#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, b1, c1, a2, b2, c2;
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  float x, y, z;
  x = a1 / float(a2);
  z = c1 / float(c2);
  y = b1 / float(b2);
  if ((a1 == 0 && b1 == 0 && c1 == 0) || (a2 == 0 && b2 == 0 && c2 == 0)) {
    if ((a1 == 0 && b1 == 0) || (a2 == 0 && b2 == 0)) {
      if (c1 != 0 || c2 != 0)
        cout << "0";
      else
        cout << "-1";
    } else
      cout << "-1";
  } else if ((a1 == 0 && b1 == 0) || (a2 == 0 && b2 == 0)) {
    cout << "0";
  } else if (a1 == 0 && a2 == 0) {
    if (y == z || (c1 == 0 && c2 == 0))
      cout << "-1";
    else
      cout << "0";
  } else if (b1 == 0 && b2 == 0) {
    if (x == z || (c1 == 0 && c2 == 0))
      cout << "-1";
    else
      cout << "0";
  } else if (x == y) {
    if ((c1 == 0 && c2 == 0) || y == z)
      cout << "-1";
    else
      cout << "0";
  } else if (x != y) {
    cout << "1";
  }
}
