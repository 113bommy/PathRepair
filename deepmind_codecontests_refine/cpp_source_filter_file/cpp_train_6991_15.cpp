#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  if ((z == 0 && x > y) || (x > y && x > (y + z))) {
    cout << '+';
  } else if ((z == 0 && x < y) || (x < y && x < (y + z))) {
    cout << '-';
  } else if (z == 0 && x == y) {
    cout << '0';
  } else {
    cout << '?';
  }
  return 0;
}
