#include <bits/stdc++.h>
double w, h, a, b, d;
double a1, a2, b1, b2;
double dt;
int main() {
  scanf("%lf%lf%lf", &w, &h, &d);
  if (d > 90.0) d = 180.0 - d;
  if (d < 1e-10) {
    printf("%.20lf\n", w * h);
    return 0;
  }
  a1 = 1.0 + cos(d * acos(-1.0) / 180.0);
  b1 = sin(d * acos(-1.0) / 180.0);
  a2 = sin(d * acos(-1.0) / 180.0);
  b2 = 1.0 + cos(d * acos(-1.0) / 180.0);
  dt = (a1 * b2 - a2 * b1);
  a = (w * b2 - h * a2) / dt;
  b = (a1 * h - b1 * w) / dt;
  if (a < 0 || b < 0) {
    a = w < h ? w : h;
    printf("%.20lf\n", a / sin(d * acos(-1.0) / 180.0) * a);
    return 0;
  }
  printf("%.20lf\n",
         w * h - 2.0 * ((cos(d * acos(-1.0) / 180.0) *
                         sin(d * acos(-1.0) / 180.0) / 2.0 * a * a) +
                        (cos(d * acos(-1.0) / 180.0) *
                         sin(d * acos(-1.0) / 180.0) / 2.0 * b * b)));
  return 0;
}
