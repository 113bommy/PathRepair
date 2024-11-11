#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int LOG = 20;
int cc[MAXN << 2], par[LOG][MAXN], mark[MAXN], tt;
int n, k;
vector<int> adj[MAXN];
int getPar(int de, int u) {
  return par[de][u] = par[de][u] ^ u ? getPar(de, par[de][u]) : u;
}
void plant(int i, int b, int e, int de = 0) {
  if (e - b == 1) {
    cc[i] = 1;
    par[de][b] = b;
    return;
  }
  int m = (b + e) >> 1;
  plant(i << 1, b, m, de + 1);
  plant(i << 1 ^ 1, m, e, de + 1);
  for (int u = b; u < e; u++) {
    par[de][u] = par[de + 1][u];
  }
  for (int u = m - 1; u >= max(b, m - k); --u) {
    for (int v : adj[u]) {
      if (b <= v && v < e) {
        par[de][getPar(de, u)] = getPar(de, v);
      }
    }
  }
  ++tt;
  for (int u = b; u < e; u++) {
    int p = getPar(de, u);
    if (mark[p] ^ tt) {
      ++cc[i];
    }
    mark[p] = tt;
  }
}
int depth[MAXN << 2];
void mark_depth(int i, int b, int e, int l, int r, int de) {
  if (r <= b || e <= l) return;
  if (l <= b && e <= r) {
    depth[i] = de;
    return;
  }
  depth[i] = -1;
  int m = (b + e) >> 1;
  mark_depth(i << 1, b, m, l, r, de);
  mark_depth(i << 1 ^ 1, m, e, l, r, de);
}
int get_depth(int i, int b, int e, int pos) {
  if (~depth[i]) return depth[i];
  int m = (b + e) >> 1;
  if (pos < m) return get_depth(i << 1, b, m, pos);
  return get_depth(i << 1 ^ 1, m, e, pos);
}
int root[MAXN];
int getRoot(int u) {
  if (mark[u] != tt) {
    root[u] = par[get_depth(1, 0, n, u)][u];
  }
  mark[u] = tt;
  return root[u] = root[u] ^ u ? getRoot(root[u]) : u;
}
int go(int i, int b, int e, int l, int r, int de = 0) {
  if (r <= b || e <= l) return 0;
  if (l <= b && e <= r) {
    mark_depth(1, 0, n, b, e, de);
    return cc[i];
  }
  int m = (b + e) >> 1;
  int ret = go(i << 1, b, m, l, r, de + 1) + go(i << 1 ^ 1, m, e, l, r, de + 1);
  b = max(b, l), e = min(e, r);
  for (int u = m - 1; u >= max(b, m - k); --u) {
    for (int v : adj[u]) {
      if (b <= v && v < e) {
        int uu = getRoot(u), vv = getRoot(v);
        if (uu ^ vv) {
          --ret;
          root[uu] = vv;
        }
      }
    }
  }
  return ret;
}
void solve() {
  cin >> n >> k;
  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  plant(1, 0, n);
  int queries;
  cin >> queries;
  while (queries--) {
    ++tt;
    int l, r;
    cin >> l >> r;
    --l;
    cout << go(1, 0, n, l, r) << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int te = 1;
  for (int w = 1; w <= te; w++) {
    solve();
  }
  return 0;
}
