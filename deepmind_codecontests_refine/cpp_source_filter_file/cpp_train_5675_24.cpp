#include <bits/stdc++.h>
using namespace std;
int main() {
  double x1(0), y1(0), x2(0), y2(0), v(0), t(0), vx(0), vy(0), wx(0), wy(0);
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> v >> t;
  cin >> vx >> vy;
  cin >> wx >> wy;
  cout.precision(10);
  cout << fixed;
  double lo(0), hi(1e9), mid(0);
  for (int i = 0; i < 1000; ++i) {
    mid = lo + (hi - lo) / 2;
    double x = x1 + min(mid, t) * vx + max(mid - t, 0.) * wx;
    double y = x1 + min(mid, t) * vy + max(mid - t, 0.) * wy;
    if (hypot(x - x2, y - y2) <= v * mid) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << mid << endl;
  return 0;
}
