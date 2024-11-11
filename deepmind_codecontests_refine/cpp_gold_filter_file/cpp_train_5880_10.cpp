#include <bits/stdc++.h>
inline int read() {
  char C = getchar();
  int A = 0, F = 1;
  while (('0' > C || C > '9') && (C != '-')) C = getchar();
  if (C == '-') F = -1, C = getchar();
  while ('0' <= C && C <= '9')
    A = (A << 1) + (A << 3) + (C - 48), C = getchar();
  return A * F;
}
int n, k;
int num[200];
double dp[200][200], tmp[200][200];
double calc(int x) { return (double)(x) * (double)(x + 1) / 2; }
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) dp[i][j] = 1.0;
  k = std::min((int)900, k);
  double tot = (n + 1) * n / 2;
  for (int m = 1; m <= k; ++m) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) tmp[i][j] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j) {
        tmp[i][j] =
            dp[i][j] * (calc(i - 1) + calc(j - i - 1) + calc(n - j)) / tot;
        for (int q = 1 - i; q + j <= n; ++q)
          tmp[i][j] +=
              (1 - dp[i + q][j + q]) *
              std::min(std::min(i, i + q), n - std::max(j, j + q) + 1) / tot;
        for (int q = 1 - i; q < j - i; ++q)
          tmp[i][j] += dp[i + q][j] *
                       std::min(std::min(i, i + q), j - std::max(i, i + q)) /
                       tot;
        for (int q = i - j + 1; q + j <= n; ++q)
          tmp[i][j] +=
              dp[i][j + q] *
              std::min(std::min(j, j + q) - i, n - std::max(j + q, j) + 1) /
              tot;
      }
    std::memcpy(dp, tmp, sizeof(tmp));
  }
  double ans = 0.0;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      if (num[i] > num[j])
        ans += dp[i][j];
      else
        ans += 1 - dp[i][j];
    }
  std::printf("%.10f", ans);
}
