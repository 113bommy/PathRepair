#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
using namespace std;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const int maxn = 2000 * 100 + 5;
const long long inf = 9223372036854775807;
const long long mod = 1e9 + 7;
const int lg = 20;
int n, q, seg[4 * maxn], cnt, st[maxn], ft[maxn], lazy[4 * maxn], mn[4 * maxn],
    mark[maxn], h[maxn], par[lg][maxn];
vector<int> adj[maxn], t;
map<int, int> e[maxn];
void dfs(int v) {
  st[v] = cnt;
  cnt++;
  t.push_back(v);
  mark[v] = 1;
  for (auto u : adj[v]) {
    if (!mark[u]) {
      par[0][u] = v;
      for (int i = 1; i < lg; i++) {
        par[i][u] = par[i - 1][par[i - 1][u]];
      }
      h[u] = h[v] + 1;
      dfs(u);
    }
  }
  ft[v] = cnt;
}
int get(int k, int v) {
  if (k < 0) cout << k << "boom" << endl;
  for (int i = lg - 1; i >= 0; i--) {
    if ((1 << i) & k) v = par[i][v];
  }
  return v;
}
void build(int x = 1, int lx = 0, int rx = n) {
  if (rx - lx == 1) {
    seg[x] = 1;
    return;
  }
  int mid = lx + rx >> 1;
  build(x << 1, lx, mid);
  build(x << 1 | 1, mid, rx);
  seg[x] = seg[x << 1] + seg[x << 1 | 1];
}
void shift(int x, int lx, int rx) {
  if (lazy[x] == 0) return;
  mn[x] += lazy[x];
  if (rx - lx > 1) {
    lazy[x << 1] += lazy[x];
    lazy[x << 1 | 1] += lazy[x];
  }
  lazy[x] = 0;
}
void upd(int l, int r, int v, int x = 1, int lx = 0, int rx = n) {
  shift(x, lx, rx);
  if (lx >= r || rx <= l) return;
  if (lx >= l && rx <= r) {
    lazy[x] += v;
    shift(x, lx, rx);
    return;
  }
  int mid = lx + rx >> 1;
  upd(l, r, v, x << 1, lx, mid);
  upd(l, r, v, x << 1 | 1, mid, rx);
  mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
  seg[x] = 0;
  if (mn[x << 1] == mn[x]) seg[x] += seg[x << 1];
  if (mn[x << 1 | 1] == mn[x]) seg[x] += seg[x << 1 | 1];
}
bool cmp(const int &a, const int &b) { return st[a] < st[b]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  build();
  dfs(1);
  int u, v, l, r, mid;
  while (q--) {
    cin >> u >> v;
    if (e[u][v] == 0) {
      e[u][v] = 1;
      e[v][u] = 1;
      if (h[u] > h[v]) swap(u, v);
      if (st[v] > st[u] && ft[v] <= ft[u]) {
        u = get(h[v] - h[u] + 1, v);
        upd(st[u], ft[u], 1);
        upd(st[v], ft[v], -1);
      } else {
        upd(0, n, 1);
        upd(st[u], ft[u], -1);
        upd(st[v], ft[v], -1);
      }
    } else {
      e[u][v] = 1;
      e[v][u] = 1;
      if (h[u] > h[v]) swap(u, v);
      if (st[v] > st[u] && ft[v] <= ft[u]) {
        u = get(h[v] - h[u] + 1, v);
        upd(st[u], ft[u], -1);
        upd(st[v], ft[v], 1);
      } else {
        upd(0, n, -1);
        upd(st[u], ft[u], 1);
        upd(st[v], ft[v], 1);
      }
    }
    if (mn[1] > 0) {
      cout << 0 << endl;
    } else {
      cout << seg[1] << endl;
    }
  }
}
