#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const double inf = 1e+20;
int n, m;
int a[N];
double s[N], g[N], t[N];
double f[N], h[N];
pair<double, double> q[N];
double slope(pair<double, double> a, pair<double, double> b) {
  return (b.second - a.second) / (b.first - a.first);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
    g[i] = g[i - 1] + 1.0 * s[i] / a[i];
    t[i] = t[i - 1] + 1.0 / a[i];
  }
  for (int i = 0; i <= n; i++) f[i] = h[i] = inf;
  f[0] = 0;
  for (int j = 1; j <= m; j++) {
    int k1 = 0, k2 = 0;
    q[0] = make_pair(0, f[0]);
    for (int i = 1; i <= n; i++) {
      while (k1 < k2 && slope(q[k1 + 1], q[k1]) < t[i]) k1++;
      h[i] = -q[k1].first * t[i] + q[k1].second + g[i];
      pair<double, double> tmp = make_pair(s[i], f[i] - g[i] + s[i] * t[i]);
      while (k1 < k2 && slope(q[k2 - 1], q[k2]) > slope(q[k2], tmp)) k2--;
      q[++k2] = tmp;
    }
    for (int i = 0; i <= n; i++) f[i] = h[i], h[i] = inf;
  }
  printf("%.6lf\n", f[n]);
  return 0;
}
