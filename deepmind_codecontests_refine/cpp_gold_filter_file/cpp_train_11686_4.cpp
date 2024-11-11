#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<vector<int>> aCount(n + 1, vector<int>(26, 0)),
      bCount(n + 1, vector<int>(26, 0));
  for (int i = 0; i < n; i++) {
    a[i] -= 'a';
    b[i] -= 'a';
    aCount[i + 1] = aCount[i];
    bCount[i + 1] = bCount[i];
    aCount[i + 1][a[i]]++;
    bCount[i + 1][b[i]]++;
  }
  for (int i = 0; i < 26; i++) {
    if (aCount.back()[i] != bCount.back()[i]) {
      cout << -1 << endl;
      return;
    }
  }
  int large = 1 << 30;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, large));
  for (int i = n; i >= 0; i--) {
    for (int j = n; j >= i; j--) {
      if (j == n) {
        dp[i][n] = 0;
        continue;
      }
      char c = b[j];
      int op = dp[i + 1][j];
      if (a[i] == b[j]) op = min(dp[i + 1][j + 1], op);
      if ((aCount[n][c] - aCount[i][c]) >= (bCount[n][c] - bCount[j][c]))
        op = min(dp[i][j + 1] + 1, op);
      dp[i][j] = op;
    }
  }
  cout << dp[0][0] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
