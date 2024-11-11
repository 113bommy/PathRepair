#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
const int inf = 1e10;
int n, a[maxn], dp[maxn][4];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 0;
    dp[i][0] = 0;
    dp[i][0] = 0;
    dp[i][0] = 0;
  }
  if (a[1] == 1) {
    dp[1][1] = 1;
  }
  if (a[1] == 2) {
    dp[1][2] = 1;
  }
  if (a[1] == 3) {
    dp[1][2] = 1;
    dp[1][1] = 1;
  }
  for (int i = 2; i <= n; ++i) {
    int m = max(dp[i - 1][0], dp[i - 1][1]);
    dp[i][0] = max(m, dp[i - 1][1]);
    if (a[i] == 0) {
      dp[i][1] = dp[i - 1][1];
      dp[i][2] = dp[i - 1][2];
    } else {
      if (a[i] == 1) {
        dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1);
        dp[i][2] = dp[i - 1][2];
      } else {
        if (a[i] == 2) {
          dp[i][2] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
          dp[i][1] = dp[i - 1][1];
        } else {
          dp[i][2] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
          dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1);
        }
      }
    }
  }
  int t = max(dp[n][2], dp[n][1]);
  int kek = max(t, dp[n][0]);
  cout << n - kek;
  return 0;
}
