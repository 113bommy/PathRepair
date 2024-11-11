#include <bits/stdc++.h>
using namespace std;
int n, m;
double v;
pair<double, int> a[10011];
pair<double, double> b[100011], ans[10011];
int main() {
  scanf("%d%lf", &n, &v);
  for (int i = 1; i <= n; ++i) scanf("%lf", &a[i].first), a[i].second = i;
  sort(a + 1, a + n + 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%lf%lf", &b[i].first, &b[i].second);
  b[++m] = make_pair(1e10, 1e10);
  sort(b + 1, b + m + 1);
  for (int i = 1, j = 1; i <= n; ++i) {
    double e = a[i].first;
    double mx = 2.0 * v * v * sin(e) * cos(e) / 9.8;
    for (;; ++j) {
      if (mx < b[j].first) {
        ans[a[i].second] = make_pair(mx, 0.0);
        break;
      }
      double t = b[j].first / (v * cos(e));
      double my = v * sin(e) * t - 4.9 * t * t;
      if (my - 1e-9 < b[j].second) {
        ans[a[i].second] = make_pair(b[j].first, my);
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    printf("%.9lf %.9lf\n", ans[i].first, ans[i].second);
  return 0;
}
