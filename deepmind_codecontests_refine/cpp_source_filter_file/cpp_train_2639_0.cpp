#include <bits/stdc++.h>
const int dbg = 0;
struct XY {
  long double x, y;
  XY operator+(const XY& o) const { return XY{x + o.x, y + o.y}; }
  XY operator-(const XY& o) const { return XY{x - o.x, y - o.y}; }
  XY operator*(long double u) const { return XY{x * u, y * u}; }
  XY rot90() const { return XY{-y, x}; }
  long double norm() const { return hypot(x, y); }
  long double arg() const { return atan2(y, x); }
};
XY intersect(XY a1, XY b1, XY a2, XY b2) {
  XY a = a1 - a2;
  long double det = b2.x * b1.y - b1.x * b2.y;
  long double l2 = (b1.y * a.x - b1.x * a.y) / det;
  return a2 + b2 * l2;
}
const long double EPS = 1e-5;
long double fgcd(long double a, long double b) {
  assert(a > -EPS);
  assert(b > -EPS);
  if (dbg) printf("gcd %.10Lf %.10Lf\n", a, b);
  if (fabs(b) < EPS) return a;
  return fgcd(b, fmod(a, b));
}
int main() {
  const long double PI = acos(-1.);
  XY a;
  scanf("%Lf %Lf", &a.x, &a.y);
  XY b;
  scanf("%Lf %Lf", &b.x, &b.y);
  XY c;
  scanf("%Lf %Lf", &c.x, &c.y);
  XY ab = (a + b) * 0.5;
  XY ab_dir = (b - a).rot90();
  XY bc = (b + c) * 0.5;
  XY bc_dir = (c - b).rot90();
  XY o = intersect(ab, ab_dir, bc, bc_dir);
  if (dbg) printf("O=(%Lf,%Lf)\n", o.x, o.y);
  XY oa = a - o;
  XY ob = b - o;
  XY oc = c - o;
  long double r = oa.norm();
  if (dbg) printf("r=%Lf\n", r);
  long double a_arg = oa.arg();
  long double b_arg = ob.arg();
  long double c_arg = oc.arg();
  long double ab_arg = fabs(b_arg - a_arg);
  long double bc_arg = fabs(c_arg - b_arg);
  if (dbg) printf("ab_arg=%.10Lf bc_arg=%.10Lf\n", ab_arg, bc_arg);
  long double alpha = fgcd(ab_arg, bc_arg);
  if (dbg) printf("alpha=%.10Lf\n", alpha);
  long double beta = fgcd(alpha, 2.0 * PI);
  if (dbg) printf("beta=%.10Lf\n", beta);
  long double area = PI * r * r * sin(beta) / beta;
  printf("%.9Lf\n", area);
}
