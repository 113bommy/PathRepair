#include <bits/stdc++.h>
#pragma GCC optimize "03"
using namespace std;
const long long int N = 1e5 + 5;
const long long int mod = 1e9 + 7;
const long long int inf = 1e18 + 9;
vector<long long int> g[N];
long long int d[N], w[N], dp[N][205];
struct classcomp {
  bool operator()(const long long int& x, const long long int& y) const {
    if (w[x] != w[y])
      return w[x] > w[y];
    else
      return d[x] > d[y];
  }
};
multiset<long long int, classcomp> s;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, k;
  cin >> n >> m >> k;
  for (long long int i = 1; i <= k; i++) {
    long long int s, t;
    cin >> s >> t >> d[i] >> w[i];
    g[s].push_back(i);
    g[t + 1].push_back(-i);
  }
  for (long long int i = 1; i <= n + 1; i++) {
    for (long long int j = 0; j <= m; j++) {
      dp[i][j] = inf;
    }
  }
  for (long long int i = 0; i <= n; i++) {
    for (auto j : g[i]) {
      if (j > 0)
        s.insert(j);
      else {
        assert(s.size() > 0);
        s.erase(s.find(-j));
      }
    }
    if (s.empty()) {
      for (long long int j = 0; j <= m; j++)
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
    } else {
      auto z = *s.begin();
      for (long long int j = 0; j <= m; j++) {
        long long int x = min(d[z] + 1, n + 1);
        dp[x][j] = min(dp[x][j], dp[i][j] + w[z]);
      }
      for (long long int j = 0; j <= m; j++)
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
    }
  }
  long long int ans = inf;
  for (long long int i = 0; i <= m; i++) ans = min(ans, dp[n + 1][i]);
  cout << ans;
  return 0;
}
