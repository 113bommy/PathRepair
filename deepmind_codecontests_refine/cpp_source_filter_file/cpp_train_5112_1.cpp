#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> col(n);
  for (int i = 0; i != n; i++) {
    cin >> col[i];
  }
  vector<vector<int>> dp(n);
  for (int i = 0; i != n; i++) {
    if (i == 0) {
      dp[i].resize(5, 5);
    }
    dp[i].resize(5, -1);
  }
  for (int i = 1; i != n; i++) {
    for (int j = 0; j != 5; j++) {
      for (int k = 0; k != 5; k++) {
        if (col[i] > col[i - 1]) {
          if (k < j && dp[i - 1][k] != -1) {
            dp[i][j] = k;
          }
        }
        if (col[i] < col[i - 1]) {
          if (k > j && dp[i - 1][k] != -1) {
            dp[i][j] = k;
          }
        }
        if (col[i] == col[i - 1]) {
          if (k != j && dp[i - 1][k] != -1) {
            dp[i][j] = k;
          }
        }
      }
    }
  }
  int st = -1;
  for (int i = 0; i != 5; i++) {
    if (dp[n - 1][i] != -1) {
      st = i;
    }
  }
  if (st == -1) {
    cout << -1;
    return 0;
  }
  vector<int> ans;
  for (int i = n - 1; i != -1; i--) {
    ans.push_back(st);
    st = dp[i][st];
  }
  for (int i = n - 1; i != -1; i--) {
    cout << ans[i] << " ";
  }
  return 0;
}
