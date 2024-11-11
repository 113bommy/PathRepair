#include <bits/stdc++.h>
using namespace std;
int a[6][1010], pos[6][1010];
int dp[1010], n, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      pos[i][a[i][j]] = j;
    }
  }
  int ans = 1;
  dp[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = 1;
    for (int j = i + 1; j <= n; j++) {
      bool ok = true;
      for (int x = 1; x <= k; x++) {
        if (pos[x][a[1][i]] > pos[x][a[1][j]]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans;
  return 0;
}
