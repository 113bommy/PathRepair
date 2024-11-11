#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n >> c;
  vector<vector<int>> dp(2, vector<int>(n, INT_MAX)),
      move(2, vector<int>(n - 1));
  for (int i = 0; i < n - 1; i++) cin >> move[0][i];
  for (int i = 0; i < n - 1; i++) cin >> move[1][i];
  dp[0][0] = 0;
  dp[1][0] = c;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        int ncost = move[k][i] + (j == 0 && k == 1 ? c : 0);
        dp[k][i + 1] = min(dp[k][i + 1], ncost + dp[j][i]);
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << min(dp[0][i], dp[1][i]) << " \n"[i == n - 1];
  return 0;
}
