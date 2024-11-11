#include <bits/stdc++.h>
using namespace std;
long long int high = 1e18;
int main() {
  long long int n, m, k;
  cin >> n >> m >> k;
  vector<long long int> c(n + 1);
  for (int i = 1; i <= n; i++) cin >> c[i];
  vector<vector<long long int>> cost(n + 1);
  for (int i = 1; i <= n; i++) {
    cost[i].resize(m + 1);
    for (int j = 1; j <= m; j++) cin >> cost[i][j];
  }
  long long int dp[101][101][101];
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= k; j++)
      for (int l = 1; l <= m; l++) dp[i][j][l] = high;
  for (int j = 1; j <= k; j++)
    for (int l = 1; l <= m; l++) dp[0][j][l] = high;
  for (int j = 1; j <= n; j++)
    for (int l = 1; l <= m; l++) dp[j][0][l] = high;
  for (int l = 1; l <= m; l++) dp[0][0][l] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= min((long long int)i, k); j++) {
      map<long long int, int> prev;
      prev.clear();
      for (int l = 1; l <= m; l++) prev[dp[i - 1][j - 1][l]]++;
      for (int l = 1; l <= m; l++) {
        long long int p1 = high, p2 = high;
        if (c[i] != 0 && c[i] != l)
          dp[i][j][l] = high;
        else {
          p1 = dp[i - 1][j][l];
          long long int smallest = prev.begin()->first;
          if (smallest != dp[i - 1][j - 1][l])
            p2 = smallest;
          else if (prev[smallest] != 1)
            p2 = smallest;
          else if (prev.size() > 1)
            p2 = (++prev.begin())->first;
          dp[i][j][l] = min(p1, p2);
          if (c[i] == 0) dp[i][j][l] += cost[i][l];
          if (i == 1 && c[i] == 0)
            dp[i][j][l] = cost[i][l];
          else if (i == 1 && c[i] == l)
            dp[i][j][l] = 0;
        }
      }
    }
  }
  long long int ans = high;
  for (int l = 1; l <= m; l++) ans = min(ans, dp[n][k][l]);
  if (ans == high)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
