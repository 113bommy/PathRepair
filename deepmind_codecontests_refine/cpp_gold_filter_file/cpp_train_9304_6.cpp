#include <bits/stdc++.h>
using namespace std;
const double Pi = 4.0 * atan(1.0);
const double t = 180.0 / Pi;
int main() {
  double w, h, a;
  scanf("%lf%lf%lf", &w, &h, &a);
  if (w < h) swap(w, h);
  if (a > 90) a = 180 - a;
  if (a == 90)
    printf("%.9lf\n", h * h);
  else if (a == 0)
    printf("%.9lf\n", w * h);
  else {
    double p = atan2(2.0 * w * h, w * w - h * h) * t;
    if (p == a)
      printf("%.9lf\n", h * (w / 2 - h * h));
    else if (p < a) {
      a = a / t;
      double si = sin(a);
      double ta = tan(a);
      double co = cos(a);
      double x = (w + h / ta - h * sqrt(1 + 1 / (ta * ta))) / 2;
      double y = x - h / ta;
      printf("%.9lf\n", h * (w - x - y));
    } else {
      a = a / t;
      double si = sin(a);
      double ta = tan(a);
      double co = cos(a);
      double x = (w - h * ta / (1.0 + 1.0 / co)) /
                 ((1.0 + 1.0 / co) - ta * ta / (1 + 1 / co));
      double y = (h - x * ta) / (1 + 1 / co);
      double s1 = x * x * ta;
      double s2 = y * y * ta;
      printf("%.9lf\n", w * h - s1 - s2);
    }
  }
}
