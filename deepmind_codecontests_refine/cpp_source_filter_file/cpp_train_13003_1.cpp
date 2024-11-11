#include <iostream>

using namespace std;

int main(){
    string a;
    while (getline(cin,a)&&a!="END OF INPUT"){
        int num=0;
        for(int i=0;i<a.length();++i){
            if(a[i]==" ") {
                cout << num;
                num=0;
            }else num++;
        }
        cout << endl;
    }
}
