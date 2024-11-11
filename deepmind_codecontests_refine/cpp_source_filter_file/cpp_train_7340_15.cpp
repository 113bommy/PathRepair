#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T &x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T &x, L y) {
  return x > y ? (x = y, 1) : 0;
}
const int maxn = 1e5 + 17, lg = 17;
int n, par[maxn][lg], nq, h[maxn], st[maxn], en[maxn], tim;
vector<int> g[maxn];
void build(int v = 0, int p = 0) {
  st[v] = tim++;
  par[v][0] = p;
  for (int i = 1; i < lg; i++) par[v][i] = par[par[v][i - 1]][i - 1];
  for (auto u : g[v])
    if (u != p) h[u] = h[v] + 1, build(u, v);
  en[v] = tim;
}
int lca(int v, int u) {
  if (h[v] > h[u]) swap(v, u);
  for (int i = 0; i < lg; i++)
    if ((h[u] - h[v]) >> i & 1) u = par[u][i];
  if (v == u) return v;
  for (int i = lg - 1; ~i; i--)
    if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
  return *par[v];
}
int a[maxn], m, sz;
bool im[maxn], mr[maxn];
vector<int> c[maxn], tree;
int dfs(int v, int p = -1) {
  int ans = 0, cnt = 0;
  if (im[v]) {
    mr[v] = 1;
    for (auto u : c[v])
      if (u != p) ans += dfs(u, v), ans += mr[u];
  } else {
    mr[v] = 0;
    for (auto u : c[v])
      if (u != p) ans += dfs(u, v), cnt += mr[u];
    if (cnt > 1)
      ans++;
    else if (cnt)
      mr[v] = 1;
  }
  return ans;
}
int solve() {
  if (m == 1) return -1;
  for (int i = 0; i < m; i++)
    if (a[i] && binary_search(a, a + m, *par[a[i]],
                              [](int a, int b) { return st[a] < st[b]; }))
      return -1;
  tree.clear(), sz = 0;
  tree.push_back(a[0]);
  for (int i = 1; i < m; i++) {
    tree.push_back(a[i]);
    tree.push_back(lca(a[i], a[i - 1]));
  }
  sort(tree.begin(), tree.end(), [](int a, int b) { return st[a] < st[b]; });
  tree.resize(unique(tree.begin(), tree.end()) - tree.begin());
  stack<int> s;
  for (auto v : tree) {
    while (s.size() && en[s.top()] <= st[v]) s.pop();
    if (s.size()) {
      c[s.top()].push_back(v);
      c[v].push_back(s.top());
    }
    s.push(v);
  }
  return dfs(tree[0]);
}
int main() {
  ios::sync_with_stdio(0), cin.tie();
  cin >> n;
  for (int i = 1, v, u; i < n; i++)
    cin >> v >> u, g[--v].push_back(--u), g[u].push_back(v);
  build();
  int nq;
  cin >> nq;
  while (nq--) {
    cin >> m;
    for (int i = 0; i < m; i++) cin >> a[i], im[--a[i]] = 1;
    sort(a, a + m, [](int &a, int &b) { return st[a] < st[b]; });
    cout << solve() << '\n';
    for (int i = 0; i < m; i++) im[a[i]] = 0;
    for (auto v : tree) c[v].clear();
  }
  return 0;
}
