#include <bits/stdc++.h>
using namespace std;
bool dp[505][505][505];
int a[505];
int main() {
  int n, lero;
  cin >> n >> lero;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  dp[0][0][0] = true;
  for (int i = 1; i <= n; ++i) {
    dp[i][a[i]][0] = true;
    dp[i][a[i]][a[i]] = true;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= lero; ++j) {
      for (int k = 0; k <= lero; ++k) {
        dp[i][j][k] = dp[i - 1][j][k];
        if (j - a[i] >= 0) {
          dp[i][j][k] = dp[i][j][k] || dp[i - 1][j - a[i]][k];
          if (k - a[i] >= 0) {
            dp[i][j][k] = dp[i][j][k] || dp[i - 1][j - a[i]][k - a[i]];
          }
        }
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i <= lero; ++i) {
    if (dp[n][lero][i]) {
      cnt++;
    }
  }
  cout << cnt;
  cout << "\n";
  for (int i = 0; i <= lero; ++i) {
    if (dp[n][lero][i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
  return 0;
}
