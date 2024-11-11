#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cout << setprecision(10);
  cout << fixed;
  double x1, x2, y1, y2, v, t, vx, vy, wx, wy, l = 0, r = 1e7;
  cin >> x1 >> y1 >> x2 >> y2 >> v >> t >> vx >> vy >> wx >> wy;
  while (l + 1e-7 < r) {
    double mid = 0.5 * (l + r);
    double x = x1 + min(mid, t) * vx + max(mid - t, 0.0) * wx;
    double y = y1 + min(mid, t) * vy + max(mid - t, 0.0) * wy;
    (hypot(x - x2, y - y2) < v * mid ? r : l) = mid;
  }
  cout << r << endl;
  return 0;
}
