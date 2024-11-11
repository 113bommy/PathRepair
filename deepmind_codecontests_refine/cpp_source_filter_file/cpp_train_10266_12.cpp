#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int n, q, st[maxn], ed[maxn], cnt, u[maxn << 1], v[maxn << 1];
long long root[maxn], w[maxn << 1];
struct node {
  int l, r;
  long long lazy, mmax;
  void update(long long val) {
    mmax += val;
    lazy += val;
  }
} seg[maxn << 2];
inline void pushup(int x) {
  seg[x].mmax = min(seg[x << 1].mmax, seg[x << 1 | 1].mmax);
}
inline void pushdown(int x) {
  long long lz = seg[x].lazy;
  if (lz) {
    seg[x].lazy = 0;
    seg[x << 1].update(lz);
    seg[x << 1 | 1].update(lz);
  }
}
void build(int x, int l, int r) {
  seg[x].l = l, seg[x].r = r, seg[x].mmax = seg[x].lazy = 0;
  if (l == r) return;
  int m = (l + r) >> 1;
  build(x << 1, l, m);
  build(x << 1 | 1, m + 1, r);
  pushup(x);
}
void update(int x, int l, int r, long long val) {
  int L = seg[x].l, R = seg[x].r;
  if (l <= L && r >= R) {
    seg[x].update(val);
    return;
  }
  pushdown(x);
  int m = (L + R) >> 1;
  if (m >= l) update(x << 1, l, r, val);
  if (m < r) update(x << 1 | 1, l, r, val);
  pushup(x);
}
long long query(int x, int l, int r) {
  int L = seg[x].l, R = seg[x].r;
  if (l <= L && r >= R) return seg[x].mmax;
  pushdown(x);
  int m = (L + R) >> 1;
  long long ret = inf;
  if (m >= l) ret = min(ret, query(x << 1, l, r));
  if (m < r) ret = min(ret, query(x << 1 | 1, l, r));
  pushup(x);
  return ret;
}
vector<int> G[maxn];
void dfs(int u) {
  st[u] = ++cnt;
  for (int i = 0; i < (int)G[u].size(); ++i) dfs(G[u][i]);
  ed[u] = cnt;
}
int main() {
  scanf("%d%d", &n, &q);
  cnt = 0;
  build(1, 1, n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d%d%I64d", &u[i], &v[i], &w[i]);
    G[u[i]].push_back(v[i]);
  }
  dfs(1);
  for (int i = n; i <= 2 * n - 2; ++i) {
    scanf("%d%d%I64d", &u[i], &v[i], &w[i]);
    root[u[i]] = w[i];
    update(1, st[u[i]], st[u[i]], w[i]);
  }
  for (int i = 1; i <= n - 1; ++i) update(1, st[v[i]], ed[v[i]], w[i]);
  while (q--) {
    int ty, a;
    long long b;
    scanf("%d%d%I64d", &ty, &a, &b);
    if (ty == 1) {
      if (a <= n - 1) {
        update(1, st[v[a]], ed[v[a]], b - w[a]);
        w[a] = b;
      } else {
        update(1, st[u[a]], st[u[a]], b - root[u[a]]);
        root[u[a]] = b;
      }
    } else {
      if (st[a] <= st[b] && ed[a] >= ed[b]) {
        printf("%I64d\n", query(1, st[b], st[b]) - query(1, st[a], st[a]) -
                              root[b] + root[a]);
      } else {
        printf("%I64d\n", query(1, st[b], st[b]) - root[b] + root[a] -
                              query(1, st[a], ed[a]) + query(1, st[a], ed[a]));
      }
    }
  }
  return 0;
}
