#include <bits/stdc++.h>
const int MAXN = 1e5 + 5;
const int MAXM = 5e5 + 5;
const int MAXL = 16;
struct Node {
  int mx, ps;
  Node(int mx = 0, int ps = -1) : mx(mx), ps(ps) {}
  inline Node operator+(const Node &t) const {
    return mx >= t.mx ? (*this) : t;
  }
} sm[MAXN << 5];
int lc[MAXN << 5], rc[MAXN << 5], rt[MAXN], cnt;
inline void update(int &x, int l, int r, int p) {
  if (!x) x = ++cnt;
  if (l == r) {
    ++sm[x].mx;
    sm[x].ps = l;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    update(lc[x], l, mid, p);
  else
    update(rc[x], mid + 1, r, p);
  sm[x] = sm[lc[x]] + sm[rc[x]];
}
inline int merge(int x, int y, int l, int r) {
  if (!x || !y) return x | y;
  int v = ++cnt, mid = (l + r) >> 1;
  if (l == r) {
    sm[v] = Node(sm[x].mx + sm[y].mx, sm[x].ps);
    return v;
  }
  lc[v] = merge(lc[x], lc[y], l, mid);
  rc[v] = merge(rc[x], rc[y], mid + 1, r);
  sm[v] = sm[lc[v]] + sm[rc[v]];
  return v;
}
inline Node query(int x, int l, int r, int L, int R) {
  if (!x) return Node(-1, -1);
  if (l == L && r == R) return sm[x];
  int mid = (l + r) >> 1;
  if (R <= mid)
    return query(lc[x], l, mid, L, R);
  else if (L > mid)
    return query(rc[x], mid + 1, r, L, R);
  else
    return query(lc[x], l, mid, L, mid) + query(rc[x], mid + 1, r, mid + 1, R);
}
char s[MAXM], str[MAXN];
int n;
int ch[MAXN][26], fail[MAXN], len[MAXN], tot = 1;
inline int work(int p, int c) {
  int q = ch[p][c], nq = ++tot;
  for (int i = 0; i <= 25; ++i) ch[nq][i] = ch[q][i];
  fail[nq] = fail[q];
  len[nq] = len[p] + 1;
  fail[q] = nq;
  for (; p && ch[p][c] == q; p = fail[p]) ch[p][c] = nq;
  return nq;
}
inline int insert(int p, int c) {
  int q = ch[p][c];
  if (q) {
    if (len[q] == len[p] + 1) return q;
    return work(p, c);
  }
  int np = ++tot;
  len[np] = len[p] + 1;
  for (; p && !ch[p][c]; p = fail[p]) ch[p][c] = np;
  if (!p)
    fail[np] = 1;
  else {
    q = ch[p][c];
    if (len[q] == len[p] + 1)
      fail[np] = q;
    else
      fail[np] = work(p, c);
  }
  return np;
}
int t[MAXN], sa[MAXN];
int f[MAXN][MAXL + 1];
int ps[MAXM], l[MAXM];
int main() {
  scanf("%s", s + 1);
  scanf("%d", &n);
  for (int c = 1; c <= n; ++c) {
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    int p = 1;
    for (int i = 1; i <= len; ++i) {
      p = insert(p, str[i] - 'a');
      update(rt[p], 1, n, c);
    }
  }
  for (int i = 1; i <= tot; ++i) ++t[len[i]];
  for (int i = 1; i <= tot; ++i) t[i] += t[i - 1];
  for (int i = 1; i <= tot; ++i) sa[t[len[i]]--] = i;
  for (int c = 1; c <= tot; ++c) {
    int v = sa[c];
    f[v][0] = fail[v];
    for (int i = 1; i <= MAXL; ++i) f[v][i] = f[f[v][i - 1]][i - 1];
  }
  for (int i = tot; i >= 1; --i)
    rt[fail[sa[i]]] = merge(rt[fail[sa[i]]], rt[sa[i]], 1, n);
  int m = strlen(s + 1);
  int v = 1, len = 0;
  for (int i = 1; i <= m; ++i) {
    int o = s[i] - 'a';
    if (ch[v][o])
      v = ch[v][o], ++len;
    else {
      while (v && !ch[v][o]) v = fail[v];
      if (!v)
        v = 1, len = 0;
      else
        len = ::len[v] + 1, v = ch[v][o];
    }
    ps[i] = v;
    l[i] = len;
  }
  int q;
  scanf("%d", &q);
  for (int c = 1; c <= q; ++c) {
    int l, r, pl, pr;
    scanf("%d%d%d%d", &l, &r, &pl, &pr);
    if (::l[pr] < pr - pl + 1) {
      printf("%d 0\n", l);
      continue;
    }
    int v = ps[pr];
    for (int i = MAXL; i >= 0; --i) {
      if (::len[f[v][i]] >= pr - pl + 1) v = f[v][i];
    }
    Node res = query(rt[v], 1, n, l, r);
    if (res.ps == -1) res = Node(0, l);
    printf("%d %d\n", res.ps, res.mx);
  }
  return 0;
}
