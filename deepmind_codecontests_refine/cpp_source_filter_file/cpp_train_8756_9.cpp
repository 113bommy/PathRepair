#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7, K = 20;
int anc[N][K], level[N], val[N];
int lca(int u, int v) {
  if (level[u] > level[v]) swap(u, v);
  for (int i = K - 1; i >= 0; i--)
    if (level[u] + (1 << i) <= level[v]) v = anc[v][i];
  if (u == v) return u;
  for (int i = K - 1; i >= 0; i--)
    if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
  return anc[u][0];
}
int get(int u, int k) {
  for (int i = 0; i < K; i++)
    if (k & (1 << i)) u = anc[u][i];
  return u;
}
int isanc(int u, int g) {
  int k = level[u] - level[g];
  return k >= 0 && get(u, k) == g;
}
pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
  if (x.first == 0) return y;
  if (y.first == 0) return x;
  if (x.first == -1 || y.first == -1) return {-1, -1};
  vector<int> can = {x.first, x.second, y.first, y.second};
  int a = can[0];
  for (int u : can)
    if (level[u] > level[a]) a = u;
  int b = -1;
  for (int u : can)
    if (!isanc(a, u)) {
      if (b == -1) b = u;
      if (level[b] < level[u]) b = u;
    }
  if (b == -1) {
    b = can[0];
    for (int u : can)
      if (level[u] < level[b]) b = u;
    return {a, b};
  }
  int g = lca(a, b);
  for (int u : can) {
    if (u == a || u == b) continue;
    if (level[u] < level[g] || (!isanc(a, u) && !isanc(b, u))) return {-1, -1};
  }
  return {a, b};
}
int pos[N];
pair<int, int> tr[4 * N];
void build(int u, int st, int en) {
  if (st == en)
    tr[u] = {pos[st], pos[st]};
  else {
    int mid = (st + en) / 2;
    build(2 * u, st, mid);
    build(2 * u + 1, mid + 1, en);
    tr[u] = merge(tr[2 * u], tr[2 * u + 1]);
  }
}
void update(int u, int st, int en, int idx, int val) {
  if (st == en)
    tr[u] = {val, val};
  else {
    int mid = (st + en) / 2;
    if (idx <= mid)
      update(2 * u, st, mid, idx, val);
    else
      update(2 * u + 1, mid + 1, en, idx, val);
    tr[u] = merge(tr[2 * u], tr[2 * u + 1]);
  }
}
pair<int, int> query(int u, int st, int en, int l, int r) {
  if (st > r || l > en) return {0, 0};
  if (l <= st && en <= r) return tr[u];
  int mid = (st + en) / 2;
  return merge(query(2 * u, st, mid, l, r),
               query(2 * u + 1, mid + 1, en, l, r));
}
int dfs(int u, int st, int en, pair<int, int> cur) {
  if (st == en)
    return st - 1;
  else {
    pair<int, int> nw = merge(cur, tr[2 * u]);
    int mid = (st + en) / 2;
    if (nw.first == -1)
      return dfs(2 * u, st, mid, cur);
    else
      return dfs(2 * u + 1, mid + 1, en, nw);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    x++;
    pos[x] = i;
    val[i] = x;
  }
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    anc[i][0] = p;
    level[i] = 1 + level[p];
  }
  for (int k = 1; k < K; k++)
    for (int i = 1; i <= n; i++) anc[i][k] = anc[anc[i][k - 1]][k - 1];
  build(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 2) {
      int ans = 0;
      if (tr[1].first != -1)
        ans = n + 1;
      else
        ans = dfs(1, 1, n, pair<int, int>(0, 0));
      cout << ans << "\n";
    } else {
      int u, v;
      cin >> u >> v;
      update(1, 1, n, val[v], u);
      update(1, 1, n, val[u], v);
      swap(val[u], val[v]);
    }
  }
}
