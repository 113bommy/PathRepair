#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long N = 52;
long long n, m, K, c[N];
ll a[N], b[N], dp[N][N][105];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> K;
  for (long long i = 1; i <= m; i++) cin >> a[i] >> b[i] >> c[i];
  memset(dp, -1, sizeof dp);
  for (long long i = 1; i <= m; i++) {
    for (long long j = 0; j <= b[i] - a[i]; j++) {
      dp[1][i][j] = a[i] + j;
    }
  }
  ll ans = 0;
  for (long long i = 2; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      for (long long k = 1; k <= m; k++)
        if (k != j && c[j] > c[k]) {
          for (long long t = 0; t <= b[k] - a[k]; t++)
            if (dp[i - 1][k][t] != -1) {
              ll tm = a[k] + t;
              if (tm + K >= a[j] && tm + K <= b[j]) {
                dp[i][j][tm + K - a[j]] =
                    max(dp[i][j][tm + K - a[j]], tm + K + dp[i - 1][k][t]);
              }
              if (tm * K >= a[j] && tm * K <= b[j]) {
                dp[i][j][tm * K - a[j]] =
                    max(dp[i][j][tm * K - a[j]], tm * K + dp[i - 1][k][t]);
              }
            }
        }
    }
  }
  ll cur = n, lst, pre;
  for (long long j = 1; j <= m; j++) {
    for (long long t = 0; t <= 100; t++) {
      if (dp[n][j][t] > ans) {
        ans = dp[n][j][t];
        lst = j;
        pre = t;
      }
    }
  }
  if (!ans) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  vector<pair<long long, long long> > path;
  path.push_back({lst, a[lst] + pre});
  ans -= a[lst] + pre;
  while (ans) {
    --cur;
    bool ok = 1;
    for (long long j = 1; j <= m; j++)
      if (c[j] < c[lst] && j != lst) {
        for (long long t = 0; t <= 100; t++)
          if (dp[cur][j][t] != -1) {
            ll prev = a[lst] + pre;
            ll now = a[j] + t;
            if (prev - now == K || now * K == prev) {
              if (dp[cur][j][t] == ans) {
                ans -= now;
                lst = j;
                pre = t;
                ok = 0;
                path.push_back({lst, a[lst] + pre});
                break;
              }
            }
          }
        if (!ok) break;
      }
    if (ok) break;
  }
  reverse(path.begin(), path.end());
  for (long long i = 0; i < path.size(); i++) {
    cout << path[i].first << ' ' << path[i].second << '\n';
  }
}
