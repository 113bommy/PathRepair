#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, a, b, c, d, x, y, x1, y1, x2, y2;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
    if ((x - a + b >= x1 && x - a + b <= x2) &&
        (y - c + d >= y1 && y - c + d <= y2)) {
      if ((x1 == x2) && (a != 0 || b != 0) ||
          (y1 == y2) && (c != 0 || d != 0)) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
