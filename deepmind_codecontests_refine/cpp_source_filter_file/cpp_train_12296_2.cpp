#include <bits/stdc++.h>
using namespace std;
int dp[55][2088];
int cnt[55];
char col[58];
int n;
int m, S;
int main() {
  cin >> n >> S >> m;
  for (int i = 1; i <= n; i++) cin >> cnt[i];
  scanf("%s", col + 1);
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) dp[i][cnt[i]] = abs(i - S);
  for (int i = 1; i <= 1; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (cnt[j] >= cnt[k]) continue;
        if (col[j] == col[k]) continue;
        dp[k][i + cnt[k]] = min(dp[k][i + cnt[k]], dp[j][i] + abs(k - j));
      }
    }
  }
  int ans = 1e9;
  for (int i = m; i <= 2084; i++)
    for (int j = 1; j <= n; j++) ans = min(ans, dp[j][i]);
  if (ans > 1e8) ans = -1;
  cout << ans;
  return 0;
}
