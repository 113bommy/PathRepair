#include <bits/stdc++.h>
using namespace std;
int s[200001];
int dp[200001][5];
int ans[200001];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 5; ++j) {
      dp[i][j] = -1;
    }
  }
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;
  dp[0][3] = 0;
  dp[0][4] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (s[i] > s[i - 1]) {
        for (int l = 0; l < j; ++l) {
          if (dp[i - 1][l] >= 0) {
            dp[i][j] = l;
            break;
          }
        }
      } else {
        if (s[i] < s[i - 1]) {
          for (int l = j + 1; l < 5; ++l) {
            if (dp[i - 1][l] >= 0) {
              dp[i][j] = l;
              break;
            }
          }
        } else {
          for (int l = 0; l < 5; ++l) {
            if (l != j) {
              if (dp[i - 1][l] >= 0) {
                dp[i][j] = l;
                break;
              }
            }
          }
        }
      }
    }
    int fl = 0;
    for (int j = 0; j < 5; ++j) {
      if (dp[i][j] != -1) {
        fl = 1;
      }
    }
    if (fl == 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  int uk;
  for (int i = 0; i < 5; ++i) {
    if (dp[n - 1][i] >= 0) {
      uk = i;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    ans[i] = uk + 1;
    uk = dp[i][uk];
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
