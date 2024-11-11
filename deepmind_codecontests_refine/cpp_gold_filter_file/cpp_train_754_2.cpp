#include <bits/stdc++.h>
const int N = 500005;
int ls[N], rs[N], n, m, Q, a[N], cnt, f[N], p[N], q[N], opt[N], tg[N];
int ans, ID, in[N], out[N], dfn[N], idn;
int find(int x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx == fy) return;
  cnt++;
  f[cnt] = cnt;
  f[fx] = f[fy] = cnt;
  ls[cnt] = fx, rs[cnt] = fy;
}
struct Edge {
  int x, y;
} e[N];
void dfs(int x) {
  in[x] = ++idn;
  dfn[idn] = x;
  if (ls[x]) dfs(ls[x]);
  if (rs[x]) dfs(rs[x]);
  out[x] = idn;
}
struct SGT {
  int t[N << 2], id[N << 2];
  void pushup(int k) {
    if (t[k << 1] > t[k << 1 | 1])
      id[k] = id[k << 1], t[k] = t[k << 1];
    else
      id[k] = id[k << 1 | 1], t[k] = t[k << 1 | 1];
  }
  void build(int k, int L, int R) {
    if (L == R) {
      t[k] = a[dfn[L]];
      id[k] = L;
      return;
    }
    int mid = (L + R) >> 1;
    build(k << 1, L, mid);
    build(k << 1 | 1, mid + 1, R);
    pushup(k);
  }
  void modify(int k, int L, int R, int x) {
    if (L == R) return void(t[k] = 0);
    int mid = (L + R) >> 1;
    if (x <= mid)
      modify(k << 1, L, mid, x);
    else
      modify(k << 1 | 1, mid + 1, R, x);
    pushup(k);
  }
  void query(int k, int L, int R, int l, int r) {
    if (L == l && R == r) {
      if (t[k] > ans) ans = t[k], ID = id[k];
      return;
    }
    int mid = (L + R) >> 1;
    if (r <= mid)
      query(k << 1, L, mid, l, r);
    else if (l > mid)
      query(k << 1 | 1, mid + 1, R, l, r);
    else {
      query(k << 1, L, mid, l, mid);
      query(k << 1 | 1, mid + 1, R, mid + 1, r);
    }
  }
} T;
int main() {
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%d%d", &e[i].x, &e[i].y);
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d", &opt[i], &q[i]);
    if (opt[i] == 2) tg[q[i]] = 1;
  }
  cnt = n;
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++)
    if (!tg[i]) merge(e[i].x, e[i].y);
  for (int i = Q; i >= 1; i--)
    if (opt[i] == 1)
      p[i] = find(q[i]);
    else
      merge(e[q[i]].x, e[q[i]].y);
  for (int i = cnt; i >= 1; i--)
    if (!in[i]) dfs(i);
  T.build(1, 1, cnt);
  for (int i = 1; i <= Q; i++)
    if (opt[i] == 1) {
      ans = 0;
      T.query(1, 1, cnt, in[p[i]], out[p[i]]);
      T.modify(1, 1, cnt, ID);
      printf("%d\n", ans);
    }
}
