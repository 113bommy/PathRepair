#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
double a, b, l;
inline int sgn(double x) {
  if (fabs(x) < 1e-12) return 0;
  return x < 0 ? -1 : 1;
}
inline double sqr(double x) { return x * x; }
inline double f(double x) {
  double y = sqrt(sqr(l) - sqr(x));
  return fabs(y * a + x * b - x * y) / l;
}
int main() {
  scanf("%lf%lf%lf", &a, &b, &l);
  if (a > b) swap(a, b);
  if (sgn(l - a) <= 0)
    printf("%.7lf\n", l);
  else if (sgn(l - b) <= 0)
    printf("%.7lf\n", a);
  else {
    double minv = 0.0, maxv = l, mid1, mid2;
    while (maxv - minv > 1e-8) {
      mid1 = minv * 2 / 3 + maxv / 3;
      mid2 = minv / 3 + maxv * 2 / 3;
      if (f(mid1) > f(mid2))
        minv = mid1;
      else
        maxv = mid2;
    }
    if (f(minv) < 1e-8)
      puts("My poor head =(");
    else
      printf("%.7lf\n", min(l, f(minv)));
  }
  return 0;
}
