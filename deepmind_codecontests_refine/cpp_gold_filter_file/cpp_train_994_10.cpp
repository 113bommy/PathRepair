#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline _T sqr(const _T& x) {
  return x * x;
}
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-11;
struct tp {
  double x, y;
};
int n, k;
tp a[10240];
double ang[10240];
double w[10240];
tp p1, p2;
double b0[10240];
double tt;
inline double dist(tp p1, tp p2) {
  return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}
inline bool hit(double s, int i) {
  if (w[i] < EPS) return false;
  double da = fabs(ang[i] - b0[i]);
  da = min(da, 2.0 * PI - da);
  double t = da / w[i];
  if (t <= tt) return true;
  int z = 2;
  for (int j = 0; j < (int)(z); j++) {
    double mi = j * 1.0 / z;
    double ma = (j + 1.0) / z;
    for (int tt = 0; tt < (int)(101); tt++) {
      if (ma - mi < 1e-11) break;
      double q1 = (mi * 2.0 + ma) / 3.0;
      double q2 = (mi + 2.0 * ma) / 3.0;
      tp pp1, pp2;
      pp1.x = p1.x + (p2.x - p1.x) * q1;
      pp1.y = p1.y + (p2.y - p1.y) * q1;
      pp2.x = p1.x + (p2.x - p1.x) * q2;
      pp2.y = p1.y + (p2.y - p1.y) * q2;
      double aa1 = atan2(pp1.y - a[i].y, pp1.x - a[i].x);
      double aa2 = atan2(pp2.y - a[i].y, pp2.x - a[i].x);
      double a1 = fabs(ang[i] - aa1);
      a1 = min(a1, 2.0 * PI - a1);
      double a2 = fabs(ang[i] - aa2);
      a2 = min(a2, 2.0 * PI - a2);
      double t1 = a1 / w[i];
      double t2 = a2 / w[i];
      double d1 = dist(p1, pp1);
      double d2 = dist(p1, pp2);
      t1 -= d1 / s;
      t2 -= d2 / s;
      if (t1 <= 0.0) return true;
      if (t2 <= 0.0) return true;
      if (t1 < t2)
        ma = q2;
      else
        mi = q1;
    }
  }
  return false;
}
bool check(double s) {
  int cnt = 0;
  tt = dist(p1, p2) / s;
  for (int i = 0; i < (int)(n); i++) {
    if (cnt + n - i <= k) return true;
    cnt += hit(s, i);
    if (cnt > k) return false;
  }
  return cnt <= k;
}
int main() {
  cout << setiosflags(ios::fixed) << setprecision(10);
  int x, y;
  scanf("%d%d", &x, &y);
  p1.x = x;
  p1.y = y;
  scanf("%d%d", &x, &y);
  p2.x = x;
  p2.y = y;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d%d", &x, &y);
    a[i].x = x;
    a[i].y = y;
    double aa, ww;
    scanf("%lf%lf", &aa, &ww);
    if (aa > PI) {
      aa -= 2.0 * PI;
    }
    ang[i] = aa;
    w[i] = ww;
  }
  scanf("%d", &k);
  for (int i = 0; i < (int)(n); i++) {
    b0[i] = atan2(p2.y - a[i].y, p2.x - a[i].x);
  }
  double mi = 3e-5;
  double ma = 4e+6;
  while (ma - mi > 3e-5 && (ma - mi) / (ma + mi) > 3e-5) {
    double q = (mi + ma) * 0.5;
    *(check(q) ? &ma : &mi) = q;
  }
  printf("%0.5lf\n", (double)mi);
  return 0;
}
