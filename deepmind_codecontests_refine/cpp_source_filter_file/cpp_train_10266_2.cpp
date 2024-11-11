#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
const long long INF = 1e18;
using namespace std;
int L[maxn], R[maxn], wt[maxn];
int n, q, k, son[maxn];
int to_node[maxn], to_node_number[maxn];
long long dis[maxn];
vector<pair<int, int> > G[2 * maxn];
int anc[maxn][20], p[maxn], deep[maxn];
void dfs(int u, int fa, long long d, int dep) {
  L[u] = k;
  p[u] = fa;
  dis[k++] = d + to_node[u];
  deep[u] = dep;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].first, w = G[u][i].second;
    if (u == fa) continue;
    dfs(v, u, d + w, dep + 1);
  }
  R[u] = k - 1;
}
void preprocess() {
  for (int i = 1; i <= n; i++) {
    anc[i][0] = p[i];
    for (int j = 1; (1 << j) < n; j++) anc[i][j] = -1;
  }
  for (int j = 1; (1 << j) < n; j++) {
    for (int i = 1; i <= n; i++) {
      if (anc[i][j - 1] == -1) continue;
      int a = anc[i][j - 1];
      anc[i][j] = anc[a][j - 1];
    }
  }
}
int LCA(int p, int q) {
  int lg;
  if (deep[p] < deep[q]) swap(p, q);
  for (lg = 1; (1 << lg) <= deep[p]; lg++)
    ;
  lg--;
  int ans = 0;
  for (int i = lg; i >= 0; i--) {
    if (deep[p] - (1 << i) >= deep[q]) p = anc[p][i];
  }
  if (p == q) return p;
  return -1;
}
long long C[maxn * 4], lazy[maxn * 4];
int m, ql, qr;
void build(int o, int l, int r) {
  if (l == r) {
    C[o] = dis[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
  C[o] = min(C[o << 1], C[o << 1 | 1]);
}
void push_down(int o) {
  C[o << 1] += lazy[o];
  C[o << 1 | 1] += lazy[o];
  lazy[o << 1] += lazy[o];
  lazy[o << 1 | 1] += lazy[o];
  lazy[o] = 0;
}
long long query(int o, int l, int r) {
  if (l >= ql && r <= qr) return C[o];
  if (l > qr || r < ql) return INF;
  push_down(o);
  int mid = (l + r) >> 1;
  long long p1 = query(o << 1, l, mid);
  long long p2 = query(o << 1 | 1, mid + 1, r);
  C[o] = min(C[o << 1], C[o << 1 | 1]);
  return min(p1, p2);
}
void update(int o, int l, int r) {
  if (l >= ql && r <= qr) {
    C[o] += m;
    lazy[o] += m;
    return;
  }
  if (l > qr || r < ql) return;
  int mid = (l + r) >> 1;
  push_down(o);
  update(o << 1, l, mid);
  update(o << 1 | 1, mid + 1, r);
  C[o] = min(C[o << 1], C[o << 1 | 1]);
}
int main() {
  while (scanf("%d %d", &n, &q) != EOF) {
    k = 0;
    memset(C, 0, sizeof C);
    memset(lazy, 0, sizeof lazy);
    for (int i = 0; i < 2 * maxn; i++) G[i].clear();
    for (int i = 1; i <= 2 * n - 2; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      if (i <= n - 1) {
        G[u].push_back(pair<int, int>(v, w));
        son[i] = v;
        wt[v] = w;
      } else {
        to_node[u] = w;
        to_node_number[i] = u;
      }
    }
    dfs(1, 0, 0, 1);
    preprocess();
    build(1, 0, k - 1);
    while (q--) {
      int op, u, v;
      scanf("%d %d %d", &op, &u, &v);
      if (op == 1) {
        if (u <= n - 1) {
          int sn = son[u], wi = wt[sn];
          ql = L[sn];
          qr = R[sn];
          m = v - wi;
          update(1, 0, k - 1);
          wt[sn] = v;
        } else {
          int vt = to_node_number[u];
          ql = qr = L[vt];
          m = v - to_node[vt];
          to_node[vt] = v;
          update(1, 0, k - 1);
        }
      } else {
        long long ans, ton = to_node[u];
        int nx = LCA(u, v);
        if (nx == u) {
          ql = qr = L[u];
          long long wu = query(1, 0, k - 1) - to_node[u];
          ql = qr = L[v];
          long long wv = query(1, 0, k - 1) - to_node[v];
          ans = wv - wu;
        } else {
          ql = L[u];
          qr = R[u];
          long long d1 = query(1, 0, k - 1);
          ql = qr = L[u];
          d1 -= (query(1, 0, k - 1) - to_node[u]);
          ql = qr = L[v];
          long long d2 = query(1, 0, k - 1);
          ans = d1 + d2 - to_node[v];
        }
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
