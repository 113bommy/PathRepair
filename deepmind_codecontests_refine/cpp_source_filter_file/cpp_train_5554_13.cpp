#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
static double dot(const complex<double>& a, const complex<double>& b) {
  return real(conj(a) * b);
}
static double cross(const complex<double>& a, const complex<double>& b) {
  return imag(conj(a) * b);
}
inline void chkmin(double& a, const double b) {
  if (a > b) a = b;
}
double dist(complex<double> a, complex<double> b, double r) {
  double ab = abs(a - b);
  if (ab < 1e-9) return ab;
  if (abs(cross(a, a - b) / ab) >= r) return ab;
  if (dot(-a, b - a) < 0.0 || dot(-b, a - b) < 0.0) return ab;
  double as = sqrt(dot(a, a) - r * r);
  double bs = sqrt(dot(b, b) - r * r);
  double a_ang = arg(complex<double>(r, as));
  double b_ang = arg(complex<double>(r, bs));
  double A[2] = {arg(a) + a_ang, arg(a) - a_ang};
  double B[2] = {arg(b) + b_ang, arg(b) - b_ang};
  double ans = PI * 2;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      double ang = abs(A[i] - B[j]);
      while (ang > PI * 2) ang -= PI * 2;
      if (ang > PI) ang = 2 * PI - ans;
      chkmin(ans, ang);
    }
  return as + bs + r * ans;
}
int main() {
  double xp, yp, vp, x, y, v, rp;
  while (cin >> xp >> yp >> vp >> x >> y >> v >> rp) {
    complex<double> p1 = complex<double>(xp, yp);
    complex<double> p0 = complex<double>(x, y);
    double l = 0, r = 1e9;
    double R = abs(p1);
    while (abs(r - l) > 1e-9) {
      double t = (l + r) * 0.5;
      complex<double> P = p1 * exp(complex<double>(0, t * vp / R));
      double d = dist(p0, P, rp);
      if (d <= v * t)
        r = t;
      else
        l = t;
    }
    cout.precision(9);
    cout << l << endl;
  }
}
