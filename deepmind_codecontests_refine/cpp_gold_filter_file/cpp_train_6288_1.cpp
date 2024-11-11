#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[305];
long long dist(pair<int, int> a, pair<int, int> b) {
  return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}
int main() {
  int n, i, x, y, j, k;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    scanf("%d", &y);
    p[i] = pair<int, int>(x, y);
  }
  pair<int, int> q, u, v;
  long long d = 0;
  double m, c, ans = 0, l;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      u = p[i];
      v = p[j];
      double len = sqrt(dist(u, v));
      if (u.first == v.first) {
        m = 100000007;
        c = u.first;
      } else {
        m = (v.second - u.second) / ((double)(v.first - u.first));
        c = v.second - m * v.first;
        l = sqrt(1 + m * m);
      }
      double d = 0, d1 = 0, d2 = 0;
      for (k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        if (m == 100000007) {
          if (p[k].first <= u.first)
            d1 = max(d1, double(u.first - p[k].first));
          else
            d2 = max(d2, double(p[k].first - u.first));
        } else {
          double s = m * p[k].first + c;
          if (p[k].second >= s)
            d1 = max(d1, fabs((m * p[k].first - p[k].second + c) / l));
          else
            d2 = max(d2, fabs((m * p[k].first - p[k].second + c) / l));
        }
      }
      if (fabs(d1) < 1e-8) d1 = 0;
      if (fabs(d2) < 1e-8) d2 = 0;
      if (d1 != 0 && d2 != 0) ans = max(ans, 0.5 * (len * (d1 + d2)));
    }
  }
  printf("%.8lf\n", ans);
  return 0;
}
