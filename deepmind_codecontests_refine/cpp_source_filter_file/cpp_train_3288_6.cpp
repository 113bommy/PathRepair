#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
const long long N = 5e2 + 7;
long long n, m;
bitset<501> dp[501][65][2];
long long mxg[N][2];
long long f[N][2];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    long long v, u, b;
    cin >> v >> u >> b;
    if (b == 0)
      dp[v][0][0][u] = 1;
    else
      dp[v][0][1][u] = 1;
  }
  for (long long k = 1; k < 65; k++)
    for (long long v = 1; v <= n; v++)
      for (long long b = 0; b < 2; b++)
        for (long long u = 1; u <= n; u++)
          if (dp[v][k - 1][b][u]) dp[v][k][b] |= dp[u][k - 1][1 - b];
  for (long long v = 1; v <= n; v++)
    for (long long b = 0; b <= 1; b++) {
      mxg[v][b] = -1;
      for (long long k = 0; k < 65; k++)
        if (dp[v][k][b].any()) mxg[v][b] = k;
    }
  vector<pair<long long, long long> > vec;
  for (long long v = 1; v <= n; v++)
    for (long long b = 0; b < 2; b++) {
      if (mxg[v][b] != -1) vec.push_back({v, b});
      if (!b && mxg[v][b] == 64) {
        cout << -1;
        return 0;
      }
    }
  sort(vec.begin(), vec.end(),
       [](pair<long long, long long> a, pair<long long, long long> b) {
         return mxg[a.first][a.second] < mxg[b.first][b.second];
       });
  long long mx = 0;
  for (auto p : vec) {
    long long v = p.first;
    long long b = p.second;
    long long k = mxg[v][b];
    for (long long u = 1; u <= n; u++)
      if (dp[v][k][b][u]) f[v][b] = max(f[v][b], (1 << k) + f[u][1 - b]);
    if (b == 0) mx = max(mx, f[v][b]);
  }
  if (mx > 1e18)
    cout << -1;
  else
    cout << mx;
  return 0;
}
