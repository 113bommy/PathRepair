#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int n;
int a[5001];
int b[5001];
int c[5001];
int m;
int k;
int d[5001];
vector<int> e[5001];
int ans = -1;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  int i, j;
  for (i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    d[i] = i;
  }
  for (i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    d[v] = max(u, d[v]);
  }
  for (i = 0; i <= n; i++)
    for (j = 0; j <= 5000; j++) dp[i][j] = -999999999;
  dp[0][k] = 0;
  for (i = 1; i <= n; i++) {
    e[d[i]].push_back(c[i]);
  }
  for (i = 1; i <= n; i++) sort(e[i].begin(), e[i].end());
  for (i = 1; i <= n; i++) {
    for (j = a[i]; j + b[i] <= 5000; j++) {
      dp[i][j + b[i]] = dp[i - 1][j];
      int s = e[i].size();
      int t = 0;
      for (int l = s - 1; l >= 0 && j + b[i] - (s - l) >= 0; l--) {
        t += e[i][l];
        dp[i][j + b[i] - (s - l)] =
            max(dp[i][j + b[i] - (s - l)], dp[i][j + b[i]] + t);
      }
    }
    if (i == n)
      for (j = 0; j <= 5000; j++) ans = max(ans, dp[i][j]);
  }
  cout << ans;
  return 0;
}
