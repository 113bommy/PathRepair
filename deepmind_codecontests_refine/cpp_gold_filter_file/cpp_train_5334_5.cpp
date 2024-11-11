#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  long long a, b, c, d, x, y, xx1, yy1, xx2, yy2;
  while (t--) {
    cin >> a >> b >> c >> d >> x >> y >> xx1 >> yy1 >> xx2 >> yy2;
    if (x == xx1 && x == xx2) {
      if (a != 0 || b != 0) {
        cout << "NO\n";
        continue;
      }
    } else if (x == xx1) {
      if (b - a > xx2 - x || b - a < 0) {
        cout << "NO\n";
        continue;
      }
    } else if (x == xx2) {
      if (a - b > x - xx1 || a - b < 0) {
        cout << "NO\n";
        continue;
      }
    } else {
      if (a > b && a - b > x - xx1) {
        cout << "NO\n";
        continue;
      } else if (a < b && b - a > xx2 - x) {
        cout << "NO\n";
        continue;
      }
    }
    if (y == yy1 && y == yy2) {
      if (c != 0 || d != 0) {
        cout << "NO\n";
        continue;
      }
    } else if (y == yy2) {
      if (c - d > y - yy1 || c - d < 0) {
        cout << "NO\n";
        continue;
      }
    } else if (y == yy1) {
      if (d - c > yy2 - y || d - c < 0) {
        cout << "NO\n";
        continue;
      }
    } else {
      if (c > d && c - d > y - yy1) {
        cout << "NO\n";
        continue;
      } else if (d > c && d - c > yy2 - y) {
        cout << "NO\n";
        continue;
      }
    }
    cout << "YES\n";
  }
  return 0;
}
