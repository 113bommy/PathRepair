#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int d[N], dep[N];
int head[N], tot, n, L, R, q[N];
int fa[N], fav[N], hson[N], S[N];
int st[N], rt[N], ans0, ans1, flg;
struct edge {
  int to, next, v;
} e[N * 2];
int ls[N * 4], rs[N * 4], nd;
pair<int, int> t[N * 4];
void build(int &k, int l, int r) {
  k = ++nd;
  t[k] = pair<int, int>(-(1 << 30), -(1 << 30));
  if (l == r) return;
  int mid = (l + r) / 2;
  build(ls[k], l, mid);
  build(rs[k], mid + 1, r);
}
void change(int k, int l, int r, int p, pair<int, int> v) {
  t[k] = max(t[k], v);
  if (l == r) return;
  int mid = (l + r) / 2;
  if (p <= mid)
    change(ls[k], l, mid, p, v);
  else
    change(rs[k], mid + 1, r, p, v);
}
pair<int, int> ask(int k, int l, int r, int x, int y) {
  if (l == x && r == y) return t[k];
  int mid = (l + r) / 2;
  if (y <= mid) return ask(ls[k], l, mid, x, y);
  if (x > mid) return ask(rs[k], mid + 1, r, x, y);
  return max(ask(ls[k], l, mid, x, mid), ask(rs[k], mid + 1, r, mid + 1, y));
}
void add(int x, int y, int v) {
  e[++tot] = (edge){y, head[x], v};
  head[x] = tot;
}
void dfs1(int x) {
  d[x] = 0;
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa[x]) {
      dep[e[i].to] = dep[x] + 1;
      fa[e[i].to] = x;
      fav[e[i].to] = e[i].v;
      dfs1(e[i].to);
      if (d[e[i].to] + 1 > d[x]) {
        hson[x] = e[i].to;
        d[x] = d[e[i].to] + 1;
      }
    }
}
void check(int x, int v) {
  if (hson[fa[x]] != x) {
    st[x] = dep[x];
    build(rt[x], dep[x], dep[x] + d[x]);
  }
  if (hson[x]) {
    st[hson[x]] = st[x];
    S[hson[x]] = S[x] + (fav[hson[x]] >= v ? 1 : -1);
    rt[hson[x]] = rt[x];
    check(hson[x], v);
  }
  if (d[x] >= L) {
    pair<int, int> v = ask(rt[x], st[x], dep[x] + d[x], dep[x] + L,
                           min(dep[x] + R, dep[x] + d[x]));
    if (v.first + S[x] - 2 * S[x] >= 0) flg = 1, ans0 = x, ans1 = v.second;
  }
  change(rt[x], st[x], dep[x] + d[x], dep[x], pair<int, int>(S[x], x));
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa[x] && e[i].to != hson[x]) {
      S[e[i].to] = S[x] + (fav[e[i].to] >= v ? 1 : -1);
      check(e[i].to, v);
      for (int j = (int)(1); j <= (int)(min(R, d[e[i].to] + 1)); j++) {
        pair<int, int> v =
            ask(rt[e[i].to], dep[e[i].to], dep[e[i].to] + d[e[i].to],
                dep[x] + j, dep[x] + j);
        int vl = dep[x] + max(0, L - j), vr = dep[x] + min(0, R - j);
        if (vl <= vr) {
          pair<int, int> vv = ask(rt[x], st[x], dep[x] + d[x], vl, vr);
          if (vv.first + v.first - 2 * S[x] >= 0)
            flg = 1, ans0 = v.second, ans1 = vv.second;
        }
      }
      for (int j = (int)(1); j <= (int)(min(R, d[e[i].to] + 1)); j++) {
        pair<int, int> v =
            ask(rt[e[i].to], dep[e[i].to], dep[e[i].to] + d[e[i].to],
                dep[x] + j, dep[x] + j);
        change(rt[x], st[x], dep[x] + d[x], dep[x] + j, v);
      }
    }
}
bool check(int v) {
  for (; nd; ls[nd] = rs[nd] = 0, --nd)
    ;
  flg = 0;
  check(1, v);
  return flg;
}
int main() {
  scanf("%d%d%d", &n, &L, &R);
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    add(x, y, v);
    add(y, x, v);
    q[++*q] = v;
  }
  dfs1(1);
  sort(q + 1, q + n);
  int l = 1, r = n - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(q[mid]))
      l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d %d\n", ans0, ans1);
}
