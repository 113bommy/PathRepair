#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const double lim = 1e8;
double ox, oy, ax, ay, v, t, vx, vy, _vx, _vy;
int main() {
  scanf("%lf%lf%lf%lf", &ox, &oy, &ax, &ay);
  scanf("%lf%lf", &v, &t);
  scanf("%lf%lf%lf%lf", &vx, &vy, &_vx, &_vy);
  double l = 0, r = lim;
  while (l + eps <= r) {
    double m = (l + r) / 2;
    if (m <= t)
      if (sqrt((ax - m * vx - ox) * (ax - m * vx - ox) +
               (ay - m * vy - oy) * (ay - m * vy - oy)) <= v * m)
        r = m;
      else
        l = m;
    else if (sqrt((ax - t * vx - (m - t) * _vx - ox) *
                      (ax - t * vx - (m - t) * _vx - ox) +
                  (ay - t * vy - (m - t) * _vy - oy) *
                      (ay - t * vy - (m - t) * _vy - oy)) <= v * m)
      r = m;
    else
      l = m;
  }
  printf("%lf", r);
  return 0;
}
