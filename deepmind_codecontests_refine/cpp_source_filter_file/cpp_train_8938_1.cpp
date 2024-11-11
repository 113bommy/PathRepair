#include <iostream>
#include <string>
using namespace std;

int main(){
    string mas;
    bool judge;
    while(cin >> mas){
        judge = false;
        for(int i=0;i<9;i+=3){
            if(mas.substr(i,3) == "ooo"){
                cout << "o" << endl;
                judge = true;
                break;
            }
            if(mas.substr(i,3) == "xxx"){
                cout << "x" << endl;
                judge = true;
                break;
            }
        }
        for(int i=0;i<3;i++){
            if(mas[i] == mas[i+3] && mas[i+3] == mas[i+6] && !judge && mas[i] != 's'){
                cout << mas[i] << endl;
                judge = true;
                break;
            }
        }
        if(mas[0] == mas[4] && mas[4] == mas[8] && !judge && mas[i] != 's') {
            cout << mas[0] << endl;
            judge = true;
        }
        else if(mas[2] == mas[4] && mas[4] == mas[6] && !judge && mas[i] != 's'){
            cout << mas[2] << endl;
            judge = true;
        }
        else if(!judge) cout << "d" << endl;
    }
}