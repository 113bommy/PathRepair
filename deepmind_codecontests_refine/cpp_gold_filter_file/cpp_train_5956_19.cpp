#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2005;
const int MOD = 998244353;
ll dp[MAXN][MAXN << 1], h[MAXN];
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> h[i];
  h[n + 1] = h[1];
  if (k == 1) {
    cout << 0 << '\n';
    return 0;
  }
  dp[0][2000] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < MAXN << 1; j++)
      if (h[i] == h[i + 1])
        dp[i][j] = (dp[i - 1][j] * k) % MOD;
      else
        dp[i][j] =
            (dp[i - 1][j - 1] + dp[i - 1][j + 1] + dp[i - 1][j] * (k - 2)) %
            MOD;
  ll ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + dp[n][2000 + i]) % MOD;
  cout << ans << '\n';
  return 0;
}
