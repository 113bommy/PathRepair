#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
int n, q;
;
vector<int> adj[maxn];
vector<int> edge[maxn];
vector<pair<int, int> > Q[maxn];
int st[maxn], ed[maxn], Node[maxn], cur;
long long h[maxn];
long long ans[maxn];
void dfs(int v, int par) {
  st[v] = ++cur;
  Node[cur] = v;
  for (int i = 0; i < adj[v].size(); ++i) {
    int u = adj[v][i];
    int c = edge[v][i];
    if (u == par) continue;
    h[u] = (h[v] + c) % mod;
    dfs(u, v);
    ;
  }
  ed[v] = cur;
}
struct node {
  long long dis, disSquare, lazy;
  node() {
    dis = 0;
    disSquare = 0;
    lazy = 0;
  }
  void merge(node L, node R) {
    dis = (L.dis + R.dis) % mod;
    disSquare = (L.disSquare + R.disSquare) % mod;
  }
} seg[4 * maxn];
void build(int idx, int i, int j) {
  if (i == j) {
    int v = Node[i];
    seg[idx].dis = h[v];
    seg[idx].disSquare = (h[v] * h[v]) % mod;
    return;
  }
  int mid = (i + j) >> 1;
  int left = idx << 1;
  int right = left | 1;
  build(left, i, mid);
  build(right, mid + 1, j);
  seg[idx].merge(seg[left], seg[right]);
}
void refresh(int idx, int i, int j) {
  int left = idx << 1;
  int right = left | 1;
  long long add = seg[idx].lazy;
  if (i != j) {
    seg[left].lazy = (seg[left].lazy + add) % mod;
    seg[right].lazy = (seg[right].lazy + add) % mod;
  }
  long long sz = j - i + 1;
  seg[idx].disSquare =
      (seg[idx].disSquare + ((2LL * add % mod) * seg[idx].dis % mod) +
       ((sz * add % mod) * add % mod)) %
      mod;
  seg[idx].dis = (seg[idx].dis + add * sz) % mod;
  seg[idx].lazy = 0;
}
void update(int idx, int i, int j, int l, int r, long long val) {
  refresh(idx, i, j);
  if (i > j || j < l || r < i) return;
  if (l <= i && j <= r) {
    seg[idx].lazy = (seg[idx].lazy + val) % mod;
    refresh(idx, i, j);
    return;
  }
  int mid = (i + j) >> 1;
  int left = idx << 1;
  int right = left | 1;
  update(left, i, mid, l, r, val);
  update(right, mid + 1, j, l, r, val);
  seg[idx].merge(seg[left], seg[right]);
}
node query(int idx, int i, int j, int l, int r) {
  refresh(idx, i, j);
  if (i > j || j < l || r < i) return node();
  if (l <= i && j <= r) return seg[idx];
  int mid = (i + j) >> 1;
  int left = idx << 1;
  int right = left | 1;
  node L = query(left, i, mid, l, r);
  node R = query(right, mid + 1, j, l, r);
  node ret;
  ret.merge(L, R);
  return ret;
}
void dfsSolve(int v, int par) {
  long long Sum = query(1, 1, n, 1, n).disSquare;
  for (int i = 0; i < Q[v].size(); ++i) {
    int u = Q[v][i].first;
    int id = Q[v][i].second;
    int L = st[u];
    int R = ed[u];
    long long subSum = query(1, 1, n, L, R).disSquare;
    ans[id] = (2LL * subSum % mod - Sum + mod) % mod;
  }
  for (int i = 0; i < adj[v].size(); ++i) {
    int u = adj[v][i];
    int c = edge[v][i];
    if (u == par) continue;
    int L = st[u];
    int R = ed[u];
    update(1, 1, n, 1, n, +c);
    update(1, 1, n, L, R, -c * 2);
    dfsSolve(u, v);
    update(1, 1, n, 1, n, -c);
    update(1, 1, n, L, R, +c * 2);
  }
}
void solve() {
  dfs(1, -1);
  build(1, 1, n);
  dfsSolve(1, -1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    adj[a].push_back(b);
    adj[b].push_back(a);
    edge[a].push_back(c);
    edge[b].push_back(c);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    Q[u].push_back({v, i});
  }
  solve();
  for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
