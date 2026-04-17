#include <iostream>
#include <vector>
#include <iomanip> //input AND output manipulators using decimal precision(allows for formatting text?)
#include <fstream>
using namespace std;
//data types for product (user-defined)
struct ChemicalInfo {
    string name, function;
    float units, quantity;
};
class Inventory {
    vector<ChemicalInfo> item;
public:
    //adds item
    void addItem(const string &name, const string &function, float units, float quantity) {
        item.push_back(ChemicalInfo{name, function, units, quantity}); //'push_back()' adds item to the vector
    }
    //removes item (entirely)
    void removeItem(const string &name) {
        for (auto it = item.begin(); it != item.end(); it++) { //for loop which runs from beginning to end of vector (containing all info)
            if (it->name == name) { //matches input to name on the list
                cout << name << " has been removed!";
                item.erase(it); //removes 'name' from vector
                return ;
            }
        }
    }
    // increase or decrease of quantity
    void quantUpdate(const string &name,float num, bool updateQ) {
        for (auto &product : item) {
            if (product.name == name) { //finds name of product
                if (updateQ) { //??
                    product.quantity += num; //adds num to original quantity
                //    cout << "Added " << "(" << num << ")" << " to " << name << "\n";
                    //worked before, not sure why it wont print anymore...
                }
                else if (product.quantity >= num) { //??
                    product.quantity -= num; //removes given num to original quant
                //    cout << "Removed " << "(" << num << ")" << " to " << name << "\n";
                }
            }
            return;
        }
    }
    //displays item list
    void displayInv() {
        if (item.empty()) {
            cout << "Empty inventory!\n";
            return; //returns nada
        } else {
            cout <<"\n-----------------------------------------------------------------\n";
            cout <<"- - - - - - - - - - - - < Stocked Items > - - - - - - - - - - - -\n";
            cout << left << setw(15) << "Name:" //sets data to the left with width of 15
            << setw(15) << "Function:"
            << setw(15) << "Units:"
            << setw(15) << "Quantity:";
            cout <<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";

            //adds items into given column
            for (const auto &s : item) {
                cout << left << setw(15) << s.name
                << setw(15) << s.function
                << setw(15) << s.units
                << setw(15) << s.quantity << "\n";
            }
        }
        }
//saving to file
    void saveFile(const string& invFile ) { //string AND invFile = file name (??)
        ofstream invF(invFile); //creating file

        if (!invF.is_open()) { //error when opening --> print message
            cerr << "Unable to open file for writing.\n"; //red error lolz (??)
            return;
        }
        else if (item.empty()) { //if empty prints message (??)
            invF << "Empty Inventory.\n";
            return;
        } else { //printing input
            invF <<"\n-----------------------------------------------------------------\n";
            invF <<"- - - - - - - - - - - - < Stocked Items > - - - - - - - - - - - -\n";
            invF << left << setw(15) << "Name:"
            << setw(15) << "Function:"
            << setw(15) << "Units:"
            << setw(15) << "Quantity:";
            invF <<"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";

            for (const auto &s : item) {
                invF << left << setw(15) << s.name
                    << setw(15) << s.function
                    << setw(15) << s.units
                    << setw(15) << s.quantity << "\n";
            }
        }
        invF.close(); //closing file
        cout << "Inventory has been saved.\n";
    }
    };
int main() {
    //adding to vector??> i dont rememver
Inventory Pro;
    Pro.addItem("ChemA", "Herbicide", 16.0, 5); //for units and quantity all for characters and nums
    Pro.addItem("ChemB", "Insecticide", 8.0, 2);

    //for menu??
    int options;
    string name, function,fileName;
    float num, units, quantity;
    bool updateQ;
    bool repeat = true;

while (repeat) {
    cout <<"----------------------------------------------------------------\n";
    cout <<"- - - - - - - - - - - - < Options Menu > - - - - - - - - - - - -\n";
    cout << "(1) Display Inventory\n";
    cout << "(2) Add New Product\n";
    cout << "(3) Remove Product\n";
    cout << "(4) Update Product Quantity\n";
    cout << "(5) Save File\n";
    cout << "\nEnter Option: ";
    cin >> options;

    //switch case for options
    switch (options) {
        case 1: //displays list
            Pro.displayInv();
            break;
        case 2: //allows user to add item (stores response)
            cout << "Name: ";
            cin >> name;
            cout << "Function: ";
            cin >> function;
            cout << "Units: ";
            cin >> units;
            cout << "Quantity: ";
            cin >> quantity;
            Pro.addItem(name,function, units, quantity);
            break;
        case 3: //removes item
            cout << "What item would you like to remove? ";
            cin >> name;
            Pro.removeItem(name);
            break;
        case 4: //adding or subtracting quantity of item //error somewhere here
            cout << "Updated Item Name: ";
            cin >> name;
            cout << "Quantity Amount: ";
            cin >> num;
            cout << "Enter '1' for adding and '2' for subtracting: "; // true or false??
            cin >> updateQ;
            Pro.quantUpdate(name, num, updateQ);
            break;
        case 5: //saving inventory to file
            cout << "File Name: ";
            cin >> fileName;
            Pro.saveFile(fileName);
            break;
        default: //mistakes lol (??)
            cout << "Invalid Option, Please try again.\n";
             break;
    }
//not sure how to add it properly
if (repeat) { //t or f (???)
    char choice;
    cout << "\nDo you want to continue? (y/n) ";
    cin >> choice;
    //if else for repeat
    if (choice == 'y' || choice == 'Y') {
        repeat = true; //repeat
    } else if (choice == 'n' || choice == 'N') {
            repeat = false; //out you go...
            cout << "\nGoodbye!";
        }
    }
}
    return 0;
}

