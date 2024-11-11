#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int n, l, v1, v2;
double delta;
pair<double, int> a[400007];
double ans[100007];
int main() {
  memset(ans, 0, sizeof(ans));
  cin >> n >> l >> v1 >> v2;
  delta = l * 1.0 * v2 / (v1 + v2);
  double ttt;
  for (int i = 0; i < n; i++) {
    scanf("%lf", &ttt);
    a[i].first = ttt;
  }
  for (int i = 0; i < n; i++) a[i].second = 1;
  for (int i = 0; i < n; i++) a[n + i] = a[i], a[n + i].first += 2 * l;
  int total = 2 * n + 1;
  a[2 * n].first = 2 * l + delta;
  a[n * 2].second = 0;
  for (int i = 0; i < 2 * n; ++i) {
    a[total].first = a[i].first + delta;
    a[total++].second = -1;
  }
  sort(a, a + total);
  int cnt = 0, back = -1;
  for (int i = 0; i < total; ++i) {
    if (a[i].first > 2 * l + delta + 1e-15) break;
    if (a[i].first > delta) {
      double last = delta;
      if (i) last = max(last, a[i - 1].first);
      ans[cnt] += (a[i].first - last) / (2 * l);
    }
    cnt += a[i].second;
  }
  for (int i = 0; i <= n; ++i) printf("%.10f\n", (double)ans[i]);
  return 0;
}
