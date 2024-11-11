#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x, y, z, r, r1, ans, a, b, x1, y1;
  cin >> t;
  while (t--) {
    cin >> x >> y >> z;
    x1 = x;
    y1 = y;
    if (z == 0 && x > y)
      cout << "1\n";
    else if (x > y + z)
      cout << z + 1 << "\n";
    else if (y + z >= x && x + z > y) {
      if (x < y) {
        x1 = x + y - x;
        b = abs(y - x - z);
        r = b / 2;
        r1 = (b / 2) + (b % 2);
      } else {
        y1 = y + x - y;
        b = abs(x - y - z);
        r = b / 2;
        r1 = (b / 2) + (b % 2);
      }
      cout << abs(y - y1) + r1 << "\n";
    } else
      cout << "0\n";
  }
}
