#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-10;
double a, v, L, d, w, curv;
double res(0);
double calc(double curv, double ri, double s) {
  double le = 0, md;
  while (le < ri - eps) {
    md = (le + ri) / 2.;
    if (curv * md + 0.5 * a * md * md > s)
      ri = md;
    else
      le = md;
  }
  return le;
}
double calc2(double s) {
  double le = 0, md, ri = 1000000;
  while (le < ri - eps) {
    md = (le + ri) / 2.;
    double t = w * md + 0.25 * a * md * md;
    if (w + 0.5 * a * md > v)
      t = w * md + 0.5 * (v - w) * (t + t - 2 * (v - w) / a);
    if (t > s)
      ri = md;
    else
      le = md;
  }
  return le;
}
int main() {
  cin >> a >> v >> L >> d >> w;
  if (w > v) w = v;
  double ti = w / a;
  if (a * ti * ti * 0.5 < d) {
    res = ti + calc2(d - a * ti * ti * 0.5);
    curv = w;
  } else {
    res = sqrt(2 * d / a);
    curv = res * a;
  }
  ti = (v - curv) / a;
  if (curv * ti + a * ti * ti * 0.5 <= L - d) {
    res += ti + (L - d - (curv * ti + a * ti * ti * 0.5)) / v;
  } else {
    res += calc(curv, ti, L - d);
  }
  printf("%.10f\n", res);
  return 0;
}
