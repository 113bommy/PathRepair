#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = dp[i - 1][j];
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (A[i] == j ? 1 : 0));
    }
  }
  int res = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (dp[n][i] >= k) {
      res = n - i;
      break;
    }
  }
  cout << res << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
