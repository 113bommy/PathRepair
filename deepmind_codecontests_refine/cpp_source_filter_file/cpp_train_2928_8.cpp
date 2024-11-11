#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
long long a[MAXN];
long long dp[MAXN][MAXN];
int main() {
  int n, k, x;
  ios::sync_with_stdio(false);
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  dp[0][1] = a[0];
  for (int i = 0; i < k; i++) dp[i][1] = a[i];
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= x; j++)
      for (int t = max(0, i - 2 * k + 2); t < i; t++)
        if (dp[t][j - 1]) dp[i][j] = max(dp[i][j], dp[t][j - 1] + a[i]);
  long long ans = 0;
  for (int i = 0; i < k; i++) ans = max(ans, dp[n - i - 1][x]);
  if (ans)
    cout << ans;
  else
    cout << -1;
  return 0;
}
