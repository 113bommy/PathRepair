#include <iostream>
#include <string>
using namespace std;

int main(){
  string s; cin >> s;
  if(s.find("AC") != npos){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}