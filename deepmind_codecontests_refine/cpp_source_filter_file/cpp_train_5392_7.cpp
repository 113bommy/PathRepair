#include <iostream>
#include <string>
using namespace std;
int main (){
  int n;
  string s;
  string a;
  cin >> n >> s;
  a = s.substr(n / 2);
  if(s == a + a ){ 
    cout << ”Yes” << endl;
  } 
  else cout << ”No” << endl;
  return 0;
}