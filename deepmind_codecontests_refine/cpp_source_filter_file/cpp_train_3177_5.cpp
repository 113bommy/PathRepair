#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-10;
const long long LINF = 1e18;
int main() {
  if ("" != "") {
    freopen(
        ""
        ".in",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  iostream::sync_with_stdio(0);
  long long a, b, c;
  cin >> a >> b >> c;
  long long x, y, z;
  cin >> x >> y >> z;
  long long canadd = 0;
  if (a > x) canadd += (a - x) / 2;
  if (b > y) canadd += (b - y) / 2;
  if (c > y) canadd += (c - y) / 2;
  bool ok = 1;
  if (a < x) {
    long long toadd = x - a;
    if (toadd > canadd) {
      cout << "No" << endl;
      return 0;
    }
    canadd -= toadd;
  }
  if (b < y) {
    long long toadd = y - b;
    if (toadd > canadd) {
      cout << "No" << endl;
      return 0;
    }
    canadd -= toadd;
  }
  if (c < z) {
    long long toadd = z - c;
    if (toadd > canadd) {
      cout << "No" << endl;
      return 0;
    }
    canadd -= toadd;
  }
  cout << "Yes" << endl;
  return 0;
}
