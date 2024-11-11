#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans1, ans2;
string ans3;
int a[105][105];
pair<int, pair<int, string> > dp[105][105][15];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char x;
      cin >> x;
      a[i][j] = x - '0';
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int l = 0; l <= k; ++l) {
        dp[i][j][l].first = -1;
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    int x = a[n - 1][j] % (k + 1);
    dp[n - 1][j][x] = {a[n - 1][j], {j, ""}};
  }
  for (int i = n - 1; i > 0; --i) {
    for (int j = 0; j < m; ++j) {
      for (int l = 0; l <= k; ++l) {
        if (dp[i][j][l].first == -1) continue;
        if (j > 0) {
          int x = (dp[i][j][l].first + a[i - 1][j - 1]) % (k + 1);
          if (a[i - 1][j - 1] + dp[i][j][l].first > dp[i - 1][j - 1][x].first) {
            dp[i - 1][j - 1][x].first = a[i - 1][j - 1] + dp[i][j][l].first;
            dp[i - 1][j - 1][x].second.second = dp[i][j][l].second.second + 'L';
            dp[i - 1][j - 1][x].second.first = dp[i][j][l].second.first;
          }
        }
        if (j < m - 1) {
          int x = (dp[i][j][l].first + a[i - 1][j + 1]) % (k + 1);
          if (a[i - 1][j + 1] + dp[i][j][l].first > dp[i - 1][j + 1][x].first) {
            dp[i - 1][j + 1][x].first = a[i - 1][j + 1] + dp[i][j][l].first;
            dp[i - 1][j + 1][x].second.second = dp[i][j][l].second.second + 'R';
            dp[i - 1][j + 1][x].second.first = dp[i][j][l].second.first;
          }
        }
      }
    }
  }
  ans1 = -1;
  for (int i = 0; i < m; ++i) {
    if (ans1 < dp[0][i][0].first) {
      ans1 = dp[0][i][0].first;
      ans2 = dp[0][i][0].second.first;
      ans3 = dp[0][i][0].second.second;
    }
  }
  if (ans1 == -1) {
    cout << -1;
    return 0;
  }
  cout << ans1 << endl << ans2 + 1 << endl << ans3;
  return 0;
}
