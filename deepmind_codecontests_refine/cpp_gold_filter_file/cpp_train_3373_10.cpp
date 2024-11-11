#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8, PI = acos(-1.0);
double dot(complex<double> a, complex<double> b) { return real(conj(a) * b); }
double cross(complex<double> a, complex<double> b) { return imag(conj(a) * b); }
int ccw(complex<double> a, complex<double> b, complex<double> c) {
  b -= a;
  c -= a;
  if (cross(b, c) > +EPS) return +1;
  if (cross(b, c) < -EPS) return -1;
  if (dot(b, c) < 0) return +2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}
complex<double> projection(complex<double> lp0, complex<double> lp1,
                           complex<double> p) {
  double t = dot(p - lp0, lp0 - lp1) / norm(lp0 - lp1);
  return lp0 + t * (lp0 - lp1);
}
complex<double> mirror(complex<double> lp0, complex<double> lp1,
                       complex<double> p) {
  return 2.0 * projection(lp0, lp1, p) - p;
}
int is_intersect_ss(complex<double> s0, complex<double> s1, complex<double> t0,
                    complex<double> t1) {
  int c00 = ccw(s0, s1, t0), c01 = ccw(s0, s1, t1), c10 = ccw(t0, t1, s0),
      c11 = ccw(t0, t1, s1);
  if (c00 * c01 == -1 && c10 * c11 == -1) return 2;
  if (c00 * c01 == 1 || c10 * c11 == 1) return -1;
  bool para = (abs((cross(s1 - s0, t1 - t0)) - (0.0)) < EPS);
  int edge = abs(c00 * c01 * c10 * c11);
  if (para) {
    if (edge == 16)
      return -1;
    else
      return 0;
  }
  return 1;
}
complex<double> intersection_ll(complex<double> s0, complex<double> s1,
                                complex<double> t0, complex<double> t1) {
  complex<double> sv = s1 - s0, tv = t1 - t0;
  assert(!(abs((cross(sv, tv)) - (0.0)) < EPS));
  return s0 + sv * cross(tv, t0 - s0) / cross(tv, sv);
}
complex<double> getp() {
  double x, y;
  if (cin >> x >> y)
    return complex<double>(x, y);
  else
    return complex<double>(1e18, 1e18);
}
int main() {
  complex<double> ps, pt;
  while (ps = getp(), ps != complex<double>(1e18, 1e18)) {
    pt = getp();
    complex<double> pw1 = getp(), pw2 = getp(), pr1 = getp(), pr2 = getp();
    bool res = false;
    {
      bool wiss = is_intersect_ss(ps, pt, pw1, pw2) <= -1;
      bool riss = is_intersect_ss(ps, pt, pr1, pr2) <= 0;
      if (wiss && riss) res = true;
    }
    {
      complex<double> pu = mirror(pr1, pr2, pt);
      if (is_intersect_ss(ps, pu, pr1, pr2) >= 1) {
        complex<double> pc = intersection_ll(ps, pu, pr1, pr2);
        bool siss = is_intersect_ss(ps, pc, pw1, pw2) <= -1;
        bool tiss = is_intersect_ss(pc, pt, pw1, pw2) <= -1;
        if (siss && tiss) res = true;
      }
    }
    puts(res ? "YES" : "NO");
  }
}
