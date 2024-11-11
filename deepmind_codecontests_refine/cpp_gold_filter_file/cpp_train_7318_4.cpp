#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m, t[maxn], a[maxn][maxn], bag[maxn][maxn];
int dp[maxn][10001];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    for (int j = 1; j <= t[i]; j++) {
      cin >> a[i][j];
      a[i][j] += a[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= t[i]; j++)
      for (int k = 0; k <= t[i] && k <= j; k++)
        bag[i][j] = max(bag[i][j], a[i][j - k] + a[i][t[i]] - a[i][t[i] - k]);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= t[i] && k <= j; k++)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + bag[i][k]);
  cout << dp[n][m] << endl;
}
