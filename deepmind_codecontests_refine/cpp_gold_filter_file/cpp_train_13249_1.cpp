#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
struct segtree {
  int size;
  vector<pair<int, int>> vals;
  void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    vals.assign(2 * size, {0, 0});
  }
  void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)a.size()) vals[x] = {a[lx], lx};
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    vals[x] = max(vals[2 * x + 1], vals[2 * x + 2]);
  }
  void build(vector<int> &a) { build(a, 0, 0, size); }
  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      vals[x].first = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    vals[x] = max(vals[2 * x + 1], vals[2 * x + 2]);
  }
  void set(int i, int v) { set(i, v, 0, 0, size); }
  pair<int, int> calc(int l, int r, int x, int lx, int rx) {
    if (lx >= l && rx <= r) return vals[x];
    if (lx >= r || rx <= l) return {-1, -1};
    int m = (lx + rx) / 2;
    pair<int, int> s1 = calc(l, r, 2 * x + 1, lx, m);
    pair<int, int> s2 = calc(l, r, 2 * x + 2, m, rx);
    return max(s1, s2);
  }
  pair<int, int> calc(int l, int r) { return calc(l, r, 0, 0, size); }
};
int n, m, q, t = -1;
int par[600001];
pair<int, int> edges[300001];
set<int> second;
pair<int, int> query[500001];
vector<int> adj[600001];
int p[600001];
int qp[500001];
bool vis[600001];
int tin[600001];
int tout[600001];
vector<int> et;
vector<int> ind;
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void join(int a, int b, int c) {
  par[c] = c;
  par[a] = c;
  par[b] = c;
  adj[c].push_back(b);
  adj[c].push_back(a);
  adj[b].push_back(c);
  adj[a].push_back(c);
}
void dfs(int x) {
  vis[x] = true;
  t++;
  tin[x] = t;
  et.push_back(p[x]);
  ind.push_back(x);
  for (auto &k : adj[x]) {
    if (!vis[k]) dfs(k);
  }
  t++;
  tout[x] = t;
  et.push_back(p[x]);
  ind.push_back(x);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    par[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    edges[i] = {u, v};
    second.insert(i);
  }
  for (int i = 1; i <= q; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int u;
      cin >> u;
      query[i] = {1, u};
    } else {
      int x;
      cin >> x;
      query[i] = {2, x};
      second.erase(x);
    }
  }
  int cur = n;
  for (auto it = second.begin(); it != second.end(); it++) {
    int i = *it;
    int u = edges[i].first;
    int v = edges[i].second;
    if (find(u) == find(v)) continue;
    cur++;
    join(find(u), find(v), cur);
  }
  for (int i = q; i >= 1; i--) {
    if (query[i].first == 1) {
      qp[i] = find(query[i].second);
    } else {
      int u = edges[query[i].second].first;
      int v = edges[query[i].second].second;
      if (find(u) == find(v)) continue;
      cur++;
      join(find(u), find(v), cur);
    }
  }
  int N = cur;
  for (int i = N; i >= 1; i--) {
    if (!vis[i]) dfs(i);
  }
  segtree st;
  st.init(t + 2);
  st.build(et);
  for (int i = 1; i <= q; i++) {
    if (query[i].first == 2) continue;
    pair<int, int> ans = st.calc(tin[qp[i]], tout[qp[i]] + 1);
    cout << ans.first << "\n";
    st.set(tin[ind[ans.second]], 0);
    st.set(tout[ind[ans.second]], 0);
  }
}
