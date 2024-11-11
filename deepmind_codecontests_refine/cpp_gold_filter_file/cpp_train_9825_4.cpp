#include <bits/stdc++.h>
using namespace std;
int v[100005];
int c[100005];
long long dp[100005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  for (int i = 1; i <= m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int j = 1; j <= n; ++j) dp[j] = -1000000000000000000LL;
    int w1 = 0, w2 = 0;
    long long ans = 0;
    for (int j = 1; j <= n; ++j) {
      if (dp[c[j]] == -1000000000000000000LL)
        dp[c[j]] = 1LL * b * v[j];
      else
        dp[c[j]] = max(dp[c[j]], dp[c[j]] + 1LL * a * v[j]);
      if (w1 == c[j])
        dp[c[j]] = max(dp[c[j]], dp[w2] + 1LL * b * v[j]);
      else
        dp[c[j]] = max(dp[c[j]], dp[w1] + 1LL * b * v[j]);
      if (dp[c[j]] > dp[w1]) {
        if (w1 != c[j]) w2 = w1;
        w1 = c[j];
      } else if (dp[c[j]] > dp[w2] && w1 != c[j]) {
        w2 = c[j];
      }
      ans = max(ans, dp[c[j]]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
