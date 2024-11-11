#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  double ans = 0;
  double x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double V, T;
  cin >> V >> T;
  double wx, wy;
  cin >> wx >> wy;
  double x = x1 + T * wx;
  double y = y1 + T * wy;
  if ((x - x2) * (x - x2) + (y - y2) * (y - y2) > (V * T) * (V * T)) {
    ans += T;
    cin >> wx >> wy;
    double l = 0, r = 1000000007LL;
    while (r - l > 1e-9) {
      double m = (l + r) / 2;
      double xx = x + wx * m;
      double yy = y + wy * m;
      if ((xx - x2) * (xx - x2) + (yy - y2) * (yy - y2) <
          (V * (m + ans)) * (V * (m + ans))) {
        r = m;
      } else
        l = m;
    }
    ans += l;
    printf("%.8lf\n", ans);
  } else {
    double x = x1;
    double y = y1;
    double l = 0, r = 1000000007LL;
    while (r - l > 1e-9) {
      double m = (l + r) / 2;
      double xx = x + wx * m;
      double yy = y + wy * m;
      if ((xx - x2) * (xx - x2) + (yy - y2) * (yy - y2) < (V * m) * (V * m)) {
        r = m;
      } else
        l = m;
    }
    ans += l;
    printf("%.8lf\n", ans);
  }
  return 0;
}
