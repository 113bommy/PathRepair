#include <bits/stdc++.h>
using namespace std;
const int MAXN = 220000;
const int MAXB = 22;
int n, m, q, d[MAXN], h[MAXN];
int dep[MAXN], op[MAXN], cl[MAXN], id[2 * MAXN];
int lg[2 * MAXN], mn[2 * MAXN][MAXB];
vector<int> g[MAXN];
bool cmp(int u, int v) { return dep[u] < dep[v]; }
void dfs(int u, int d) {
  dep[u] = d;
  op[u] = ++m;
  id[m] = u;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    dfs(v, d + 1);
    id[++m] = u;
  }
  cl[u] = m;
}
int lca(int u, int v) {
  if (op[u] > op[v]) swap(u, v);
  int k = lg[op[v] - op[u] + 1];
  return min(mn[op[u]][k], mn[op[v] - (1 << k) + 1][k], cmp);
};
bool through(int x, int y, int v) {
  int z = lca(x, y);
  return op[z] <= op[v] && op[v] <= cl[z] &&
         (op[v] <= op[x] && op[x] <= cl[v] || op[v] <= op[y] && op[y] <= cl[v]);
}
struct Path {
  int x, y;
  Path(int u = 0, int v = 0) : x(u), y(v) {}
  Path operator+(const Path& rhs) const {
    int t[4] = {x, y, rhs.x, rhs.y};
    for (int i = 0; i < 4; i++)
      if (!t[i]) return Path();
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) {
        bool flag = 1;
        for (int k = 0; k < 4; k++)
          if (k != i && k != j && !through(t[i], t[j], t[k])) {
            flag = 0;
            break;
          }
        if (flag) return Path(t[i], t[j]);
      }
    return Path();
  }
};
struct SegmentTree {
  struct Node {
    int l, r;
    Path p;
  } tr[4 * MAXN];
  void pushup(int o) { tr[o].p = tr[(o << 1)].p + tr[(o << 1 | 1)].p; }
  void build(int o, int l, int r, int* a) {
    tr[o].l = l;
    tr[o].r = r;
    if (l == r) {
      tr[o].p = Path(a[l], a[l]);
      return;
    }
    int mid = l + r >> 1;
    build((o << 1), l, mid, a);
    build((o << 1 | 1), mid + 1, r, a);
    pushup(o);
  }
  int query(int o, Path c = Path()) {
    if (tr[o].l == tr[o].r) return tr[o].l;
    Path t = c.x ? c + tr[(o << 1)].p : tr[(o << 1)].p;
    if (t.x)
      return query((o << 1 | 1), t);
    else
      return query((o << 1), c);
  }
  void update(int o, int p, int k) {
    if (tr[o].l == tr[o].r) {
      tr[o].p = Path(k, k);
      return;
    }
    int mid = tr[o].l + tr[o].r >> 1;
    if (p <= mid)
      update((o << 1), p, k);
    else
      update((o << 1 | 1), p, k);
    pushup(o);
  }
} st;
int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]), h[d[i]] = i;
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    g[p].push_back(i);
  }
  m = lg[0] = 0;
  dfs(1, 1);
  for (int i = 1; i <= m; i++) lg[i] = lg[i - 1] + (1 << lg[i - 1] + 1 == i);
  for (int i = 1; i <= m; i++) mn[i][0] = id[i];
  for (int j = 1; 1 << j <= m; j++)
    for (int i = 1; i + (1 << j) - 1 <= m; i++)
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1], cmp);
  st.build(1, 0, n, h);
  scanf("%d", &q);
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int a, b;
      scanf("%d%d", &a, &b);
      st.update(1, d[a], b);
      st.update(1, d[b], a);
      swap(d[a], d[b]);
    } else
      printf("%d\n", st.query(1));
  }
  return 0;
}
