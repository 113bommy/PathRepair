#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
char s[500005], t[500005];
int head[100005], to[100005], Next[100005];
int fa[100005][25], End[500005], Max[500005];
struct PII {
  int fir, sec;
  inline bool operator<(const PII &x) const {
    return sec == x.sec ? fir > x.fir : sec < x.sec;
  }
};
struct Segment_Tree {
  int tot;
  PII seg[2000005];
  int root[100005], son[2000005][2];
  void change(int &k, int l, int r, int pos) {
    if (!k) k = ++tot;
    if (l == r) {
      seg[k].fir = pos;
      seg[k].sec++;
      return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
      change(son[k][0], l, mid + 0, pos);
    else
      change(son[k][1], mid + 1, r, pos);
    seg[k] = max(seg[son[k][0]], seg[son[k][1]]);
    return;
  }
  PII query(int k, int l, int r, int wl, int wr) {
    if (!k) return (PII){0, 0};
    if (wr < l || r < wl) return (PII){0, 0};
    if (wl <= l && r <= wr) return seg[k];
    int mid = l + r >> 1;
    PII res = (PII){0, 0};
    res = max(res, query(son[k][0], l, mid + 0, wl, wr));
    res = max(res, query(son[k][1], mid + 1, r, wl, wr));
    return res;
  }
  int merge(int x, int y, int l, int r) {
    if (!x || !y) return x + y;
    int k = ++tot;
    if (l == r) {
      seg[k] = (PII){l, seg[x].sec + seg[y].sec};
      return k;
    }
    int mid = l + r >> 1;
    son[k][0] = merge(son[x][0], son[y][0], l, mid + 0);
    son[k][1] = merge(son[x][1], son[y][1], mid + 1, r);
    seg[k] = max(seg[son[k][0]], seg[son[k][1]]);
    return k;
  }
} T;
struct SAM {
  int tot, lst;
  struct Trans {
    int len, link;
    int Next[26];
  } s[100005];
  void init() {
    s[0].link = -1;
    s[0].len = tot = lst = 0;
  }
  void insert(char c, int rk) {
    int p = lst, Now = ++tot;
    s[Now].len = s[p].len + 1;
    T.change(T.root[Now], 1, n, rk);
    while (p != -1 && !s[p].Next[c - 'a']) {
      s[p].Next[c - 'a'] = Now;
      p = s[p].link;
    }
    if (p == -1)
      s[Now].link = 0;
    else {
      int q = s[p].Next[c - 'a'];
      if (s[q].len == s[p].len + 1)
        s[Now].link = q;
      else {
        int New = ++tot;
        s[New] = s[q];
        s[New].len = s[p].len + 1;
        while (p != -1 && s[p].Next[c - 'a'] == q) {
          s[p].Next[c - 'a'] = New;
          p = s[p].link;
        }
        s[Now].link = s[q].link = New;
      }
    }
    lst = Now;
    return;
  }
  void build(char *s, int rk) {
    int n = strlen(s + 1);
    for (register int i = 1; i <= n; ++i) insert(s[i], rk);
    return;
  }
  void Match(char *t) {
    int u = 0, len = 0, n = strlen(t + 1);
    for (register int i = 1; i <= n; ++i) {
      while (u != -1 && !s[u].Next[t[i] - 'a']) {
        u = s[u].link;
        len = s[u].len;
      }
      if (u == -1)
        u = len = 0;
      else {
        ++len;
        u = s[u].Next[t[i] - 'a'];
      }
      End[i] = u;
      Max[i] = len;
    }
    return;
  }
} S;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void add(int u, int v) {
  to[++cnt] = v;
  Next[cnt] = head[u];
  head[u] = cnt;
}
void DFS(int u) {
  for (register int i = 1; i <= 20; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (register int i = head[u]; i; i = Next[i]) {
    int v = to[i];
    fa[v][0] = u;
    DFS(v);
    T.root[u] = T.merge(T.root[u], T.root[v], 1, n);
  }
  return;
}
PII Query(int l, int r, int L, int R) {
  if (Max[R] < R - L + 1) return (PII){l, 0};
  int s = End[R];
  for (register int i = 20; ~i; --i) {
    if (S.s[fa[s][i]].len >= R - L + 1) s = fa[s][i];
  }
  PII ans = T.query(T.root[s], 1, n, l, r);
  if (!ans.sec) ans.fir = l;
  return ans;
}
int main() {
  scanf("%s", s + 1);
  n = read();
  S.init();
  for (register int i = 1; i <= n; ++i) {
    scanf("%s", t + 1);
    S.lst = 0;
    S.build(t, i);
  }
  S.Match(s);
  for (register int i = 1; i <= S.tot; ++i) add(S.s[i].link, i);
  DFS(0);
  m = read();
  for (register int i = 1; i <= m; ++i) {
    int l = read(), r = read();
    int L = read(), R = read();
    PII ans = Query(l, r, L, R);
    printf("%d %d\n", ans.fir, ans.sec);
  }
  return 0;
}
