#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    long long int x, y, z;
    cin >> x >> y >> z;
    if (x == y && y == z && x == z) {
      cout << "YES" << endl;
      cout << x << " " << y << " " << z << endl;
    } else if (x != y && x != z && y != z) {
      cout << "NO" << endl;
    } else if ((x > y && x > z) || (y > x && y > z) || (z > x && z > y)) {
      cout << "NO" << endl;
    } else {
      if (x < y && x < z) {
        b = x;
        c = x;
        a = y;
      } else if (y < x && y < z) {
        b = y;
        c = y;
        a = z;
      } else {
        b = z;
        c = z;
        a = z;
      }
      cout << "YES" << endl;
      cout << a << " " << b << " " << c << endl;
    }
  }
}
