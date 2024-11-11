#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
const int INF = 1e9;
const long long LINF = 1e18;
long long mod_sum() { return 0LL; }
template <typename T, typename... Args>
T mod_sum(T a, Args... args) {
  return ((a + mod_sum(args...)) % mod + mod) % mod;
}
long long mod_prod() { return 1LL; }
template <typename T, typename... Args>
T mod_prod(T a, Args... args) {
  return (a * mod_prod(args...)) % mod;
}
vector<vector<long long> > adj;
vector<bool> vis;
vector<long long> side;
vector<pair<long long, long long> > divisions;
vector<vector<long long> > backtrack[2];
void add_edge(long long u, long long v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
bool bipartite_check() {
  long long n = adj.size();
  queue<long long> q;
  for (long long i = 0; i < n; i++) {
    if (side[i] == -1) {
      backtrack[0].push_back(vector<long long>());
      backtrack[1].push_back(vector<long long>());
      q.push(i);
      side[i] = 0;
      while (!q.empty()) {
        long long v = q.front();
        backtrack[side[v]].back().push_back(v);
        q.pop();
        for (long long u : adj[v]) {
          if (side[u] == -1) {
            side[u] = side[v] ^ 1;
            q.push(u);
          } else if ((side[u] ^ side[v]) == 0)
            return false;
        }
      }
    }
  }
  return true;
}
pair<long long, long long> dfs(long long v) {
  vis[v] = true;
  long long p0 = 0, p1 = 0;
  if (side[v] == 0)
    p0++;
  else
    p1++;
  for (long long u : adj[v]) {
    if (!vis[u]) {
      pair<long long, long long> x = dfs(u);
      p0 += x.first, p1 += x.second;
    }
  }
  return {p0, p1};
}
long long solve() {
  backtrack[0].clear(), backtrack[1].clear();
  long long n, m, n1, n2, n3;
  cin >> n >> m >> n1 >> n2 >> n3;
  adj.resize(n), vis.resize(n, false), side.resize(n, -1);
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    u--, v--;
    add_edge(u, v);
  }
  if (!bipartite_check()) {
    cout << "NO" << endl;
    return 0;
  }
  for (long long i = 0; i < n; i++) {
    if (!vis[i]) divisions.push_back(dfs(i));
  }
  vector<vector<long long> > dp(divisions.size() + 5,
                                vector<long long>(n + 5, -1));
  dp[0][0] = 0;
  for (long long i = 0; i < divisions.size(); i++) {
    for (long long j = 0; j < n; j++) {
      if (dp[i + 1][j] != -1) {
        dp[i + 1][j + divisions[i].first] = 0;
        dp[i + 1][j + divisions[i].second] = 1;
      }
    }
  }
  if (dp[divisions.size()][n2] == -1) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  vector<long long> ans(n + 5);
  long long cur = n2;
  for (long long i = divisions.size(); i > 0; i--) {
    for (auto it : backtrack[dp[i][cur]][i - 1]) ans[it] = 2;
    cur -= backtrack[dp[i][cur]][i - 1].size();
    if (cur == 0) break;
  }
  for (long long i = 0; i < n; i++) {
    if (ans[i] != 2) {
      if (n1 > 0)
        ans[i] = 1, n1--;
      else
        ans[i] = 3;
    }
  }
  for (long long i = 0; i < n; i++) cout << ans[i];
  cout << endl;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
