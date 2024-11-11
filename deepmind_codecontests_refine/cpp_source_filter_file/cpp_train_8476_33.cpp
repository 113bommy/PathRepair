#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
struct point3 {
  double x, y, z;
  point3(double a, double b, double c) {
    x = a;
    y = b;
    z = c;
  }
  point3() {}
};
struct plane3 {
  point3 a, b, c;
  plane3(point3 x, point3 y, point3 z) {
    a = x;
    b = y;
    c = z;
  }
  plane3() {}
};
double dmult(point3 u, point3 v) { return u.x * v.x + u.y * v.y + u.z * v.z; }
point3 xmult(point3 u, point3 v) {
  point3 ret;
  ret.x = u.y * v.z - v.y * u.z;
  ret.y = u.z * v.x - u.x * v.z;
  ret.z = u.x * v.y - u.y * v.x;
  return ret;
}
point3 subt(point3 u, point3 v) {
  point3 ret;
  ret.x = u.x - v.x;
  ret.y = u.y - v.y;
  ret.z = u.z - v.z;
  return ret;
}
point3 pvec(plane3 s) { return xmult(subt(s.a, s.b), subt(s.b, s.c)); }
double vlen(point3 p) { return sqrt(p.x * p.x + p.y * p.y + p.z * p.z); }
double ptoplane(point3 p, plane3 s) {
  return fabs(dmult(pvec(s), subt(p, s.a))) / vlen(pvec(s));
}
double check(double a, double h) {
  point3 A = point3(0, 0, 0);
  point3 B = point3(0, a, 0);
  point3 C = point3(a / (2.), a / (2.), h);
  plane3 p = plane3(A, B, C);
  point3 O = point3(a / (2.), a / (2.), 0);
  double r = ptoplane(O, p);
  double res = 1. / 3 * a * a * h - 4. / 3 * pi * r * r * r;
  return r;
}
int main() {
  double x;
  cin >> x;
  int a, b;
  double ans = 1e9;
  for (int j = 1; j <= 10; ++j)
    for (int i = 1; i <= 10; ++i) {
      if (fabs(check(i, j) - x) < 1e-8) {
        cout << i << ' ' << j << endl;
        return 0;
      }
    }
  cout << a << ' ' << b << endl;
}
