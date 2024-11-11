#include <bits/stdc++.h>
const int N = 200001;
using namespace std;
int main() {
  cout << fixed << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double x1, y1, x2, y2, vmax, t, vx, vy, wx, wy;
  cin >> x1 >> y1 >> x2 >> y2 >> vmax >> t >> vx >> vy >> wx >> wy;
  double l = 0, r = INT_MAX, mid, ans;
  while (l <= r) {
    mid = (l + r) / 2;
    double t1 = min(mid, t);
    double t2 = max(0.0, mid - t1);
    double fx = x1 + vx * t1 + wx * t2;
    double fy = y1 + vy * t1 + wy * t2;
    double rem = sqrt((x2 - fx) * (x2 - fx) + (y2 - fy) * (y2 - fy));
    if (rem / vmax <= mid) {
      ans = mid;
      r = mid - 0.00000001;
    } else {
      l = mid + 0.00000001;
    }
  }
  cout << ans;
}
