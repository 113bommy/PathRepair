#include <bits/stdc++.h>
using namespace std;
const int maxn = 100025;
int n, m, i, j, t, k, s, a[maxn << 1], N, head[maxn], dfn[maxn << 1], low[maxn],
    ti;
int stk[maxn], tpp, Head_yf[maxn << 1], b[maxn << 1];
int siz[maxn << 1], son[maxn << 1], tp[maxn << 1], fa[maxn << 1],
    dep[maxn << 1];
int seg[maxn << 3], nowfang, dn;
multiset<int> S[maxn << 1];
struct Edge {
  int nxt, aim;
} edge[maxn * 6];
inline void add_edge(int x, int y) {
  edge[++N] = (Edge){head[x], y};
  head[x] = N;
}
inline void yf_add_edge(int x, int y) {
  edge[++N] = (Edge){Head_yf[x], y};
  Head_yf[x] = N;
}
inline int get_mn(int x) { return *S[x].begin(); }
void tarjan(int x, int y) {
  low[x] = dfn[x] = ++ti;
  stk[++tpp] = x;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int des = edge[i].aim;
    if (des == y) continue;
    if (!dfn[des]) {
      tarjan(des, x), low[x] = min(low[x], low[des]);
      if (low[des] >= dfn[x]) {
        ++nowfang;
        a[nowfang] = (1e9) + 7;
        while (stk[tpp] != des) {
          yf_add_edge(stk[tpp], nowfang);
          yf_add_edge(nowfang, stk[tpp]);
          a[nowfang] = min(a[nowfang], a[stk[tpp]]);
          --tpp;
        }
        --tpp;
        yf_add_edge(x, nowfang);
        yf_add_edge(nowfang, x);
        yf_add_edge(des, nowfang);
        yf_add_edge(nowfang, des);
        a[nowfang] = min(a[nowfang], min(a[x], a[des]));
      }
    } else
      low[x] = min(low[x], dfn[des]);
  }
}
void dfs1(int x, int y) {
  siz[x] = 1;
  dep[x] = dep[y] + 1;
  for (int i = Head_yf[x]; i; i = edge[i].nxt) {
    int des = edge[i].aim;
    if (des == y) continue;
    dfs1(des, x);
    fa[des] = x;
    if (x > n) S[x].insert(a[des]);
    siz[x] += siz[des];
    if (siz[des] > siz[son[x]]) son[x] = des;
  }
}
void dfs2(int x, int y) {
  dfn[x] = ++ti;
  b[ti] = x;
  if (son[x]) {
    tp[son[x]] = tp[x];
    dfs2(son[x], x);
  }
  for (int i = Head_yf[x]; i; i = edge[i].nxt) {
    int des = edge[i].aim;
    if (des == y || des == son[x]) continue;
    tp[des] = des;
    dfs2(des, x);
  }
}
void build(int rt, int l, int r) {
  if (l == r) {
    if (b[l] <= n)
      seg[rt] = a[b[l]];
    else
      seg[rt] = get_mn(b[l]);
    return;
  }
  int mid = (l + r) / 2;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  seg[rt] = min(seg[rt << 1], seg[rt << 1 | 1]);
}
void upd(int rt, int l, int r, int pl, int x) {
  if (l == r) {
    seg[rt] = x;
    return;
  }
  int mid = (l + r) / 2;
  if (pl <= mid)
    upd(rt << 1, l, mid, pl, x);
  else
    upd(rt << 1 | 1, mid + 1, r, pl, x);
  seg[rt] = min(seg[rt << 1], seg[rt << 1 | 1]);
}
int query(int rt, int l, int r, int L, int R) {
  if (l >= L && r <= R) return seg[rt];
  int mid = (l + r) / 2;
  if (R <= mid) return query(rt << 1, l, mid, L, R);
  if (L > mid) return query(rt << 1 | 1, mid + 1, r, L, R);
  return min(query(rt << 1, l, mid, L, R),
             query(rt << 1 | 1, mid + 1, r, L, R));
}
int Query(int x, int y) {
  int ret = (1e9) + 16;
  while (1) {
    if (tp[x] == tp[y]) {
      if (dep[x] > dep[y]) swap(x, y);
      ret =
          min(ret, query(1, 1, dn, (x == tp[x] || x <= n ? dfn[x] : dfn[x] - 1),
                         dfn[y]));
      if (x == tp[x] && x > n) ret = min(ret, a[fa[x]]);
      return ret;
    }
    if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
    ret = min(ret, query(1, 1, dn, dfn[tp[x]], dfn[x]));
    x = fa[tp[x]];
  }
}
int main() {
  int T;
  scanf("%d%d%d", &n, &m, &T);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (i = 1; i <= m; ++i) {
    scanf("%d%d", &t, &k);
    add_edge(t, k);
    add_edge(k, t);
  }
  nowfang = n;
  tarjan(1, 0);
  dn = nowfang;
  dfs1(1, 0);
  ti = 0;
  tp[1] = 1;
  fa[1] = 1;
  dfs2(1, 0);
  build(1, 1, dn);
  while (T--) {
    char op[2];
    int x, y;
    scanf("%s", op);
    scanf("%d%d", &x, &y);
    if (op[0] == 'C') {
      upd(1, 1, dn, dfn[x], y);
      if (fa[x] > n) {
        S[fa[x]].erase(S[fa[x]].find(a[x]));
        S[fa[x]].insert(y);
        upd(1, 1, dn, dfn[fa[x]], get_mn(fa[x]));
      }
      a[x] = y;
    } else {
      printf("%d\n", Query(x, y));
    }
  }
  return 0;
}
