#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, i, j, k, t1, t2, t0, x1, x2, y1, y2, y1max = 0, y2max = 0;
  double tmin = 1e300, t;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  if (t1 == t0 && t2 == t0) {
    cout << x1 << " " << x2;
  } else if (t1 == t0) {
    cout << x1 << " 0";
  } else if (t2 == t0) {
    cout << "0 " << x2;
  } else {
    for (i = 0; i <= x1; i++) {
      if (i == 0) {
        y2 = x2;
      } else {
        y2 = (t0 * i - t1 * i) / (t2 - t0);
        if ((t0 * i - t1 * i) % (t2 - t0) > 0) y2 += 1;
      }
      if (y2 > x2) continue;
      t = double(t1 * i + t2 * y2) / (i + y2);
      if (t < tmin && t >= t0) {
        tmin = t;
        y1max = i;
        y2max = y2;
      } else if (fabs(t - tmin) < (1e-6) && (i + y2) > (y1max + y2max)) {
        tmin = t;
        y1max = i;
        y2max = y2;
      }
    }
    cout << y1max << " " << y2max;
  }
  return 0;
}
