#include <bits/stdc++.h>
using namespace std;
int t[500005], g[500005], dp[3][5005], s[500005];
int main() {
  int k, n;
  scanf("%d%d", &k, &n);
  dp[0][0] = dp[1][0] = dp[2][0] = 0;
  for (int i = 1; i <= k; i++) dp[0][i] = dp[1][i] = dp[2][i] = 1e9;
  for (int i = 0; i < n; i++) scanf("%d", &t[i]);
  sort(t, t + n);
  for (int i = 1; i < n; i++) s[i] = g[i] = t[i] - t[i - 1];
  sort(s + 1, s + n);
  int cnt = 0, upbound = min(3 * k, n) - 1;
  for (int i = 1; i < n; i++) {
    if (g[i] > s[upbound]) continue;
    cnt++;
    for (int j = 1; j <= cnt && j <= k; j++)
      dp[cnt % 3][j] =
          min(dp[(cnt - 1) % 3][j],
              dp[(cnt - 1 - g[i - 1] <= s[upbound]) % 3][j - 1] + g[i]);
  }
  printf("%d\n", dp[cnt % 3][k]);
  return 0;
}
