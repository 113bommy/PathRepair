#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}
const int N = 400000 + 10;
int n, rt[N];
struct Segment_Tree {
  int tot;
  int ls[N * 30], rs[N * 30];
  Segment_Tree() { tot = 0; }
  inline void modify(int& o, int l, int r, int p) {
    if (!o) o = ++tot;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (p <= mid)
      modify(ls[o], l, mid, p);
    else
      modify(rs[o], mid + 1, r, p);
  }
  inline int query(int o, int l, int r, int ql, int qr) {
    if (!o) return 0;
    if (ql <= l && r <= qr) return 1;
    int mid = (l + r) >> 1, res = 0;
    if (ql <= mid) res |= query(ls[o], l, mid, ql, qr);
    if (qr > mid) res |= query(rs[o], mid + 1, r, ql, qr);
    return res;
  }
  inline int merge(int x, int y) {
    if (!x || !y) return x + y;
    int t = ++tot;
    ls[t] = merge(ls[x], ls[y]), rs[t] = merge(rs[x], rs[y]);
    return t;
  }
} T;
struct Suffix_Automaton {
  int last, tot;
  int ch[N][26], fa[N], len[N], pos[N];
  Suffix_Automaton() { last = tot = 1; }
  inline void extend(int c, int id) {
    int p = last, np = ++tot;
    last = np, len[np] = len[p] + 1, pos[np] = id;
    for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
    if (!p)
      fa[np] = 1;
    else {
      int q = ch[p][c];
      if (len[p] + 1 == len[q])
        fa[np] = q;
      else {
        int nq = ++tot;
        len[nq] = len[p] + 1;
        memcpy(ch[nq], ch[q], sizeof(ch[q]));
        pos[nq] = pos[q], fa[nq] = fa[q], fa[q] = fa[np] = nq;
        for (; ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
      }
    }
    T.modify(rt[last], 1, n, id);
  }
} S;
char s[N];
int o[N], p[N];
int f[N], anc[N];
int main() {
  n = read();
  scanf("%s", s + 1);
  for (register int i = 1; i <= n; ++i) S.extend(s[i] - 'a', i);
  for (register int i = 1; i <= S.tot; ++i) ++o[S.len[i]];
  for (register int i = 1; i <= n; ++i) o[i] += o[i - 1];
  for (register int i = S.tot; i; --i) p[o[S.len[i]]--] = i;
  for (register int i = S.tot; i > 1; --i) {
    int u = p[i];
    rt[S.fa[u]] = T.merge(rt[S.fa[u]], rt[u]);
  }
  int ans = 1;
  for (register int i = 2; i <= S.tot; ++i) {
    int u = p[i], fa = S.fa[u];
    if (fa == 1) {
      f[u] = 1, anc[u] = u;
      continue;
    }
    int tmp = T.query(rt[anc[fa]], 1, n, S.pos[u] - S.len[u] + S.len[anc[fa]],
                      S.pos[u] - 1);
    if (tmp)
      f[u] = f[fa] + 1, anc[u] = u;
    else
      f[u] = f[fa], anc[u] = anc[fa];
    ans = max(ans, f[u]);
  }
  printf("%d\n", ans);
  return 0;
}
