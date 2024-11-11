#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const double Max = 2e9;
const double eps = 1e-6;
int n, T;
double a, k, b, xx, yy, jx, ans, kx, ky;
inline double dis(double X1, double Y1, double X2, double Y2) {
  return sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
}
struct node {
  double x, y;
  node(double xk = 0.0, double yk = 0.0) {
    x = xk;
    y = yk;
  }
  bool operator<(const node& e) const {
    return fabs(dis(-a, 0, x, y) - dis(a, 0, x, y)) <
           fabs(dis(-a, 0, e.x, e.y) - dis(a, 0, e.x, e.y));
  }
} s[N];
int main() {
  scanf("%d%lf", &n, &a);
  ans = 2.0 * a;
  for (register int i = 1; i <= n; i++) scanf("%lf%lf", &s[i].x, &s[i].y);
  sort(s + 1, s + n + 1);
  T = min(40000000 / n, n);
  for (register int now = 1; now <= T; now++) {
    kx = s[now].x;
    ky = s[now].y;
    for (register int i = now + 1; i <= n; i++) {
      if (ky == s[i].y)
        continue;
      else if (kx == s[i].x) {
        ans = min(ans, fabs(fabs(a - kx) - fabs(-a - kx)));
        continue;
      }
      k = (ky - s[i].y) / (kx - s[i].x);
      b = ky - k * kx;
      jx = -b / k;
      if (jx < -a || jx > a) continue;
      xx = ((1 - k * k) * a - 2 * k * b) / (k * k + 1);
      yy = k * a + k * xx + 2 * b;
      ans = min(ans, dis(-a, 0, xx, yy));
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}
