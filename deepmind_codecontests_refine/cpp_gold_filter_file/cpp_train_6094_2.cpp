#include <bits/stdc++.h>
const int MN = 50000 + 5, ME = 1e7, MQ = 500000 + 5, LGS = 21;
using namespace std;
template <typename T>
inline T &IN(T &in) {
  in = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) in = in * 10 + c - '0', c = getchar();
  return in *= f;
}
int n, m, Q;
char c[MQ], s[MQ];
int rt[MN * 2];
pair<int, int> ans[MQ];
struct segtree {
  int S;
  struct node {
    int l, r, mx, pos;
  } t[ME];
  void upd(int rt) {
    t[rt].pos =
        t[t[rt].l].mx >= t[t[rt].r].mx ? t[t[rt].l].pos : t[t[rt].r].pos;
    t[rt].mx = max(t[t[rt].l].mx, t[t[rt].r].mx);
  }
  void mod(int &rt, int l, int r, int p) {
    if (!rt) rt = ++S;
    if (l == r) return t[rt].mx++, t[rt].pos = l, void();
    int mid = l + r >> 1;
    if (p <= mid)
      mod(t[rt].l, l, mid, p);
    else
      mod(t[rt].r, mid + 1, r, p);
    upd(rt);
  }
  int merge(int u, int v, int l, int r) {
    if (!u || !v) return u + v;
    int mid = l + r >> 1;
    if (l == r) return t[u].mx += t[v].mx, u;
    t[u].l = merge(t[u].l, t[v].l, l, mid);
    t[u].r = merge(t[u].r, t[v].r, mid + 1, r);
    upd(u);
    return u;
  }
  pair<int, int> query(int rt, int l, int r, int L, int R) {
    int mid = l + r >> 1;
    if (!rt || r < L || R < l) return pair<int, int>(0, -L);
    if (L <= l && r <= R) return pair<int, int>(t[rt].mx, -t[rt].pos);
    return max(query(t[rt].l, l, mid, L, R), query(t[rt].r, mid + 1, r, L, R));
  }
} seg;
struct data {
  int l, r, L, R, id;
  bool operator<(const data &x) const { return r < x.r; }
} q[MQ];
int t[MN * 2][26], fa[MN * 2][LGS + 1], len[MN * 2], las = 1, S = 1;
int nxt[ME], to[ME], h[MN * 2], _h[MN * 2], cnt;
void add(int u, int v, int *h) { to[cnt] = v, nxt[cnt] = h[u], h[u] = cnt++; }
void ins(char c) {
  int p = las, np = ++S;
  len[las = np] = len[p] + 1;
  while (p && !t[p][c]) t[p][c] = np, p = fa[p][0];
  if (!p) return fa[np][0] = 1, void();
  int q = t[p][c];
  if (len[q] == len[p] + 1) return fa[np][0] = q, void();
  int nq = ++S;
  memcpy(t[nq], t[q], sizeof t[nq]);
  fa[nq][0] = fa[q][0];
  len[nq] = len[p] + 1;
  fa[q][0] = fa[np][0] = nq;
  while (p && t[p][c] == q) t[p][c] = nq, p = fa[p][0];
}
void dfs(int u) {
  for (int e = h[u], v = to[e]; ~e; e = nxt[e], v = to[e])
    dfs(v), rt[u] = seg.merge(rt[u], rt[v], 1, m);
  for (int e = _h[u], v = to[e]; ~e; e = nxt[e], v = to[e])
    ans[q[v].id] = seg.query(rt[u], 1, m, q[v].L, q[v].R);
}
void input() {
  scanf("%s", c + 1);
  n = strlen(c + 1);
  IN(m);
  for (int i = 1; i <= m; ++i) {
    las = 1;
    scanf("%s", s + 1);
    for (int j = 1, len = strlen(s + 1); j <= len; ++j)
      ins(s[j] - 'a'), seg.mod(rt[las], 1, m, i);
  }
  IN(Q);
  memset(h, -1, sizeof h), memset(_h, -1, sizeof _h);
  for (int j = 1; j <= LGS; ++j)
    for (int i = 1; i <= S; ++i) fa[i][j] = fa[fa[i][j - 1]][j - 1];
  for (int i = 1; i <= Q; ++i)
    IN(q[i].L), IN(q[i].R), IN(q[i].l), IN(q[i].r), q[i].id = i;
  sort(q + 1, q + Q + 1);
  for (int i = 1, p = 1, j = 1, l = 0; i <= n; ++i) {
    while (p && !t[p][c[i] - 'a']) p = fa[p][0], l = len[p];
    if (!p)
      p = 1, l = 0;
    else
      p = t[p][c[i] - 'a'], l++;
    while (j <= Q && q[j].r == i) {
      int L = q[j].r - q[j].l + 1, u = p;
      if (l < L) {
        ans[q[j].id] = pair<int, int>(0, -q[j].L), j++;
        continue;
      }
      for (int k = LGS; k >= 0; --k)
        if (L <= len[fa[u][k]] && fa[u][k]) u = fa[u][k];
      add(u, j, _h);
      j++;
    }
  }
  for (int i = 2; i <= S; ++i) add(fa[i][0], i, h);
  dfs(1);
  for (int i = 1; i <= Q; ++i) printf("%d %d\n", -ans[i].second, ans[i].first);
}
int main() {
  input();
  return 0;
}
