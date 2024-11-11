#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 50;
const long long mod = 1e9 + 7;
vector<long long> g[N];
vector<pair<long long, long long> > edges;
set<long long> xset[N], xset1[N];
long long val[N];
long long n, m, k;
vector<long long> xx;
long long dfs(long long node, long long x) {
  long long ret = 1;
  xset[x].erase(xset[x].find(node));
  for (auto to : g[node]) {
    if (val[to] ^ val[node] == xx[x]) {
      if (xset[x].find(to) != xset[x].end()) ret += dfs(to, x);
    }
  }
  return ret;
}
long long binpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret *= a;
    a *= a;
    ret %= mod;
    a %= mod;
    b >>= 1;
  }
  return ret % mod;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) cin >> val[i];
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    edges.push_back({u, v});
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long ans = 0;
  for (long long i = 0; i < edges.size(); i++) {
    long long x = val[edges[i].first] ^ val[edges[i].second];
    xx.push_back(x);
  }
  sort(xx.begin(), xx.end());
  xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
  ans = binpow(2, n);
  long long temp = 1ll << k;
  temp -= xx.size();
  temp %= mod;
  ans *= temp;
  ans %= mod;
  for (auto f : edges) {
    long long xy = val[f.first] ^ val[f.second];
    long long ind = lower_bound(xx.begin(), xx.end(), xy) - xx.begin();
    xset[ind].insert(f.first);
    xset[ind].insert(f.second);
  }
  for (long long i = 0; i < xx.size(); i++) xset1[i] = xset[i];
  for (long long i = 0; i < xx.size(); i++) {
    temp = n;
    while (!xset[i].empty()) temp += (1 - dfs(*xset[i].begin(), i));
    ans += binpow(2ll, temp);
    ans %= mod;
  }
  cout << ans << '\n';
}
