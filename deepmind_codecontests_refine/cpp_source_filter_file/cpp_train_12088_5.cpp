#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
long long mod = 998244353;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long Bpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long n, m;
vector<vector<long long>> g(1e5 + 7);
vector<vector<long long>> w(1e5 + 7);
vector<long long> tin(1e5 + 7), tout(1e5 + 7);
vector<vector<long long>> p(1e5 + 7, vector<long long>(20, -1));
map<pair<long long, long long>, long long> ma;
vector<long long> ver;
vector<long long> h(1e5 + 7);
long long cur = 0;
void dfs(long long v, long long wei = 0, long long par = -1) {
  tin[v] = ++cur;
  h[v] = wei;
  if (par != -1) {
    p[v][0] = par;
    for (long long i = 1; i < 20; i++) {
      if (p[v][i - 1] == -1) break;
      p[v][i] = p[p[v][i - 1]][i - 1];
    }
  }
  for (long long i = 0; i < g[v].size(); i++) {
    if (g[v][i] == par) continue;
    if (tin[g[v][i]] && !tout[g[v][i]]) ver.push_back(v);
    if (!tin[g[v][i]]) dfs(g[v][i], wei + w[v][i], v);
  }
  tout[v] = ++cur;
}
bool is_par(long long v1, long long v2) {
  return tin[v1] < tin[v2] && tout[v2] < tout[v1];
}
long long lca(long long v1, long long v2) {
  if (is_par(v1, v2)) return v1;
  if (is_par(v2, v1)) return v2;
  for (long long i = 19; i >= 0; i--) {
    if (p[v1][i] != -1 && !is_par(p[v1][i], v2)) v1 = p[v1][i];
  }
  return p[v1][0];
}
void dij(long long v, vector<long long>& Len) {
  Len[v] = 0;
  priority_queue<pair<long long, long long>> q;
  q.push({0, v});
  while (!q.empty()) {
    pair<long long, long long> x = q.top();
    q.pop();
    if (-x.first > Len[x.second]) continue;
    for (long long i = 0; i < g[x.second].size(); i++) {
      if (Len[g[x.second][i]] > Len[x.second] + w[x.second][i]) {
        Len[g[x.second][i]] = Len[x.second] + w[x.second][i];
        q.push({-Len[g[x.second][i]], g[x.second][i]});
      }
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    g[a].push_back(b);
    g[b].push_back(a);
    w[a].push_back(c);
    w[b].push_back(c);
  }
  dfs(1);
  vector<vector<long long>> len(ver.size(), vector<long long>(n + 1, 1e18));
  for (long long i = 0; i < ver.size(); i++) {
    dij(ver[i], len[i]);
  }
  long long q;
  cin >> q;
  while (q--) {
    long long a, b;
    cin >> a >> b;
    long long v = lca(a, b);
    long long ans = h[a] + h[b] - 2 * h[v];
    for (long long i = 0; i < ver.size(); i++) {
      ans = min(ans, len[i][a] + len[i][b]);
    }
    cout << ans << "\n";
  }
}
