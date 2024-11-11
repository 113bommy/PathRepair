#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[6][1002];
int pos[6][1002];
int dp[1002];
int main() {
  int i, j, ij;
  cin >> n >> k;
  for (i = 1; i <= k; i++)
    for (j = 1; j <= n; j++) {
      cin >> a[i][j];
      pos[i][a[i][j]] = j;
    }
  int ans = 1;
  dp[n] = 1;
  for (i = n - 1; i >= 1; i--) {
    dp[i] = 1;
    for (j = i + 1; j <= n; j++) {
      bool ok = true;
      for (ij = 1; ij <= k; ij++)
        if (pos[ij][a[1][i]] > pos[ij][a[1][j]]) {
          ok = false;
          break;
        }
      if (ok) dp[i] = max(dp[i], dp[j] + 1);
    }
    ans = max(ans, dp[i]);
  }
  cout << ans;
  return 0;
}
