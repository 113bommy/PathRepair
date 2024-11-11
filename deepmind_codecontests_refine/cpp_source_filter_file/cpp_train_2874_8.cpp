#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005, N = 200000;
const int D = 1e9 + 7;
int n, ans, L, R;
int qpow(int x, int y = D - 2) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % D;
    x = 1ll * x * x % D;
    y >>= 1;
  }
  return ret;
}
struct mes {
  int v, c;
  mes() { v = 1, c = 0; }
  mes(int vv, int cc) { v = vv, c = cc; }
  void clear() { v = 1, c = 0; }
} val[MAXN << 4];
mes operator*(const mes &aa, const mes &bb) {
  return mes(1ll * aa.v * bb.v % D, aa.c + bb.c);
}
void modify(int p, int l, int r, int x, mes v) {
  if (l == r) return (void)(val[p] = val[p] * v);
  int mid = (l + r) >> 1;
  if (x <= mid)
    modify(p << 1, l, mid, x, v);
  else
    modify(p << 1 | 1, mid + 1, r, x, v);
  val[p] = val[p << 1] * val[p << 1 | 1];
}
mes query(int p, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) return val[p];
  int mid = (l + r) >> 1;
  if (qr <= mid)
    return query(p << 1, l, mid, ql, qr);
  else if (ql > mid)
    return query(p << 1 | 1, mid + 1, r, ql, qr);
  else
    return query(p << 1, l, mid, ql, mid) *
           query(p << 1 | 1, mid + 1, r, mid + 1, qr);
}
void clear(int p, int l, int r, int x) {
  val[p].clear();
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (x <= mid)
    clear(p << 1, l, mid, x);
  else
    clear(p << 1 | 1, mid + 1, r, x);
}
void modify(int x, int v) { modify(1, L, R, x + N, mes(v, 1)); }
mes askp(int x) {
  if (x + N >= L)
    return query(1, L, R, L, x + N);
  else
    return mes(1, 0);
}
void clear(int x) { clear(1, L, R, x + N); }
struct node {
  int x, v, c;
  node() {}
  node(int xx, int vv, int cc) { x = xx, v = vv, c = cc; }
};
vector<node> ver[MAXN];
int rt, all;
int siz[MAXN], mxp[MAXN];
bool del[MAXN];
void groot(int u, int fa) {
  siz[u] = 1, mxp[u] = 0;
  for (node v : ver[u])
    if (v.x != fa && !del[v.x]) {
      groot(v.x, u);
      siz[u] += siz[v.x];
      mxp[u] = max(mxp[u], siz[v.x]);
    }
  mxp[u] = max(mxp[u], all - siz[u]);
  if (mxp[u] < mxp[rt]) rt = u;
}
struct sta {
  int c0, c1, v;
  sta() {}
  sta(int cc0, int cc1, int vv) { c0 = cc0, c1 = cc1, v = vv; }
};
vector<sta> s[MAXN];
void dfs(int u, int fa, int id, int c0, int c1, int vv) {
  s[id].push_back(sta(c0, c1, vv));
  for (node v : ver[u])
    if (v.x != fa && !del[v.x])
      dfs(v.x, u, id, c0 + (v.c == 0), c1 + (v.c == 1), 1ll * vv * v.v % D);
}
void calc(int u) {
  for (node v : ver[u])
    if (!del[v.x]) dfs(v.x, u, v.x, v.c == 0, v.c == 1, v.v);
  int v0 = 1, v1 = 1, v2 = 1;
  int cnt = 1, pre = 1;
  for (node v : ver[u])
    if (!del[v.x]) {
      int delta = 1;
      for (sta x : s[v.x]) {
        v0 = 1ll * v0 * pre % D * qpow(x.v, cnt) % D;
        delta = 1ll * delta * x.v;
      }
      pre = 1ll * pre * delta % D;
      cnt += s[v.x].size();
    }
  modify(0, 1);
  for (node v : ver[u])
    if (!del[v.x]) {
      for (sta x : s[v.x]) {
        mes y = askp(x.c1 - 2 * x.c0 - 1);
        v1 = 1ll * v1 * y.v % D * qpow(x.v, y.c) % D;
      }
      for (sta x : s[v.x]) modify(2 * x.c0 - x.c1, x.v);
    }
  clear(0);
  for (node v : ver[u])
    if (!del[v.x])
      for (sta x : s[v.x]) clear(2 * x.c0 - x.c1);
  modify(0, 1);
  for (node v : ver[u])
    if (!del[v.x]) {
      for (sta x : s[v.x]) {
        mes y = askp(x.c0 - 2 * x.c1 - 1);
        v1 = 1ll * v1 * y.v % D * qpow(x.v, y.c) % D;
      }
      for (sta x : s[v.x]) modify(2 * x.c1 - x.c0, x.v);
    }
  clear(0);
  for (node v : ver[u])
    if (!del[v.x])
      for (sta x : s[v.x]) clear(2 * x.c1 - x.c0);
  for (node v : ver[u])
    if (!del[v.x]) s[v.x].clear();
  int new_val = 1ll * v0 * qpow(v1, D - 2) % D * qpow(v2, D - 2) % D;
  ans = 1ll * ans * new_val % D;
}
void solve(int u) {
  del[u] = 1;
  calc(u);
  for (node v : ver[u])
    if (!del[v.x]) {
      mxp[rt = 0] = all = siz[v.x];
      groot(v.x, u);
      solve(rt);
    }
}
int main() {
  scanf("%d", &n);
  L = N - 2 * n, R = N + 2 * n;
  ans = 1;
  for (int i = 1; i < n; i++) {
    int x, y, v, c;
    scanf("%d%d%d%d", &x, &y, &v, &c);
    ver[x].push_back(node(y, v, c));
    ver[y].push_back(node(x, v, c));
  }
  mxp[rt = 0] = all = n;
  groot(1, 0);
  solve(rt);
  printf("%d\n", ans);
  return 0;
}
