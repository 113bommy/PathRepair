#include <bits/stdc++.h>
const int INF = 1e5;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, a, b, c, d, n, x, y;
  cin >> t;
  while (t--) {
    int x1, x2, y1, y2;
    x1 = y1 = -INF;
    x2 = y2 = INF;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> a >> b >> c >> d;
      if (a == 0) x1 = max(x, x1);
      if (b == 0) y2 = min(y, y2);
      if (c == 0) x2 = min(x, x2);
      if (d == 0) y1 = max(y, y1);
    }
    if (x1 <= x2 && y1 <= y2) {
      cout << 1 << " " << x1 << " " << y1 << "\n";
    } else
      cout << "0\n";
  }
  return 0;
}
