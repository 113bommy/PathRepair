#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long r) {
  uniform_int_distribution<long long> uid(l, r);
  return uid(rng);
}
const int N = 1e5 + 5;
const int LOGN = 17;
int dp[LOGN][N];
int depth[N], st[N], tt;
long long dist[N];
vector<pair<int, int> > g[N];
void dfs(int u, int p) {
  st[u] = ++tt;
  depth[u] = depth[p] + 1;
  dp[0][u] = p;
  for (pair<int, int> v : g[u]) {
    if (v.first != p) {
      dist[v.first] = dist[u] + v.second;
      dfs(v.first, u);
    }
  }
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int k = LOGN - 1; k >= 0; k--) {
    if (depth[dp[k][u]] >= depth[v]) u = dp[k][u];
  }
  if (u == v) return u;
  for (int k = LOGN - 1; k >= 0; k--) {
    if (dp[k][u] != dp[k][v]) u = dp[k][u], v = dp[k][v];
  }
  return dp[0][u];
}
int D(int u, int v) { return dist[u] + dist[v] - 2 * dist[lca(u, v)]; }
long long cur = 0;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs(1, 0);
  for (int k = 1; k <= LOGN - 1; k++) {
    for (int i = 1; i <= n; i++) {
      dp[k][i] = dp[k - 1][dp[k - 1][i]];
    }
  }
  set<pair<int, int> > s;
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    char ch;
    int u;
    cin >> ch;
    if (ch != '?') cin >> u;
    if (ch == '?') {
      cout << cur / 2 << '\n';
    } else if (ch == '+') {
      if (!(int)s.size()) {
        s.insert({st[u], u});
      } else {
        auto it = s.upper_bound({st[u], u});
        if (it == s.end()) {
          it = s.begin();
        }
        int v1 = it->second;
        if (it == s.begin()) {
          it = s.end();
        }
        it--;
        int v2 = it->second;
        cur -= D(v1, v2);
        cur += D(v1, u);
        cur += D(v2, u);
        s.insert({st[u], u});
      }
    } else {
      if ((int)s.size() == 1) {
        s.clear();
        cur = 0;
      } else {
        s.erase({st[u], u});
        auto it = s.upper_bound({st[u], u});
        if (it == s.end()) {
          it = s.begin();
        }
        int v1 = it->second;
        if (it == s.begin()) {
          it = s.end();
        }
        it--;
        int v2 = it->second;
        cur -= D(v1, u);
        cur -= D(v2, u);
        cur += D(v1, v2);
      }
    }
  }
  return 0;
}
