#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9;
bool isLucky(long long n) {
  while (n > 0) {
    long long x = n % 10;
    if (x != 4 && x != 7) return false;
    n /= 10;
  }
  return true;
}
vector<vector<pair<long long, bool>>> g;
vector<long long> dp, s;
vector<bool> used;
void dfs(long long v) {
  used[v] = true;
  s[v] = 1;
  for (auto& p : g[v]) {
    long long u = p.first;
    bool lucky = p.second;
    if (!used[u]) {
      dfs(u);
      s[v] += s[u];
      if (lucky)
        dp[v] += s[u];
      else
        dp[v] += dp[u];
    }
  }
}
long long ans = 0;
void dfs(long long v, long long up) {
  used[v] = true;
  long long x = dp[v] + up;
  ans += x * (x - 1);
  for (auto& p : g[v]) {
    long long u = p.first;
    bool lucky = p.second;
    if (!used[u]) {
      if (lucky)
        dfs(u, g.size() - s[u]);
      else
        dfs(u, dp[v] - dp[u] + up);
    }
  }
}
void solve() {
  long long n;
  cin >> n;
  g.resize(n);
  for (long long i = 0; i < n - 1; i++) {
    long long from, to, num;
    cin >> from >> to >> num;
    from--;
    to--;
    bool lucky = isLucky(num);
    g[from].push_back(make_pair(to, lucky));
    g[to].push_back(make_pair(from, lucky));
  }
  used.resize(n);
  dp.resize(n);
  s.resize(n);
  dfs(0);
  used.clear();
  used.resize(n);
  dfs(0, 0);
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(12);
  solve();
}
