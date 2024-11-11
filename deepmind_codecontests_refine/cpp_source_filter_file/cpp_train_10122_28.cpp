#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      if (a % 2 == b % 2)
        cout << "1" << endl;
      else
        cout << "2" << endl;
    } else if (a < b) {
      if (a % 2 == b % 2)
        cout << b - a << endl;
      else
        cout << "1" << endl;
    } else
      cout << "0" << endl;
  }
  return 0;
}
