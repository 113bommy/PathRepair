#include <bits/stdc++.h>
using namespace std;
int dp[155][155], full[155][155], T[155][155][155];
int n, cost[155];
char a[155];
int main() {
  int i, j, k, p;
  cin.sync_with_stdio(false);
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> cost[i];
  cin >> (a + 1);
  for (i = n; i; --i)
    for (j = i; j <= n; ++j)
      for (k = 0; k <= n; ++k) T[i][j][k] = full[i][j] = -2000000000;
  for (i = n; i; --i) {
    T[i][i][1] = 0;
    if (cost[1] != -1) T[i][i][0] = cost[1];
  }
  for (i = n; i; --i) T[i][i - 1][0] = 0;
  for (i = n; i; --i)
    for (j = i; j <= n; ++j) {
      if (j > i) {
        for (k = 1; k <= j - i + 1; ++k) {
          for (p = i + 1; p <= j; ++p)
            T[i][j][k] = max(T[i][j][k], T[p][j][k] + full[i][p - 1]);
          for (p = j - 1; p >= i; --p)
            T[i][j][k] = max(T[i][j][k], T[i][p][k] + full[p + 1][j]);
          if (a[i] == a[j] && k >= 2)
            T[i][j][k] = max(T[i][j][k], T[i + 1][j - 1][k - 2]);
        }
      }
      for (k = 1; k <= j - i + 1; ++k)
        if (cost[k] != -1) full[i][j] = max(full[i][j], T[i][j][k] + cost[k]);
      T[i][j][0] = full[i][j];
    }
  for (i = n; i; --i)
    for (j = i; j <= n; ++j) {
      dp[i][j] = full[i][j];
      for (k = i; k <= j; ++k)
        dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
    }
  cout << dp[1][n] << "\n";
  return 0;
}
