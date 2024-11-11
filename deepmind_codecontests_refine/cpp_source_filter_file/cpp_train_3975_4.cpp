#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 7;
const int M = 100 + 7;
pair<pair<int, int>, pair<long long, long long> > p[N];
long long dp[N][N][M];
pair<int, bool> par[N][N][M];
long long a[N], b[N], c[N], ind[N];
pair<int, int> ans[N];
int main() {
  ios::sync_with_stdio(false);
  int n, m, x;
  cin >> n >> m >> x;
  for (int i = 0; i < m; i++) {
    cin >> p[i].second.first >> p[i].second.second >> p[i].first.first;
    p[i].second.second++;
    p[i].first.second = i;
  }
  sort(p, p + m);
  for (int i = 0; i < m; i++)
    a[i] = p[i].second.first, b[i] = p[i].second.second,
    c[i] = p[i].first.first, ind[i] = p[i].first.second;
  memset(par, -1, sizeof par);
  for (int i = 0; i < m; i++) {
    for (long long j = a[i]; j < b[i]; j++) dp[i][1][j - a[i]] = j;
    for (int j = 0; j < i; j++)
      if (c[j] < c[i])
        for (int k = 2; k <= n; k++)
          for (long long l = a[j]; l < b[j]; l++) {
            if (a[i] <= l + x && l + x < b[i] && dp[j][k - 1][l - a[j]] &&
                dp[i][k][l + x - a[i]] < dp[j][k - 1][l - a[j]] + l + x) {
              dp[i][k][l + x - a[i]] = dp[j][k - 1][l - a[j]] + l + x;
              par[i][k][l + x - a[i]] = {j, 0};
            }
            if (a[i] <= l * x && l * x < b[i] && dp[k][k - 1][l - a[j]] &&
                dp[i][k][l * x - a[i]] < dp[j][k - 1][l - a[j]] + l * x) {
              dp[i][k][l * x - a[i]] = dp[j][k - 1][l - a[j]] + l * x;
              par[i][k][l * x - a[i]] = {j, 1};
            }
          }
  }
  long long pos = -1, val = 0;
  for (int i = 0; i < m; i++)
    for (long long j = a[i]; j < b[i]; j++) {
      if (pos == -1 || dp[pos][n][val - a[pos]] < dp[i][n][j - a[i]]) {
        pos = i;
        val = j;
      }
    }
  if (dp[pos][n][val - a[pos]] == 0) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = n; i > 0; i--) {
    ans[i - 1] = {ind[pos] + 1, val};
    auto u = par[pos][i][val - a[pos]];
    pos = u.first;
    if (u.second)
      val /= x;
    else
      val -= x;
  }
  for (int i = 0; i < n; i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
  return 0;
}
