#include <bits/stdc++.h>
using namespace std;
int n;
double x[111], y[111], z[111];
double a, b, c;
double Cal(double xx, double yy, double zz) {
  double res = -1.0;
  for (int i = (1), _b = (n); i <= _b; ++i)
    res = max(res, (x[i] - xx) * (x[i] - xx) + (y[i] - yy) * (y[i] - yy) +
                       (z[i] - zz) * (z[i] - zz));
  return res;
}
double CalC(double xx, double yy) {
  double x = -10000, y = 10000, pre, las;
  for (int q = 0, _b = (50); q < _b; ++q) {
    c = (x + y) / 2.0;
    pre = Cal(xx, yy, c - 0.00001);
    las = Cal(xx, yy, c + 0.00001);
    if (pre > las) {
      x = c;
    } else if (pre < las)
      y = c;
  }
  return Cal(xx, yy, c);
}
double CalB(double xx) {
  double x = -10000, y = 10000, pre, las;
  for (int q = 0, _b = (50); q < _b; ++q) {
    b = (x + y) / 2.0;
    pre = CalC(xx, b - 0.000001);
    las = CalC(xx, b + 0.000001);
    if (pre > las) {
      x = b;
    } else if (pre < las)
      y = b;
  }
  return CalC(xx, b);
}
void CalA() {
  double x = -10000, y = 10000, pre, las;
  for (int q = 0, _b = (50); q < _b; ++q) {
    a = (x + y) / 2.0;
    pre = CalB(a - 0.0000001);
    las = CalB(a + 0.0000001);
    if (pre > las) {
      x = a;
    } else if (pre < las)
      y = a;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = (1), _b = (n); i <= _b; ++i)
    scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
  CalA();
  printf("%.7lf %.7lf %.7lf", a, b, c);
  return 0;
}
