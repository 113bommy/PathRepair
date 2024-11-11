#include <bits/stdc++.h>
using namespace std;
const long double pi = acos((long double)-1);
inline long double get() {
  double x;
  scanf("%lf", &x);
  return x;
}
inline long double m(long double x) {
  x -= (int)(x / (2 * pi)) * (2 * pi);
  while (x >= 2 * pi) x -= 2 * pi;
  while (x < 0) x += 2 * pi;
  return x;
}
long double xp, yp, vp, x, y, v, r, d, rr, th, t2, s;
long double f(long double th) {
  return sqrt(rr * rr + d * d - 2 * rr * d * cos(th));
}
long double bs(long double a, long double b) {
  if (b < th)
    return 1e100;
  else if (a < th)
    a = th;
  if (f(a) / v <= (a - th) * rr / vp)
    return (a - th) * rr / vp;
  else if (f(b) / v > (b - th) * rr / vp)
    return 1e100;
  else {
    for (int k = 0; k < 100; k++) {
      long double z = (a + b) / 2;
      if (f(z) / v <= (z - th) * rr / vp)
        b = z;
      else
        a = z;
    }
    return m(a - th) * rr / vp;
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
  long double ans = 1e100;
  long double d1 = vp * (s / v) / rr + th - t2;
  d1 = m(d1);
  long double dd1 = d1 / (1 - r * vp / v / rr);
  long double tt1 = dd1 * r / v + s / v;
  ans = min(ans, tt1);
  long double d2 = (2 * pi - t2) - (vp * (s / v) / rr + th);
  d2 = m(d2);
  long double dd2 = d2 / (1 + r * vp / v / rr);
  long double tt2 = dd2 * r / v + s / v;
  ans = min(ans, tt2);
  for (int rot = 0; rot <= 30000; rot++) {
    ans = min(ans, bs(2 * pi - t2 + 2 * pi * rot, 2 * pi + 2 * pi * rot));
    ans = min(ans, bs(2 * pi * rot, t2 + 2 * pi * rot));
  }
  printf("%.10lf\n", (double)ans);
}
