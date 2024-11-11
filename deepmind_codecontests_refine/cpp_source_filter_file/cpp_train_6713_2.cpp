#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, q;
int par[N], dep[N], siz[N], mxc[N], anc[N], dfn[N], dfo[N];
int Ut[N], Vt[N], Wt[N], ordt[N];
int Uq[N], Vq[N], Wq[N], ordq[N], res[N];
int F[N];
int lb[N], rb[N], lc[N], rc[N];
vector<int> B[N], C[N];
struct P {
  int l, r, v, f;
  P(int _l = 0, int _r = 0, int _v = 0, int _f = 0) {
    l = _l;
    r = _r;
    v = _v;
    f = _f;
  }
} val[N];
P rev(P a) { return P(a.r, a.l, a.v, a.f); }
P operator+(P a, P b) {
  if (!a.f && !b.f)
    return P(a.l, b.r, a.v + b.v + F[a.r + b.l], 0);
  else if (!a.f && b.f)
    return P(a.l, a.r + b.r, a.v, 0);
  else if (a.f && !b.f)
    return P(a.l + b.l, b.r, b.v, 0);
  else
    return P(a.l + b.l, a.r + b.r, 0, 1);
}
P d1() { return P(1, 1, 0, 1); }
void dfs1(int t = 1, int f = 0, int d = 0) {
  par[t] = f;
  dep[t] = d;
  siz[t] = 1;
  for (auto p : B[t])
    if (p != f) {
      dfs1(p, t, d + 1);
      siz[t] += siz[p];
      if (siz[p] > siz[mxc[t]]) mxc[t] = p;
    }
}
void dfs2(int t = 1, int p = 1) {
  static int tot = 0;
  dfo[++tot] = t;
  dfn[t] = tot;
  anc[t] = p;
  if (mxc[t]) dfs2(mxc[t], p);
  for (auto p : B[t])
    if (p != mxc[t] && p != par[t]) dfs2(p, p);
}
int build(int l, int r) {
  static int tot = 0;
  int t = ++tot;
  lb[t] = l;
  rb[t] = r;
  if (l < r) {
    lc[t] = build(l, (l + r) / 2);
    rc[t] = build((l + r) / 2 + 1, r);
    val[t] = val[lc[t]] + val[rc[t]];
  } else {
    if (dfo[l] <= n) val[t] = P(0, 0, 0, 1);
  }
  return t;
}
void modify(int t, int p) {
  if (lb[t] == rb[t])
    val[t] = P(1, 1, 0, 1);
  else {
    if (p <= rb[lc[t]])
      modify(lc[t], p);
    else
      modify(rc[t], p);
    val[t] = val[lc[t]] + val[rc[t]];
  }
}
P query(int t, int l, int r) {
  if (l <= lb[t] && rb[t] <= r) return val[t];
  if (r <= rb[lc[t]]) return query(lc[t], l, r);
  if (l >= lb[rc[t]]) return query(rc[t], l, r);
  return query(lc[t], l, r) + query(rc[t], l, r);
}
int query(int a, int b) {
  P A = P(0, 0, 0, 1), B = P(0, 0, 0, 1);
  while (1) {
    if (anc[a] != anc[b]) {
      if (dep[anc[a]] < dep[anc[b]]) swap(a, b), swap(A, B);
      A = A + query(1, dfn[anc[a]], dfn[a]);
      a = par[anc[a]];
    } else {
      if (dep[a] > dep[b]) swap(a, b), swap(A, B);
      return (P() + rev(A) + query(1, dfn[a], dfn[b]) + B + P()).v;
    }
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; ++i) scanf("%d", &F[i]);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d", &Ut[i], &Vt[i], &Wt[i]);
    B[Ut[i]].push_back(i + n);
    B[i + n].push_back(Ut[i]);
    B[Vt[i]].push_back(i + n);
    B[i + n].push_back(Vt[i]);
  }
  for (int i = 1; i <= q; ++i) scanf("%d%d%d", &Uq[i], &Vq[i], &Wq[i]);
  for (int i = 1; i < n; ++i) ordt[i] = i;
  sort(ordt + 1, ordt + n, [](int a, int b) { return Wt[a] > Wt[b]; });
  for (int i = 1; i <= q; ++i) ordq[i] = i;
  sort(ordq + 1, ordq + q + 1, [](int a, int b) { return Wq[a] > Wq[b]; });
  dfs1();
  dfs2();
  build(1, n + n - 1);
  for (int i = 1, j = 1; i <= q; ++i) {
    while (j < n && Wt[ordt[j]] >= Wq[ordq[i]]) {
      modify(1, dfn[ordt[j] + n]);
      j++;
    }
    res[ordq[i]] = query(Uq[ordq[i]], Vq[ordq[i]]);
  }
  for (int i = 1; i <= q; ++i) printf("%d\n", res[i]);
}
