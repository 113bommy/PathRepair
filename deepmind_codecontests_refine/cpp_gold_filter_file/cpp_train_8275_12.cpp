#include <bits/stdc++.h>
using namespace std;
double a, v, l, d, w, t1, t2, ans;
inline double F(double x) { return x * x; }
inline double f(double v0, double v, double a, double l) {
  double s = (v + v0) * (v - v0) / 2 / a;
  if (s >= l)
    return (-v0 + sqrt(F(v0) + 2 * a * l)) / a;
  else
    return (v - v0) / a + (l - s) / v;
}
signed main() {
  scanf("%lf%lf%lf%lf%lf", &a, &v, &l, &d, &w);
  double stp = F(w) / 2 / a;
  if (w >= v || stp >= d)
    ans = f(0, v, a, l);
  else {
    t2 = f(w, v, a, l - d);
    double tjs = sqrt((2 * a * d + F(w)) / 2 / a / a);
    if (tjs * a <= v)
      t1 = 2 * tjs - w / a;
    else {
      double sf = F(v) / 2 / a;
      double sl = (v + w) * (v - w) / 2 / a;
      t1 = v / a + (v - w) / a + (d - sf - sl) / v;
    }
    ans = t1 + t2;
  }
  printf("%.12f", ans);
}
