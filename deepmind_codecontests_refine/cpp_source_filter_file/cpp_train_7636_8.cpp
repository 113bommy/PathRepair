#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
pair<double, double> za, zb, zc, zd;
pair<double, double> a, b, c, d, e;
pair<double, double> A, B, C, D;
double cha(pair<double, double> a, pair<double, double> b,
           pair<double, double> c) {
  return (b.first - a.first) * (c.second - a.second) -
         (b.second - a.second) * (c.first - a.first);
}
pair<double, double> jiao(pair<double, double> a, pair<double, double> b,
                          pair<double, double> c, pair<double, double> d) {
  double t1 = cha(a, c, b), t2 = cha(a, b, d), t3 = cha(c, a, d),
         t4 = cha(c, d, b);
  return make_pair((c.first * t2 + d.first * t1) / (t1 + t2),
                   (c.second * t2 + d.second * t1) / (t1 + t2));
}
void work(pair<double, double> a, pair<double, double> b,
          pair<double, double> &c, pair<double, double> &d) {
  c.first = (a.first + b.first) / 2, c.second = (a.second + b.second) / 2;
  d.first = c.first + b.second - a.second,
  d.second = c.second + a.first - b.first;
}
bool get(pair<double, double> a, pair<double, double> b,
         pair<double, double> c) {
  work(a, b, za, zb), work(b, c, zc, zd);
  d.first = b.first + zd.first - zc.first,
  d.second = b.second + zd.second - zc.second;
  d = jiao(b, d, za, zb);
  e = jiao(za, zb, zc, zd);
  A.first = 2 * d.first - e.first, A.second = 2 * d.second - e.second;
  B.first = 2 * b.first - A.first, B.second = 2 * b.second - A.second;
  C.first = 2 * c.first - B.first, C.second = 2 * c.second - B.second;
  D.first = 2 * a.first - A.first, D.second = 2 * a.second - A.second;
  return cha(A, B, C) * cha(B, C, D) - eps > 0 &&
         cha(B, C, D) * cha(C, D, A) - eps > 0 &&
         cha(C, D, A) * cha(D, A, B) - eps > 0;
}
int main() {
  int t;
  for (scanf("%d", &t); t--;) {
    scanf("%lf%lf%lf%lf%lf%lf", &a.first, &a.second, &b.first, &b.second,
          &c.first, &c.second);
    if (fabs(cha(a, b, c)) - eps > 0) {
      printf("NO\n");
      continue;
    }
    if (get(a, b, c) || get(a, c, b) || get(b, a, c)) {
      printf("YES\n");
      printf("%.9f %.9f ", A.first, A.second);
      printf("%.9f %.9f ", B.first, B.second);
      printf("%.9f %.9f ", C.first, C.second);
      printf("%.9f %.9f\n", D.first, D.second);
    } else
      printf("NO\n");
  }
  return 0;
}
