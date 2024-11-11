#include <bits/stdc++.h>
using namespace std;
int const N = 100, P = 10, X = N * P;
double const inf = 1e18;
double dp[N + 1][X + 1], prc[N + 1];
pair<int, int> x[N];
void up(double &x, double y) { x = min(x, y); }
void solve() {
  int n;
  double C, T;
  scanf("%d%lf%lf", &n, &C, &T);
  for (int i = 0; i < (int)(n); ++i) scanf("%d%d", &x[i].first, &x[i].second);
  sort(x, x + n);
  reverse(x, x + n);
  for (int i = 0; i < (int)(n + 1); ++i)
    for (int j = 0; j < (int)(X + 1); ++j) dp[i][j] = inf * 1.5;
  dp[0][0] = 0.0;
  for (int i = 0; i < (int)(n); ++i)
    for (int j = n - 1; j >= 0; --j)
      for (int k = 0; k < (int)(X - x[i].second + 1); ++k)
        if (dp[j][k] < inf)
          up(dp[j + 1][k + x[i].second], dp[j][k] + x[i].first * prc[j]);
  int an = 0;
  for (int i = 1; i < (int)(n + 1); ++i)
    for (int j = 1; j < (int)(X + 1); ++j)
      if (dp[i][j] < inf) {
        double l = 0.0, r = T;
        for (int it = 0; it < (int)(50); ++it) {
          double m1 = l + (r - l) / 3.0, m2 = r - (r - l) / 3.0;
          double v1 = m1 + dp[i][j] / (m1 * C + 1),
                 v2 = m2 + dp[i][j] / (m2 * C + 1);
          if (v1 < v2)
            r = m2;
          else
            l = m1;
        }
        if (l + dp[i][j] / (l * C + 1) + i * 10 < T + 1e-5) an = max(an, j);
      }
  printf("%d\n", an);
}
int main() {
  prc[0] = 1 / 0.9;
  for (int i = 1; i < (int)(N); ++i) prc[i] = prc[i - 1] / 0.9;
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
