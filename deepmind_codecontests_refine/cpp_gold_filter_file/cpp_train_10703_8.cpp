#include <iostream>
using namespace std;

int main(){
  string s;
  int a = 0;
  cin >> s;
  for(auto i : s)
    if(i == '2')
      ++a;
  cout << a << "\n";
}