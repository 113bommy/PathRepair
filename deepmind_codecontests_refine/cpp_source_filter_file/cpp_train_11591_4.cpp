#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4000 + 23;
int n, k, t[MAXN], d[MAXN], dp[MAXN][MAXN], ans;
int main() {
  cin >> n >> k;
  if (n == 0) return cout << 86400, 0;
  for (int i = 0; i < n; i++) cin >> t[i] >> d[i];
  t[n] = 86400;
  for (int i = 0; i < n; i++) dp[0][i] = max(t[i], dp[0][i - 1]) + d[i];
  for (int i = 1; i <= k; i++)
    for (int j = 0; j < n; j++) {
      if (j < i) {
        dp[i][j] = 1;
        continue;
      }
      dp[i][j] = min(dp[i - 1][j - 1], max(t[j], dp[i][j - 1]) + d[j]);
    }
  for (int i = 0; i < n; i++) ans = max(ans, t[i + 1] - dp[k][i]);
  cout << ans;
  return 0;
}
