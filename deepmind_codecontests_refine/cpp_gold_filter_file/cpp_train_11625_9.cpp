#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
long long n;
vector<long long> G[N];
long long dp[N][20][2];
long long lev[N];
void dfs(long long u, long long p) {
  vector<long long> ver;
  for (long long i = 0; i < G[u].size(); ++i) {
    long long v = G[u][i];
    if (v == p) continue;
    dfs(v, u);
    lev[u] = max(lev[u], lev[v] + 1);
    ver.push_back(v);
  }
  dp[u][1][0] = dp[u][1][1] = n;
  for (long long i = 2; i <= 19; ++i) {
    long long l = 0, r = n;
    while (l < r) {
      long long mid = l + r + 1 >> 1;
      long long cnt = 0;
      for (long long j = 0; j < ver.size(); ++j) {
        long long v = ver[j];
        if (dp[v][i - 1][0] >= mid) cnt++;
      }
      if (cnt >= mid)
        l = mid;
      else
        r = mid - 1;
    }
    dp[u][i][0] = l;
    for (long long j = 0; j < ver.size(); ++j) {
      long long v = ver[j];
      dp[u][i][1] = max(dp[u][i][1], dp[v][i][1]);
    }
    dp[u][i][1] = max(dp[u][i][1], dp[u][i][0]);
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (long long i = 0; i < n - 1; ++i) {
    long long u, v;
    cin >> u >> v;
    G[u].push_back(v), G[v].push_back(u);
  }
  dfs(1, 1);
  long long res = 0;
  for (long long i = 1; i <= n; ++i) res += lev[i];
  for (long long u = 1; u <= n; ++u) {
    for (long long i = 1; i <= 19; ++i) {
      long long l = 2;
      if (i <= 18) l = max(l, dp[u][i + 1][1] + 1);
      long long r = dp[u][i][1];
      if (l <= r) res += (r - l + 1) * (i - 1);
    }
  }
  res += n * n;
  cout << res << '\n';
}
