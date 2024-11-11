#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = dp[i - 1][j];
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] == j));
    }
  }
  for (int i = n; i >= k; i--) {
    if (dp[n][i] >= k) {
      cout << n - i << endl;
      return;
    }
  }
  cout << -1 << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
