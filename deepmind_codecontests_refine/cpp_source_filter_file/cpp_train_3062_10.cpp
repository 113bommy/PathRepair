#include <bits/stdc++.h>
bool o;
int n, m, k, a, t;
int dp[2][775], suf[776];
struct poi {
  int r, c;
} p[100010];
bool operator<(poi x, poi y) { return x.c < y.c; }
int main() {
  scanf("%d%d", &n, &k), m = sqrt(6 * k);
  for (int i = 1; i <= k; ++i) {
    scanf("%d%d", &p[i].r, &p[i].c);
    if ((p[i].r = n - p[i].r + 1) > m) a += 3, --i, --k;
  }
  std::sort(p + 1, p + k + 1);
  for (int i = 1; i <= m; ++i) dp[o][i] = 1e9;
  for (int i = 1, j = 1; i <= n + 1; ++i, o ^= 1) {
    for (int j = 1; j <= m; ++j) suf[j] = 0;
    while (p[j].c == i) suf[p[j].r] += 3, ++j;
    for (int j = m - 1; j; --j) suf[j] += suf[j + 1];
    dp[o ^ 1][0] = std::min(t = dp[o][0], dp[o][1]) + suf[1];
    for (int j = 1; j < m; ++j)
      dp[o ^ 1][j] = std::min((t = std::min(t, dp[o][j])) + j * (j + 1) / 2 + 2,
                              dp[o][j + 1]) +
                     suf[j + 1];
    dp[o ^ 1][m] = t + m * (m + 1) / 2 + 2;
  }
  printf("%d\n", dp[o][0]);
  return 0;
}
