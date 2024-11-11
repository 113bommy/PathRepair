#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, log2n, q, C[N], L[N], R[N], tot = 0, f[N][25], up[N], de2[N];
long long de[N];
struct node {
  long long min, sign;
} a[N * 4];
pair<int, int> E[2 * N];
vector<pair<int, int> > e[N];
void add1(int x, int k) {
  for (; x <= n; x += x & (-x)) de[x] += k;
}
long long ask1(int x) {
  long long res = 0;
  for (; x; x -= x & (-x)) res += de[x];
  return res;
}
void build(int l, int r, int now) {
  if (l == r) {
    a[now].min = ask1(l) + up[C[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, now << 1);
  build(mid + 1, r, now << 1 | 1);
  a[now].min = min(a[now << 1].min, a[now << 1 | 1].min);
}
void update(int l, int r, int now, int k) {
  a[now].min += k;
  a[now].sign += k;
}
void down(int l, int r, int now) {
  int mid = (l + r) >> 1;
  update(l, mid, now >> 1, a[now].sign);
  update(mid + 1, r, now << 1 | 1, a[now].sign);
  a[now].sign = 0;
}
void add2(int l, int r, int now, int s, int t, int k) {
  if (s <= l && r <= t) {
    update(l, r, now, k);
    return;
  }
  down(l, r, now);
  int mid = (l + r) >> 1;
  if (s <= mid) add2(l, mid, now << 1, s, t, k);
  if (t > mid) add2(mid + 1, r, now << 1 | 1, s, t, k);
  a[now].min = min(a[now << 1].min, a[now << 1 | 1].min);
}
long long ask2(int l, int r, int now, int s, int t) {
  if (s <= l && r <= t) return a[now].min;
  down(l, r, now);
  int mid = (l + r) >> 1;
  long long res = 0x3f3f3f3f3f3f3f3f;
  if (s <= mid) res = min(ask2(l, mid, now << 1, s, t), res);
  if (t > mid) res = min(ask2(mid + 1, r, now << 1 | 1, s, t), res);
  return res;
}
void dfs1(int u, int fa) {
  f[u][0] = fa;
  C[++tot] = u;
  L[u] = tot;
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i].first;
    if (v == fa) continue;
    dfs1(v, u);
  }
  R[u] = tot;
}
void dfs2(int u, int fa) {
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i].first, w = e[u][i].second;
    if (v == fa) continue;
    de2[v] = de2[u] + 1;
    add1(L[v], w);
    add1(R[v] + 1, -w);
    dfs2(v, u);
  }
}
bool on(int u, int v) {
  swap(u, v);
  long long k = de2[u] - de2[v];
  if (k < 0) return false;
  for (int i = 0; k; i++, k >>= 1)
    if (k & 1) u = f[u][i];
  return (u == v);
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  log2n = log2(n);
  for (int i = 1; i <= 2 * n - 2; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (i < n)
      E[i] = {w, v};
    else
      E[i] = {w, u}, up[u] = w;
    if (i >= n) continue;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  dfs1(1, 0);
  dfs2(1, 0);
  for (int j = 1; j <= log2n; j++)
    for (int i = 1; i <= n; i++) f[i][j] = f[f[i][j - 1]][j - 1];
  build(1, n, 1);
  for (int i = 0; i < q; i++) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 1) {
      if (x < n) {
        add1(L[E[x].second], -E[x].first + y);
        add1(R[E[x].second] + 1, E[x].first - y);
        add2(1, n, 1, L[E[x].second], R[E[x].second], -E[x].first + y);
      } else
        add2(1, n, 1, L[E[x].second], L[E[x].second], -E[x].first + y);
      E[x].first = y;
    } else {
      if (on(x, y))
        cout << ask1(L[y]) - ask1(L[x]) << endl;
      else
        cout << ask2(1, n, 1, L[x], R[x]) - ask1(L[x]) + ask1(L[y]) << endl;
    }
  }
  return 0;
}
