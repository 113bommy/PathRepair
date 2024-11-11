#include <bits/stdc++.h>
using namespace std;
int m, k, dp[1000][11][11], w[10];
int main() {
  for (int i = 0; i < 10; ++i) {
    char c;
    cin >> c;
    if (c == '1') {
      w[k++] = i + 1;
    }
  }
  cin >> m;
  for (int i = 0; i < k; ++i) {
    dp[0][w[i]][i] = 1;
  }
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < 10; ++j) {
      for (int p = 0; p < k; ++p) {
        if (w[p] < j) {
          dp[i][j][p] = 0;
        } else {
          for (int q = 0; q < k; ++q) {
            if (q != p && dp[i - 1][w[p] - j][q]) {
              dp[i][j][p] = q + 1;
            }
          }
        }
      }
    }
  }
  int win_j = -1, win_p = -1;
  for (int j = 1; j < 10; ++j) {
    for (int p = 0; p < k; ++p) {
      if (dp[m - 1][j][p]) {
        win_j = j;
        win_p = p;
      }
    }
  }
  if (win_j == -1) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  int ans[1000];
  for (int i = m - 1; i >= 0; --i) {
    ans[i] = w[win_p];
    int tmp = dp[i][win_j][win_p] - 1;
    win_j = w[win_p] - win_j;
    win_p = tmp;
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << ' ';
  }
  return 0;
}
