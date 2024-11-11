#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const double PI = acos(-1.0);
double vmax;
double dEqual(double a, double b) { return fabs(a - b) < EPS; }
double findTime(double vx, double vy, double lo, double hi, double dx,
                double dy) {
  for (int it = 0; it < 50; it++) {
    double mid = (lo + hi) / 2.0;
    double ux = dx - (vx * mid);
    double uy = dy - (vy * mid);
    double ti = hypot(ux, uy) / vmax;
    if (ti < mid)
      hi = mid;
    else
      lo = mid;
  }
  return lo;
}
int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double dx = x2 - x1;
  double dy = y2 - y1;
  double t;
  cin >> vmax >> t;
  double vx, vy, wx, wy;
  cin >> vx >> vy >> wx >> wy;
  double ux = dx - (vx * t);
  double uy = dy - (vy * t);
  double ti = hypot(ux, uy) / vmax;
  if (dEqual(ti, t) || ti < t) {
    double lo = findTime(vx, vy, 0.0, t, dx, dy);
    cout << fixed << setprecision(8) << lo << "\n";
  } else {
    dx -= (vx * t);
    dy -= (vy * t);
    double lo = 0.0, hi = 2.0 * PI;
    double tlo, thi;
    for (int it = 0; it < 50; it++) {
      double mlo = lo + (hi - lo) / 3.0;
      double mhi = hi - (hi - lo) / 3.0;
      double uxlo = vmax * cos(mlo);
      double uylo = vmax * sin(mlo);
      double uxhi = vmax * cos(mhi);
      double uyhi = vmax * sin(mhi);
      tlo = findTime(wx, wy, 0.0, 1e10, dx - (uxlo * t), dy - (uylo * t));
      thi = findTime(wx, wy, 0.0, 1e10, dx - (uxhi * t), dy - (uyhi * t));
      if (tlo < thi)
        hi = mhi;
      else
        lo = mlo;
    }
    cout << fixed << setprecision(8) << tlo + t << "\n";
  }
  return 0;
}
