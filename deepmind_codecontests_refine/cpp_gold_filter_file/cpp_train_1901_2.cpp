#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1070;
const long long mod = 998244353;
const long long inf = 1e18 + 10;
long long n;
vector<long long> g[maxn];
vector<long long> H[maxn];
long long h[maxn], tin[maxn], tout[maxn], tim;
void dfs(long long v, long long p = -1) {
  tin[v] = ++tim;
  H[h[v]].push_back(v);
  for (auto u : g[v])
    if (u != p) {
      h[u] = h[v] + 1;
      dfs(u, v);
    }
  tout[v] = ++tim;
}
bool is_anc(long long v, long long u) {
  if (tin[v] <= tin[u] && tout[v] >= tout[u]) return 1;
  return 0;
}
pair<long long, long long> Q(vector<long long> ve) {
  cout << "? " << ve.size() << " ";
  for (auto x : ve) cout << x << " ";
  cout << "\n";
  long long x, d;
  cin >> x >> d;
  return {x, d};
}
long long s, f, dis;
bool ok(long long he) {
  vector<long long> ve;
  for (long long i = he; i <= n; i++)
    for (auto x : H[i]) ve.push_back(x);
  if (ve.empty()) return 0;
  pair<long long, long long> X = Q(ve);
  if (X.second == dis) {
    s = X.first;
    return 1;
  }
  return 0;
}
void solve() {
  vector<long long> kol;
  for (long long i = 1; i <= n; i++) kol.push_back(i);
  pair<long long, long long> X = Q(kol);
  long long v = X.first;
  dis = X.second;
  s = v;
  h[v] = 0;
  dfs(v);
  long long lo = (dis - 5) / 2, hi = dis + 1;
  while (hi - lo > 1) {
    long long tm = (hi + lo) >> 1;
    if (ok(tm))
      lo = tm;
    else
      hi = tm;
  }
  long long hf = dis - h[s];
  vector<long long> ve;
  for (auto x : H[hf])
    if (!is_anc(x, s)) ve.push_back(x);
  if (!ve.empty()) {
    X = Q(ve);
    f = X.first;
  } else
    f = v;
  cout << "! " << s << " " << f << "\n";
  cout.flush();
  string s;
  cin >> s;
}
signed main() {
  long long q;
  cin >> q;
  while (q--) {
    cin >> n;
    for (long long i = 1, u, v; i < n; i++) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    solve();
    for (long long i = 0; i <= n + 10; i++) {
      H[i].clear();
      g[i].clear();
      tout[i] = 0;
      tin[i] = 0;
      h[i] = 0;
      s = 0;
      f = 0;
      dis = 0;
      tim = 0;
    }
  }
}
