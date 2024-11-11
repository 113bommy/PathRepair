#include <bits/stdc++.h>
using namespace std;
int n;
int x[11111], y[11111], z[11111];
int vs, vp;
int px, py, pz;
inline int sgn(double x) { return fabs(x) < 1e-11 ? 0 : (x < 0 ? -1 : 1); }
inline double calc(double x, double y, double z, double xx, double yy,
                   double zz, double v) {
  x -= xx;
  y -= yy;
  z -= zz;
  double t = sqrt(x * x + y * y + z * z);
  return t / v;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    scanf("%d%d%d", x + i, y + i, z + i);
  }
  scanf("%d%d", &vp, &vs);
  scanf("%d%d%d", &px, &py, &pz);
  cout << fixed << setprecision(8);
  double total = 0;
  for (int i = 0; i < n; i++) {
    double used = calc(x[i], y[i], z[i], x[i + 1], y[i + 1], z[i + 1], vs);
    double t = calc(px, py, pz, x[i + 1], y[i + 1], z[i + 1], vp);
    if (sgn(t - (used + total)) <= 0) {
      double lo = 0, hi = 1;
      for (int tt = 0; tt < 500; tt++) {
        double mid = (lo + hi) / 2.0;
        used = calc(x[i], y[i], z[i], x[i] + (x[i + 1] - x[i]) * mid,
                    y[i] + (y[i + 1] - y[i]) * mid,
                    z[i] + (z[i + 1] - z[i]) * mid, vs);
        t = calc(px, py, pz, x[i] + (x[i + 1] - x[i]) * mid,
                 y[i] + (y[i + 1] - y[i]) * mid, z[i] + (z[i + 1] - z[i]) * mid,
                 vp);
        if (sgn(t - (used + total)) <= 0) {
          hi = mid;
        } else {
          lo = mid;
        }
      }
      cout << "YES" << endl;
      cout << total + used << endl;
      cout << x[i] + (x[i + 1] - x[i]) * hi << " "
           << y[i] + (y[i + 1] - y[i]) * hi << " "
           << z[i] + (z[i + 1] - z[i]) * hi << endl;
      return 0;
    }
    total += used;
  }
  printf("NO\n");
  return 0;
}
