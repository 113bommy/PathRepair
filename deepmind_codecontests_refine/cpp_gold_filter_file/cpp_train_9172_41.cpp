#include <bits/stdc++.h>
using namespace std;
int n;
int x[101], y[101], z[101];
double dis(double x1, double y1, double z1, double x2, double y2, double z2) {
  double ans = 1.0 * (x1 - x2) * (x1 - x2);
  ans += 1.0 * (y1 - y2) * (y1 - y2);
  ans += 1.0 * (z1 - z2) * (z1 - z2);
  ans = sqrt(ans);
  return ans;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
  double xx = 0.0, yy = 0.0, zz = 0.0;
  for (int i = 0; i < n; i++) {
    xx += 1.0 * x[i];
    yy += 1.0 * y[i];
    zz += 1.0 * z[i];
  }
  xx /= (1.0 * n);
  yy /= (1.0 * n);
  zz /= (1.0 * n);
  double d = 0.0;
  for (int i = 0; i < n; i++) {
    d = max(d, dis(xx, yy, zz, x[i], y[i], z[i]));
  }
  double lambda = 1.0;
  for (int t = 0; t < 100000; t++) {
    int id = -1;
    double dd = -1.0;
    for (int i = 0; i < n; i++) {
      double tmp = dis(xx, yy, zz, x[i], y[i], z[i]);
      if (tmp > dd) {
        dd = tmp;
        id = i;
      }
    }
    d = min(d, dd);
    xx += lambda * (x[id] - xx);
    yy += lambda * (y[id] - yy);
    zz += lambda * (z[id] - zz);
    lambda *= 0.999;
  }
  printf("%.7f %.7f %.7f", xx, yy, zz);
  return 0;
}
