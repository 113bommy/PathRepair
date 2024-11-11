#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const double INF = 1e20;
double x1, _y1, x2, y2, x0, _y0, d;
int n, tot;
pair<double, int> T[N];
double Q(double x, double y) { return sqrt(x * x + y * y); }
int main() {
  scanf("%lf%lf%lf%lf%d", &x1, &_y1, &x2, &y2, &n);
  x0 = (x1 + x2) / 2;
  _y0 = (_y1 + y2) / 2;
  d = Q(x1 - x0, _y1 - _y0);
  for (int i = 1; i <= n; ++i) {
    double x, y, xx, yy, r;
    scanf("%lf%lf%lf", &x, &y, &r);
    yy = ((y - _y0) - (x - x0) * (_y1 - _y0) / (x1 - x0)) / d * (x1 - x0);
    xx = ((y - _y0) - (x - x0) * (_y1 - _y0) / (x1 - x0)) / d * (_y1 - _y0) +
         (x - x0) * d / (x1 - x0);
    double md = (xx + d) / 2 / yy * (xx - d) + yy / 2;
    {
      double L = -INF, R = md;
      for (int T = 1; T <= 100; ++T) {
        double M = (L + R) / 2;
        if (abs(Q(d, M) - Q(xx, yy - M)) < r)
          R = M;
        else
          L = M;
      }
      T[++tot] = make_pair(L, 1);
    }
    {
      double L = md, R = INF;
      for (int T = 1; T <= 100; ++T) {
        double M = (L + R) / 2;
        if (abs(Q(d, M) - Q(xx, yy - M)) < r)
          L = M;
        else
          R = M;
      }
      T[++tot] = make_pair(L, -1);
    }
  }
  T[++tot] = make_pair(0, 0);
  sort(T + 1, T + tot + 1);
  double ans = INF;
  for (int i = 1, s = 0; i <= tot; ++i) {
    if (s == 0) ans = min(ans, Q(d, T[i].first));
    s += T[i].second;
    if (s == 0) ans = min(ans, Q(d, T[i].first));
  }
  printf("%lf\n", ans);
}
