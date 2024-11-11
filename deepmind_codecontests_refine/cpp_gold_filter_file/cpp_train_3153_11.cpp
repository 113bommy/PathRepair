#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(const T a) {
  return a > 0 ? a : -a;
}
const double PI = 2.0 * acos(1.0);
const long double eps = 1e-12;
long double alpha;
int n;
int m;
long double dist(long double ra, long double rb, long double angle) {
  if (abs(ra) < eps) {
    return rb * alpha;
  }
  if (abs(rb) < eps) {
    return ra * alpha;
  }
  if (fabs(angle) < eps) return abs(rb - ra) * alpha;
  long double co = rb * sin(angle / alpha);
  long double si = (ra - rb * cos(angle / alpha));
  long double q = (sqrt(abs(((co) * (co)) + ((si) * (si)))));
  co /= q;
  si /= q;
  long double tmp = tan(angle / alpha), tg = si / co;
  return abs(alpha * ra * (co * (tmp - tg) / (1.0 + tmp * tg) + si));
}
int main() {
  long double r, h;
  cin >> r >> h;
  long double xa, ya, za, xb, yb, zb;
  cin >> xa >> ya >> za;
  cin >> xb >> yb >> zb;
  if (abs(zb) < eps && abs(za) < eps) {
    printf(
        "%.10lf\n",
        (double)(sqrt(abs(((xb - xa) * (xb - xa)) + ((yb - ya) * (yb - ya))))));
    return 0;
  }
  if (abs(zb) < eps) {
    swap(xa, xb);
    swap(ya, yb);
    swap(za, zb);
  }
  alpha = (sqrt(abs(1.0 + ((h / r) * (h / r)))));
  if (abs(za) > eps && abs(zb) > eps) {
    long double ra = (sqrt(abs(((xa) * (xa)) + ((ya) * (ya)))));
    long double rb = (sqrt(abs(((xb) * (xb)) + ((yb) * (yb)))));
    long double angle = -1.0;
    if (abs(ra) > eps && abs(rb) > eps)
      angle = acos((xa * xb + ya * yb) / ra / rb);
    long double ans = dist(ra, rb, angle);
    long double fans1 = -1, fans2 = -1;
    for (int i = 0; i < (1); i++) {
      long double L1 = -M_PI / 20, R1 = M_PI / 20.0;
      long double L2 = -M_PI / 20, R2 = M_PI / 20.0;
      n = 1780;
      for (int j = 0; j < (n); j++) {
        long double f1 = L1 + (R1 - L1) * j / (long double)n;
        for (int k = 0; k < (n); k++) {
          long double f2 = L2 + (R2 - L2) * k / (long double)n;
          long double tmp = r * (sqrt(abs(2.0 - 2.0 * cos(angle + f1 - f2)))) +
                            dist(r, ra, f1) + dist(r, rb, f2);
          if (tmp < ans) {
            ans = tmp;
            fans1 = f1;
            fans2 = f2;
          }
        }
      }
      long double d = R1 - L1;
      L1 = fans1 - d / 2.0 * 0.99;
      L2 = fans2 - d / 2.0 * 0.99;
      R1 = fans1 + d / 2.0 * 0.99;
      R2 = fans2 + d / 2.0 * 0.99;
    }
    printf("%.10lf\n", (double)ans);
    return 0;
  } else {
    long double L = 0.0, R = 2.0 * M_PI;
    long double ans = 1e20;
    long double fans = -1;
    long double rb = (sqrt(abs(((xb) * (xb)) + ((yb) * (yb)))));
    for (int i = 0; i < (200); i++) {
      for (int j = 0; j < (1000); j++) {
        double f = L + (R - L) / 100.0 * j;
        long double x = r * cos(f);
        long double y = r * sin(f);
        long double angle = -1.0;
        if (abs(rb) > eps) angle = acos((x * xb + y * yb) / rb / r);
        long double tmp =
            (sqrt(abs(((xa - x) * (xa - x)) + ((ya - y) * (ya - y))))) +
            dist(r, rb, angle);
        if (tmp < ans) {
          ans = tmp;
          fans = f;
        }
      }
      long double d = R - L;
      L = fans - d / 2.0 * 0.9;
      R = fans + d / 2.0 * 0.9;
    }
    printf("%.10lf\n", (double)ans);
  }
  return 0;
}
