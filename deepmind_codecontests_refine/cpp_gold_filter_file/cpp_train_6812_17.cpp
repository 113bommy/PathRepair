#include <bits/stdc++.h>
using namespace std;
char s[105][105];
int a[105][105], n, m;
int dp[105][105][12];
int recur[105][105][12];
int lastremainder[105][105][12];
vector<char> path;
int start;
void recursion(int i, int j, int k) {
  if (i == 0) {
    start = j + 1;
    return;
  }
  if (recur[i][j][k] == -1) {
    recursion(i - 1, j - 1, lastremainder[i][j][k]);
    path.push_back('R');
  } else {
    recursion(i - 1, j + 1, lastremainder[i][j][k]);
    path.push_back('L');
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int k;
  cin >> n >> m >> k;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      cin >> s[i][j];
      a[i][j] = s[i][j] - '0';
    }
  }
  memset(dp, -1, sizeof(dp));
  for (int j = 0; j < m; j++) {
    dp[0][j][a[0][j] % (k + 1)] = a[0][j];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      for (int run = 0; run <= k; run++) {
        if (dp[i][j][run] != -1) {
          if (j > 0) {
            int remain = (run + a[i + 1][j - 1]) % (k + 1);
            if (dp[i][j][run] + a[i + 1][j - 1] > dp[i + 1][j - 1][remain]) {
              dp[i + 1][j - 1][remain] = dp[i][j][run] + a[i + 1][j - 1];
              recur[i + 1][j - 1][remain] = 1;
              lastremainder[i + 1][j - 1][remain] = run;
            }
          }
          if (j < m - 1) {
            int remain = (run + a[i + 1][j + 1]) % (k + 1);
            if (dp[i][j][run] + a[i + 1][j + 1] > dp[i + 1][j + 1][remain]) {
              dp[i + 1][j + 1][remain] = dp[i][j][run] + a[i + 1][j + 1];
              recur[i + 1][j + 1][remain] = -1;
              lastremainder[i + 1][j + 1][remain] = run;
            }
          }
        }
      }
    }
  }
  int ans = -1, endpoint;
  for (int j = 0; j < m; j++) {
    if (dp[n - 1][j][0] > ans) {
      ans = dp[n - 1][j][0];
      endpoint = j;
    }
  }
  if (ans == -1)
    cout << "-1";
  else {
    cout << ans << "\n";
    recursion(n - 1, endpoint, 0);
    cout << start << "\n";
    for (int i = 0; i < path.size(); i++) cout << path[i];
  }
}
