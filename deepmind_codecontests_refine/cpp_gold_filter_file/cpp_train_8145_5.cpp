#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
vector<long long> g[N];
const long long LG = 20;
long long tin[N], tout[N], ptr = 0, to[N][LG], h[N], dep[N], up[N];
pair<long long, long long> down[N];
void calc(long long u, long long p) {
  to[u][0] = p;
  for (long long i = 1; i < LG; ++i) to[u][i] = to[to[u][i - 1]][i - 1];
  tin[u] = ptr++;
  down[u] = make_pair(0, u);
  dep[u] = 0;
  for (long long v : g[u])
    if (v != p) {
      h[v] = h[u] + 1;
      calc(v, u);
      dep[u] = max(dep[u], dep[v] + 1);
      auto t = down[v];
      t.first++;
      down[u] = max(down[u], t);
    }
  tout[u] = ptr++;
}
bool anc(long long u, long long v) {
  return tin[u] <= tin[v] && tout[v] <= tout[u];
}
long long lca(long long u, long long v) {
  if (anc(u, v)) return u;
  for (long long i = LG - 1; i >= 0; --i)
    if (!anc(to[u][i], v)) u = to[u][i];
  return to[u][0];
}
long long goup(long long u, long long k) {
  for (long long i = 0; i < LG; ++i)
    if ((k >> i) & 1) u = to[u][i];
  return u;
}
long long dist(long long u, long long v) {
  return h[u] + h[v] - 2 * h[lca(u, v)];
}
void calc_up(long long u, long long p) {
  vector<long long> a = {-1};
  for (long long v : g[u]) {
    if (v != p) {
      a.push_back(dep[v]);
    }
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (long long v : g[u]) {
    if (v != p) {
      up[v] = max(up[u], a[dep[v] == a[0]] + 1) + 1;
      calc_up(v, u);
    }
  }
}
void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  for (long long i = 1; i <= n; ++i) g[i].clear();
  for (long long i = 0; i < n - 1; ++i) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  h[1] = up[1] = 0;
  calc(1, 1);
  calc_up(1, 1);
  long long len = dist(a, b);
  long long root = -1;
  for (long long u = 1; u <= n; ++u) {
    vector<long long> a = {up[u]};
    for (long long v : g[u]) {
      if (v != to[u][0]) a.push_back(dep[v] + 1);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    if (a.size() >= 3 && a[2] >= len) {
      root = u;
    }
  }
  if (root == -1) {
    cout << "NO" << endl;
    return;
  } else {
    h[root] = 0;
    calc(root, root);
    set<pair<long long, long long> > was;
    while (!anc(a, b) && !anc(b, a)) {
      if (was.count(make_pair(a, b))) break;
      was.insert(make_pair(a, b));
      long long to = down[a].second;
      long long d = h[to] - h[a];
      if (dist(lca(a, b), b) <= d) {
        cout << "YES" << endl;
        return;
      } else {
        a = to;
        b = goup(b, d);
      }
      swap(a, b);
    }
    if (anc(a, b) || anc(b, a)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
