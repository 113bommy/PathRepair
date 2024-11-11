#include <bits/stdc++.h>
inline long long ceil_div(long long a, long long b) { return (a + b - 1) / b; }
using namespace std;
inline int qr() {
  int f = 0, fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fu = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + (c & 15);
    c = getchar();
  }
  return f * fu;
}
const int N = 2e3 + 10, MOD = 1e9 + 7;
int u[N], v[N], w[N], dp[2][N], b[N], n, m, q;
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++) scanf("%d%d%d", &u[i], &v[i], &w[i]);
  for (int i = 1; i <= n; i++) dp[0][i] = dp[1][i] = -2e9;
  for (int i = 1; i <= m; i++) b[i] = -2e9;
  dp[0][1] = 0;
  int ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i & 1][v[j]] = max(dp[i & 1][v[j]], dp[i - 1 & 1][u[j]] + w[j]);
      dp[i & 1][u[j]] = max(dp[i & 1][u[j]], dp[i - 1 & 1][v[j]] + w[j]);
    }
    for (int j = 1; j <= m; j++)
      b[j] = max(b[j], max(dp[i & 1][u[j]], dp[i & 1][v[j]]) - i * w[j]);
    ans = (1ll * ans + *max_element(dp[i & 1] + 1, dp[i & 1] + 1 + n)) % MOD;
  }
  for (int i = 1; i <= m; i++) {
    int l = n, r = q;
    for (int j = 1; j <= m; j++) {
      if (i == j) continue;
      int k = w[i] - w[j], d = b[j] - b[i] + (j < i);
      if (!k) {
        if (d > 0) {
          r = 0;
          break;
        }
      } else if (k > 0)
        l = max(l, (d + k - 1) / k);
      else
        r = min(r, d / k);
    }
    if (l <= r)
      ans = (ans + 1ll * (l + r) * (r - l + 1) / 2 % MOD * w[i] +
             1ll * (b[i] % MOD + MOD) * (r - l + 1)) %
            MOD;
  }
  printf("%d\n", ans);
  return 0;
}
