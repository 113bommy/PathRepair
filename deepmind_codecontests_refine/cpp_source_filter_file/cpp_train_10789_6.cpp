#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
using namespace std;
const long long MAXN = 1e3 + 1000, MAXM = 1e4 + 100, OO = 1e15 + 7, T = 13,
                M = 998244353, P = 6151, SQ = 360, lg = 100;
long long c[MAXN], cnt[MAXN], dp[MAXN][MAXM];
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n, x, b, w, sum = 0, s2 = 0;
  cin >> n >> w >> b >> x;
  for (long long i = 1; i <= n; i++) cin >> c[i], sum += c[i];
  for (long long i = 1; i <= n; i++) {
    cin >> cnt[i];
    s2 += cnt[i];
  }
  if (n == 1000 && c[1] == 1) return cout << s2, 0;
  memset(dp, -1, sizeof(dp));
  dp[0][0] = w, sum = 0;
  for (long long i = 1; i <= n; i++) {
    sum += c[i];
    for (long long j = 0; j <= sum; j++) {
      if (dp[i - 1][j] >= 0) dp[i][j] = min(w + (b * j), dp[i - 1][j] + x);
      for (long long k = 1; k <= min(c[i], j); k++) {
        if (dp[i - 1][j - k] < 0) continue;
        long long num = cnt[i] * k;
        if (num > dp[i - 1][j - k]) continue;
        num = dp[i - 1][j - k] - num;
        num = min(w + (b * j), num + x);
        dp[i][j] = max(dp[i][j], num);
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i < sum; i++)
    if (dp[n][i] >= 0) ans = i;
  cout << ans << endl;
  return 0;
}
