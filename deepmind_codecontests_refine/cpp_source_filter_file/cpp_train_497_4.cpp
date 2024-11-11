#include <iostream>
using namespace std;
int main() {
  int r = 0, b = 0, n;
  char x;
  cin >> n;
  while(n--) {
    cin >> x;
    if(x == 'R') ++r;
    else ++b;
  }
  if(r>b) cout << "Yes";
  else cout << "No";