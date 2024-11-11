#include <iostream>
using namespace std;

int main(){
  string a[4]={"A","C","G","T"};
  string s;
  cin >> s;
  for(int i=0;i<4;i++){
    if(s==a[i]){
      cout << a[3-i] << endl;
    }
  }
}