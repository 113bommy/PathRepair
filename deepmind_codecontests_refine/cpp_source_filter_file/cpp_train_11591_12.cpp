#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4000 + 5, T = 86400;
int n, k, dp[MAXN][MAXN], t[MAXN], d[MAXN], ans = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MAXN; j++) dp[i][j] = 1;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> t[i] >> d[i];
  t[n] = T;
  ans = t[k] - 1;
  dp[0][0] = t[0] + d[0] - 1;
  for (int i = 1; i < n; i++) dp[i][0] = max(dp[i - 1][0], t[i] - 1) + d[i];
  for (int j = 1; j <= k; j++) {
    for (int i = j; i < n; i++)
      dp[i][j] = min(max(dp[i - 1][j], t[i] - 1) + d[i], dp[i - 1][j - 1]);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++) ans = max(ans, t[i + 1] - dp[i][j] - 1);
  cout << ans << '\n';
  return 0;
}
