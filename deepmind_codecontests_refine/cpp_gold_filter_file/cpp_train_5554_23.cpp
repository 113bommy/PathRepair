#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
const double eps = 1e-9;
inline int cmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator+(point q) { return point(x + q.x, y + q.y); }
  point operator-(point q) { return point(x - q.x, y - q.y); }
  point operator*(double t) { return point(x * t, y * t); }
  point operator/(double t) { return point(x / t, y / t); }
  double operator*(point q) { return x * q.x + y * q.y; }
  double operator%(point q) { return x * q.y - y * q.x; }
  double polar() { return ((y > -eps) ? atan2(y, x) : 2 * Pi + atan2(y, x)); }
  double mod() { return sqrt(x * x + y * y); }
  double mod2() { return (x * x + y * y); }
  point rotate(double t) {
    return point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t));
  }
  int cmp(point q) const {
    if (int t = ::cmp(x, q.x)) return t;
    return ::cmp(y, q.y);
  }
  bool operator==(point q) const { return cmp(q) == 0; }
  bool operator!=(point q) const { return cmp(q) != 0; }
  bool operator<(point q) const { return cmp(q) < 0; }
  static point pivot;
};
point point::pivot;
double seg_distance(point p, point q, point r) {
  point A = r - q, B = r - p, C = q - p;
  double a = A * A, b = B * B, c = C * C;
  if (cmp(b, a + c) >= 0)
    return sqrt(a);
  else if (cmp(a, b + c) >= 0)
    return sqrt(b);
  else
    return fabs(A % B) / sqrt(c);
}
inline double angle(point p, point q, point r) {
  point u = p - q, v = r - q;
  return atan2(u % v, u * v);
}
point pla, p;
double vp, v, r, R, pmod;
double solve(double tmp) {
  double alfa = tmp * vp / R;
  point pos = pla.rotate(alfa);
  double dist;
  if (cmp(seg_distance(p, pos, point(0, 0)), r) > 0)
    dist = (p - pos).mod();
  else {
    double angp = acos(r / pmod);
    double angpos = acos(r / R);
    dist = sqrt(pmod * pmod - r * r) + sqrt(R * R - r * r);
    double ang = fabs(angle(p, point(0, 0), pos));
    ang = ang - angp - angpos;
    dist += ang * r;
  }
  return fabs(tmp - dist / v);
}
double busca(double ini, double fim) {
  double m1, m2;
  for (int i = 0; i < 100; i++) {
    m1 = ini + (fim - ini) / 3;
    m2 = fim - (fim - ini) / 3;
    if (cmp(solve(m1), solve(m2)) > 0)
      ini = m1;
    else
      fim = m2;
  }
  return ini;
}
int main() {
  cin >> pla.x >> pla.y >> vp;
  cin >> p.x >> p.y >> v >> r;
  R = pla.mod();
  pmod = p.mod();
  double tempo = 2 * Pi * R / vp;
  double ans1 = busca(0, tempo / 2), ans2 = busca(tempo / 2, tempo);
  int val = (int)((fabs(pmod - R) + 2 * Pi * R) / v);
  tempo *= 0.5;
  double ans = busca(0, tempo);
  for (int i = 1; i < val + 10; i++) {
    double aux = busca(tempo * i, tempo * (i + 1));
    if (cmp(solve(ans), solve(aux)) > 0) ans = aux;
  }
  printf("%.9lf\n", ans);
  return 0;
}
