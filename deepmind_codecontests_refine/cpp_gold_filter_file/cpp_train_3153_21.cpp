#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:65777216")
using namespace std;
const long double pi = acosl(-1.);
const long double eps = 1e-17;
int r, h;
long double getAngle(long double x, long double y, long double z) {
  long double H = h - z;
  if (H < eps) return 0;
  long double R = r * H / h;
  long double X = 0;
  long double Y = R;
  long double d = sqrtl((x - X) * (x - X) + (y - Y) * (y - Y));
  long double a = asinl(d / 2 / R) * 2;
  long double l = a * R / sqrtl(R * R + H * H);
  if (x > 0) l = -l;
  return l;
}
long double conDist(long double z, long double Z, long double a) {
  long double r1 = sqrtl(h * h + r * r + 0.) / h * (h - z);
  long double r2 = sqrtl(h * h + r * r + 0.) / h * (h - Z);
  long double x = r1;
  long double y = 0;
  long double X = cosl(a) * r2;
  long double Y = sinl(a) * r2;
  return sqrtl((x - X) * (x - X) + (y - Y) * (y - Y));
}
long double getOnConus(long double x, long double y, long double z,
                       long double X, long double Y, long double Z) {
  long double a1 = getAngle(x, y, z);
  long double a2 = getAngle(X, Y, Z);
  long double a = fabsl(a2 - a1);
  long double A = r / sqrtl(h * h + r * r + 0.) * 2 * pi;
  return min(conDist(z, Z, a), conDist(z, Z, A - a));
}
long double getOnConus(long double x, long double y, long double z,
                       long double X, long double Y) {
  if (z > eps) return getOnConus(x, y, z, X, Y, 0);
  return sqrtl((x - X) * (x - X) + (y - Y) * (y - Y));
}
long double getD(long double x, long double y, long double z, long double X,
                 long double Y, long double Z, long double XX, long double YY,
                 long double XXX, long double YYY) {
  long double res = sqrtl((XX - XXX) * (XX - XXX) + (YY - YYY) * (YY - YYY));
  res += getOnConus(x, y, z, XX, YY);
  res += getOnConus(X, Y, Z, XXX, YYY);
  return res;
}
long double getD(long double x, long double y, long double z, long double X,
                 long double Y, long double Z, long double XX, long double YY) {
  long double res = 1e100;
  for (int i(0); i < (6); i++) {
    long double a = 2 * pi / 3 * i;
    long double b = a + pi;
    for (int j(0); j < (50); j++) {
      long double s1 = (a * 2 + b) / 3;
      long double s2 = (a + 2 * b) / 3;
      long double d1 =
          getD(x, y, z, X, Y, Z, XX, YY, cosl(s1) * r, sinl(s1) * r);
      long double d2 =
          getD(x, y, z, X, Y, Z, XX, YY, cosl(s2) * r, sinl(s2) * r);
      res = min(res, min(d1, d2));
      if (d1 < d2)
        b = s2;
      else
        a = s1;
    }
  }
  return res;
}
long double go(long double x, long double y, long double z, long double X,
               long double Y, long double Z) {
  long double res = getOnConus(x, y, z, X, Y, Z);
  if (z < eps || Z < eps) res = 1e100;
  for (int i(0); i < (6); i++) {
    long double a = 2 * pi / 3 * i;
    long double b = a + pi;
    for (int j(0); j < (50); j++) {
      long double s1 = (a * 2 + b) / 3;
      long double s2 = (a + 2 * b) / 3;
      long double d1 = getD(x, y, z, X, Y, Z, cosl(s1) * r, sinl(s1) * r);
      long double d2 = getD(x, y, z, X, Y, Z, cosl(s2) * r, sinl(s2) * r);
      res = min(res, min(d1, d2));
      if (d1 < d2)
        b = s2;
      else
        a = s1;
    }
  }
  return res;
}
int main() {
  cin >> r >> h;
  long double x, y, z, X, Y, Z;
  cin >> x >> y >> z >> X >> Y >> Z;
  if (z < eps && Z < eps)
    printf("%.10lf\n", (double)sqrt((x - X) * (x - X) + (y - Y) * (y - Y)));
  else
    printf("%.10lf\n", (double)go(x, y, z, X, Y, Z));
  return 0;
}
