#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int MOD = 998244353;
long long dp[MAXN][MAXN], h[MAXN], n, k, ans;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> h[i];
  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }
  dp[0][2001] = 1;
  ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < MAXN << 1; j++)
      if (h[i] == h[i % n + 1])
        dp[i][j] = (dp[i - 1][j] * k) % MOD;
      else
        dp[i][j] =
            (dp[i - 1][j - 1] + dp[i - 1][j + 1] + dp[i - 1][j] * (k - 2)) %
            MOD;
  for (int i = 1; i <= n; i++) ans = (ans + dp[n][2001 + i]) % MOD;
  cout << ans << endl;
  return 0;
}
