#include <bits/stdc++.h>
using namespace std;
const long double pi = acos((long double)-1);
inline long double get() {
  double x;
  scanf("%lf", &x);
  return x;
}
inline long double m(long double x) {
  x -= ((long long)(x / (2 * pi))) * (2 * pi);
  while (x >= 2 * pi) x -= 2 * pi;
  while (x < 0) x += 2 * pi;
  return x;
}
long double xp, yp, vp, x, y, v, r, d, rr, th, t2, s;
long double f(long double th) {
  return sqrt(rr * rr + d * d - 2 * rr * d * cos(th));
}
inline long double g(long double th) {
  if (th <= t2 || th >= 2 * pi - t2)
    return f(th) / v;
  else {
    th = pi - t2 - fabs(th - pi);
    return s / v + th * rr / v;
  }
}
int main() {
  xp = get();
  yp = get();
  vp = get();
  x = get();
  y = get();
  v = get();
  r = get();
  d = sqrt(x * x + y * y);
  rr = sqrt(xp * xp + yp * yp);
  th = m(atan2(yp, xp) - atan2(y, x));
  t2 = acos(r / d) + acos(r / rr);
  s = sqrt(d * d - r * r) + sqrt(rr * rr - r * r);
  long double a = 0, b = 1e10;
  for (int k = 0; k < 1000; k++) {
    long double mi = (a + b) / 2;
    long double p = m(mi * vp / r + th);
    if (g(p) > mi)
      a = mi;
    else
      b = mi;
  }
  printf("%.10lf\n", (double)a);
}
