#include <bits/stdc++.h>
using namespace std;
int n, m, q, edge_number;
int head[200010];
long long a[200010], b[200010], sum[200010];
struct Node {
  int l, r;
  long long minn, tag;
} t[200010 << 2];
struct Edge {
  int nxt, to;
  long long dis;
} edge[200010 << 1];
inline void add(int from, int to, long long dis) {
  edge[++edge_number].nxt = head[from];
  edge[edge_number].to = to;
  edge[edge_number].dis = dis;
  head[from] = edge_number;
}
inline int ls(int x) { return x << 1; }
inline int rs(int x) { return x << 1 | 1; }
inline void push_up(int x) { t[x].minn = min(t[ls(x)].minn, t[rs(x)].minn); }
inline void solve(int x, long long k) {
  t[x].tag += k;
  t[x].minn += k;
}
inline void push_down(int x) {
  if (t[x].tag) {
    solve(ls(x), t[x].tag);
    solve(rs(x), t[x].tag);
    t[x].tag = 0;
  }
}
inline void build(int x, int l, int r, int op) {
  t[x].l = l, t[x].r = r;
  if (l == r) {
    if (op == 0)
      t[x].minn = b[l];
    else
      t[x].minn = sum[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(ls(x), l, mid, op);
  build(rs(x), mid + 1, r, op);
  push_up(x);
}
inline void build2(int x, int l, int r) {
  t[x].l = l, t[x].r = r;
  if (l == r) {
    t[x].minn = sum[l];
    return;
  }
  int mid = (l + r) >> 1;
  build2(ls(x), l, mid);
  build2(rs(x), mid + 1, r);
  push_up(x);
}
inline void update(int x, int ll, int rr, long long k) {
  int l = t[x].l, r = t[x].r;
  if (ll <= l && r <= rr) {
    solve(x, k);
    return;
  }
  int mid = (l + r) >> 1;
  push_down(x);
  if (ll <= mid) update(ls(x), ll, rr, k);
  if (mid < rr) update(rs(x), ll, rr, k);
  push_up(x);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i < n; i++) scanf("%I64d%I64d", &a[i], &b[i]);
  for (int i = 1; i <= m; i++) {
    int u, v;
    long long w;
    scanf("%d%d%I64d", &u, &v, &w);
    add(u, v, w);
  }
  build(1, 0, n - 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = head[i]; j; j = edge[j].nxt) {
      int v = edge[j].to;
      update(1, 0, v - 1, edge[j].dis);
    }
    sum[i] = a[i] + t[1].minn;
  }
  memset(t, 0, sizeof(t));
  build(1, 1, n, 1);
  printf("%I64d\n", t[1].minn);
  for (int i = 1; i <= q; i++) {
    int u;
    long long k;
    scanf("%d%I64d", &u, &k);
    update(1, u, u, k - a[u]);
    a[u] = k;
    printf("%I64d\n", t[1].minn);
  }
  return 0;
}
