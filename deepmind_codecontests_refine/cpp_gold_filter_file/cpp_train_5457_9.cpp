#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001];
void solve() {
  int n, m;
  cin >> n >> m;
  char x[n][m + 1];
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m;) {
      if (x[i][j] == '0')
        dp[i][j] = -1, j++;
      else {
        int k = j;
        while (k < m && x[i][k] == '1') k++;
        for (int jj = j; jj < k; jj++) dp[i][jj] = k - 1;
        j = k;
      }
    }
  }
  int maxi = 0;
  for (int j = 0; j < m; j++) {
    vector<int> have;
    for (int i = 0; i < n; i++) {
      if (dp[i][j] != -1) have.push_back(dp[i][j] - j + 1);
    }
    sort(have.begin(), have.end());
    for (int it = (int)have.size() - 1, c = 1; it >= 0; it--, c++) {
      maxi = max(maxi, have[it] * c);
    }
  }
  cout << maxi << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  while (t--) solve();
  return 0;
}
