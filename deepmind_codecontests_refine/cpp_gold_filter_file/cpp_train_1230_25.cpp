#include <iostream>
using namespace std ;

int main () {
  string s;cin >> s;
  int n=0;
  for (char i:s) (i=='+')? ++n:--n;
  cout << n << endl;
  return 0;
}