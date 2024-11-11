#include <bits/stdc++.h>
using namespace std;
long long cc = 0;
vector<vector<pair<long long, long long>>> g(300001);
bool visit[300001];
long long dp[2][300001];
void dfs1(long long x, long long pa, long long val) {
  cc++;
  visit[x] = 1;
  for (auto X : g[x]) {
    if (X.first != pa && X.second == val) dfs1(X.first, x, val);
  }
}
void dfs2(long long x, long long pa) {
  for (auto X : g[x]) {
    if (X.first != pa) {
      dfs2(X.first, x);
      if (X.second == 0)
        dp[0][x] += (1 + dp[0][X.first]);
      else
        dp[1][x] += (1 + dp[1][X.first]);
    }
  }
}
void dfs3(long long x, long long pa) {
  for (auto X : g[x]) {
    if (X.first != pa) {
      if (X.second == 0)
        dp[0][X.first] += (dp[0][x] - dp[0][X.first]);
      else
        dp[1][X.first] += (dp[1][x] - dp[1][X.first]);
      dfs3(X.first, x);
    }
  }
}
void query() {
  long long n, ans = 0;
  cin >> n;
  for (long long i = 1; i < n; i++) {
    long long x, y, c;
    cin >> x >> y >> c;
    g[x].push_back({y, c});
    g[y].push_back({x, c});
  }
  memset(visit, false, sizeof(visit));
  for (long long i = 1; i <= n; i++) {
    if (!visit[i]) {
      cc = 0;
      dfs1(i, i, 0);
      ans += (cc * (cc - 1));
    }
  }
  memset(visit, false, sizeof(visit));
  for (long long i = 1; i <= n; i++) {
    if (!visit[i]) {
      cc = 0;
      dfs1(i, i, 1);
      ans += (cc * (cc - 1));
    }
  }
  memset(dp, 0, sizeof(dp));
  dfs2(1, 1);
  dfs3(1, 1);
  for (long long i = 1; i <= n; i++) ans += (dp[0][i] * dp[1][i]);
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    query();
  }
}
