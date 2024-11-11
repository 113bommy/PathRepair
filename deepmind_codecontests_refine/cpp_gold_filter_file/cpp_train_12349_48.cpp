#include <bits/stdc++.h>
using namespace std;
int n, m;
double dp[55][5005];
int f[55], s[55], p[55];
bool isok(double mid) {
  for (int i = (0); i < (m + 1); ++i) dp[n][i] = 0;
  for (int i = (n)-1; i >= (0); --i)
    for (int j = (0); j < (m + 1); ++j) {
      double t1 = 1.0 * p[i + 1] * (f[i + 1] + mid) / 100.0,
             t2 = 1.0 * (100 - p[i + 1]) * (s[i + 1] + mid) / 100.0;
      if (j + f[i + 1] <= m)
        t1 = 1.0 * p[i + 1] * (f[i + 1] + dp[i + 1][j + f[i + 1]]) / 100.0;
      if (j + s[i + 1] <= m)
        t2 = 1.0 * (100 - p[i + 1]) * (s[i + 1] + dp[i + 1][j + s[i + 1]]) /
             100.0;
      dp[i][j] = min(t1 + t2, mid);
    }
  return dp[0][0] >= mid;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i < (n + 1); ++i) scanf("%d%d%d", &f[i], &s[i], &p[i]);
  double l = 0, r = 1e8;
  while (r - l > 1e-8) {
    double mid = (l + r) / 2;
    if (isok(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.12lf\n", l);
  return 0;
}
