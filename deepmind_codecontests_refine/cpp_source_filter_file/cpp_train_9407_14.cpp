#include <bits/stdc++.h>
const double PI = acos(-1.0);
using namespace std;
double y_1, y2, yw, xb, yb, r;
double calc(double x) {
  double alpha = asin(
      (xb - x) / (sqrt((xb - x) * (xb - x) + (yw - r - yb) * (yw - r - yb))));
  return yw - x / tan(alpha) - r;
}
int main() {
  scanf("%lf %lf %lf %lf %lf %lf", &y_1, &y2, &yw, &xb, &yb, &r);
  double oy2 = y2;
  y_1 += r;
  y2 -= r;
  if (y_1 > y2) {
    printf("-1\n");
    return 0;
  }
  double a = r, b = xb;
  while (fabs(b - a) >= 10e-9) {
    double m = (a + b) / 2;
    double yf = calc(m);
    double alpha = asin(
        (xb - m) / (sqrt((xb - m) * (xb - m) + (yw - r - yb) * (yw - r - yb))));
    if (yf < y_1)
      b = m;
    else if (yf > y2)
      a = m;
    else if (sin(PI / 2 - alpha) * ((oy2 - yf) / tan(PI / 2 - alpha)) < r)
      a = m;
    else
      a = b = m;
  }
  double yf = calc(a);
  double alpha = asin(
      (xb - a) / (sqrt((xb - a) * (xb - a) + (yw - r - yb) * (yw - r - yb))));
  if (yf >= y_1 && yf <= y2 &&
      sin(PI / 2 - alpha) * ((oy2 - yf) / tan(PI / 2 - alpha)) >= r)
    printf("%0.10lf\n", a);
  else
    printf("-1\n");
  return 0;
}
