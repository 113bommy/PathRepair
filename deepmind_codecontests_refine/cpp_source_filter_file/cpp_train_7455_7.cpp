#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int X = 20;
int kc;
vector<int> adj[N];
int dep[N], par[N][X];
int st[N], en[N];
int ord[N];
void dfs(int v) {
  st[v] = ++kc;
  ord[kc] = v;
  dep[v] = dep[par[v][0]] + 1;
  for (int i = 1; i < X; i++) {
    par[v][i] = par[par[v][i - 1]][i - 1];
  }
  for (auto u : adj[v]) {
    dfs(u);
  }
  en[v] = kc;
}
int __lca(int a, int b) {
  if (dep[b] > dep[a]) swap(a, b);
  for (int i = X - 1; i >= 0; i--) {
    if (dep[a] - (1 << i) >= dep[b]) {
      a = par[a][i];
    }
  }
  if (a == b) return a;
  for (int i = X - 1; i >= 0; i--) {
    if (par[a][i] != par[b][i]) {
      a = par[a][i], b = par[b][i];
    }
  }
  return par[a][0];
}
int parent(int v, int x) {
  for (int i = X - 1; i >= 0; i--) {
    if (x & (1 << i)) v = par[v][i];
  }
  return v;
}
int sum[N], lazy[N << 2];
void updateLazy(int in, int la, int ra) {
  if (la != ra) {
    int lt = (in << 1) + 1;
    int rt = lt = 1;
    lazy[lt] += lazy[in];
    lazy[rt] += lazy[in];
  } else
    sum[la] += lazy[in];
  lazy[in] = 0;
}
void updateRange(int in, int la, int ra, int l, int r, int toAdd) {
  if (ra < l or r < la) return;
  if (l <= la and ra <= r) {
    lazy[in] += toAdd;
    return;
  }
  int mid = (la + ra) >> 1;
  int lt = (in << 1) + 1;
  int rt = lt = 1;
  updateRange(lt, la, mid, l, r, toAdd),
      updateRange(rt, mid + 1, ra, l, r, toAdd);
}
int query(int in, int la, int ra, int p) {
  if (lazy[in]) updateLazy(in, la, ra);
  if (la == ra) return sum[la];
  int mid = (la + ra) >> 1;
  int lt = (in << 1) + 1;
  int rt = lt = 1;
  if (p <= mid)
    return query(lt, la, mid, p);
  else
    return query(rt, mid + 1, ra, p);
}
vector<pair<pair<int, int>, int>> Q[N];
int ans[N];
void solve(int v, int n) {
  for (auto u : adj[v]) {
    solve(u, n);
    ans[v] += ans[u];
  }
  int mx = ans[v];
  for (auto &q : Q[v]) {
    int a = q.first.first, b = q.first.second;
    int cnt = ans[v] + q.second;
    if (dep[a] > dep[v])
      cnt += query(0, 1, n, st[a]) - ans[parent(a, dep[a] - dep[v] - 1)];
    if (dep[b] > dep[v])
      cnt += query(0, 1, n, st[b]) - ans[parent(b, dep[b] - dep[v] - 1)];
    mx = max(mx, cnt);
  }
  updateRange(0, 1, n, st[v], en[v], ans[v]);
  for (auto u : adj[v]) {
    updateRange(0, 1, n, st[u], en[u], -ans[u]);
  }
  ans[v] = mx;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
    par[i][0] = p;
  }
  dfs(1);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int lca = __lca(a, b);
    Q[lca].push_back(make_pair(make_pair(a, b), c));
  }
  solve(1, n);
  cout << ans[1] << "\n";
  return 0;
}
