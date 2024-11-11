#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t = 1, n, m, i, j, k, u, to, w;
  while (t--) {
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
      cin >> dp[0][i];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= n - i; j++) {
        dp[i][j] = dp[i - 1][j + 1] ^ dp[i - 1][j];
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n - i; j++) {
        dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i - 1][j + 1]});
      }
    }
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int len = r - l;
      cout << dp[len][l - 1] << '\n';
    }
  }
}
