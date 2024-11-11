#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int u, d, l, r;
    cin >> l >> r >> d >> u;
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    bool ok = 1;
    if (y2 == y1 && (u > 0 || d > 0)) ok = 0;
    if (x2 == x1 && (l > 0 || r > 0)) ok = 0;
    if (x + r - l > x2 || x + r - l < x1 || y + u - d > y2 || y + u - d < y1)
      ok = 0;
    if (ok)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
