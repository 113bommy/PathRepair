#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 99, M = 45, inf = 1e9;
int n, t, a[N], dp[N][M], ans = inf;
int main() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
    a[i] /= 1000;
  }
  for (int i = 1; i < M; i++) dp[0][i] = inf;
  for (int i = 1; i < n + 1; i++)
    for (int j = 0; j < M; j++) {
      dp[i][j] = inf;
      if (j >= a[i]) dp[i][j] = dp[i - 1][j - a[i]] + a[i] * 10;
      for (int l = j + 1; l < M; l++)
        dp[i][j] = min(dp[i][j], dp[i - 1][l] + max(a[i] * 10 - (l - j), 0));
      ;
    }
  for (int i = 0; i < M; i++) ans = min(ans, dp[n][i]);
  ;
  cout << ans * 100ll;
}
