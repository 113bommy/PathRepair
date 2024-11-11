#include <bits/stdc++.h>
using namespace std;
const long long nax = 125, mod = 1e9 + 7;
long long add(long long x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
long long mul(long long x, long long y) { return x * y % mod; }
vector<long long> g[nax];
long long vis[nax], cnt[nax], dp[nax][nax];
long long find(long long n, long long k) {
  for (long long i = 0; i <= n; i++)
    for (long long j = 0; j <= k; j++) dp[i][j] = 0;
  dp[0][0] = 1;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < k; j++) {
      dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j + 1] = add(dp[i + 1][j + 1], mul(dp[i][j], cnt[i]));
    }
  return dp[n][k];
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    for (long long i = 0; i < n; i++) g[i].clear();
    for (long long i = 1; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      g[--x].push_back(--y);
      g[y].push_back(x);
    }
    if (k == 2) {
      cout << (n * (n - 1) / 2) % mod << '\n';
      continue;
    }
    long long res = 0;
    for (long long x = 0; x < n; x++) {
      memset(vis, 0, sizeof(vis));
      vis[x] = 1;
      vector<pair<long long, long long> > e;
      long long m = g[x].size();
      for (long long i = 0; i < m; i++) {
        long long y = g[x][i];
        e.push_back({y, i});
        cnt[i] = 1;
        vis[y] = 1;
      }
      while (!e.empty()) {
        res = add(res, find(m, k));
        vector<pair<long long, long long> > ee;
        for (auto p : e) {
          cnt[p.second]--;
          for (auto y : g[p.first])
            if (!vis[y]) {
              ee.push_back({y, p.second});
              vis[y] = 1;
              cnt[p.second]++;
            }
        }
        e = ee;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
