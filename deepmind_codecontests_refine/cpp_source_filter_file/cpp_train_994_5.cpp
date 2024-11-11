#include <bits/stdc++.h>
using namespace std;
const double pi2 = acos(-1.0) * 2;
double g(double x, double y, double a, double v) {
  double c = atan2(y, x) - a;
  for (; c >= pi2; c -= pi2)
    ;
  for (; c < 0; c += pi2)
    ;
  return min(c, pi2 - c);
}
double f(double x0, double y0, double x1, double y1, double a, double v) {
  double dx = x1 - x0, dy = y1 - y0, d = sqrt(dx * dx + dy * dy);
  double res = 1 / g(x1, y1, a, v);
  for (double t = 1e-4; t < 1; t += 2e-4)
    res = max(res, t / g(x0 + dx * t, y0 + dy * t, a, v));
  double L = 1e-4, R = 1, l, r, fl, fr;
  for (int k(0); k < 256; ++k) {
    l = (L * 2 + R) / 3;
    r = (L + R * 2) / 3;
    fl = l / g(x0 + dx * l, y0 + dy * l, a, v);
    fr = r / g(x0 + dx * r, y0 + dy * r, a, v);
    if (fl < fr) {
      res = max(res, fr);
      L = l;
    } else {
      res = max(res, fl);
      R = r;
    }
  }
  return d * res;
}
int main() {
  double Ax, Ay, Bx, By;
  int n;
  cin >> Ax >> Ay >> Bx >> By >> n;
  vector<double> v;
  for (int i(0); i < n; ++i) {
    double x, y, a, w;
    scanf("%lf%lf%lf%lf", &x, &y, &a, &w);
    v.push_back(f(Ax - x, Ay - y, Bx - x, By - y, a, w));
  }
  sort(v.rbegin(), v.rend());
  v.push_back(0);
  cin >> n;
  printf("%.12lf\n", v[n]);
  return 0;
}
