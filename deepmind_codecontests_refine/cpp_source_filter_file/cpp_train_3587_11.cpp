#include <bits/stdc++.h>
using namespace std;
int n, m;
long long t[1502][1502];
long long dp[1502][1502];
long long pf[1502][1502];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < m + 1; j++) {
      if (i < n && j < m) scanf("%d", &t[i][j]);
      dp[i][j] = -(1LL << 62);
      pf[i][j] = -(1LL << 62);
    }
  }
  for (int i = 0; i < n; i++) {
    pf[i][0] = t[i][0];
    for (int j = 1; j < m; j++) {
      pf[i][j] = pf[i][j - 1] + t[i][j];
    }
  }
  bool sm = true;
  for (int j = 0; j < m; j++) dp[0][j] = pf[0][j];
  for (int j = m - 1; j >= 0; j--) dp[0][j] = max(dp[0][j + 1], pf[0][j]);
  for (int i = 1; i < n; i++) {
    if (sm) {
      for (int j = 0; j < m - 1; j++) dp[i][j] = dp[i - 1][j + 1] + pf[i][j];
      for (int j = 1; j < m - 1; j++) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
    } else {
      for (int j = 1; j < m; j++) dp[i][j] = dp[i - 1][j - 1] + pf[i][j];
      for (int j = m - 1; j >= 0; j--) dp[i][j] = max(dp[i][j + 1], dp[i][j]);
    }
    sm = !sm;
  }
  long long ans = -(1LL << 62);
  for (int j = 0; j < m; j++) ans = max(dp[n - 1][j], ans);
  cout << ans;
  return 0;
}
