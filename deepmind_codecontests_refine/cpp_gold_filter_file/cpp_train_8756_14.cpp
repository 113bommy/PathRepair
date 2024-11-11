#include <bits/stdc++.h>
using namespace std;
char gchar() {
  static char tbuf1[1000], *tmp_st = tbuf1, *tmp_ed = tbuf1;
  if (tmp_st == tmp_ed) {
    int len = fread(tbuf1, 1, 1000, stdin);
    if (len == 0) return -1;
    tmp_ed = tbuf1 + len;
    tmp_st = tbuf1;
  }
  return *(tmp_st++);
}
inline bool gn(int &x) {
  char c, sg = 0;
  while (c = gchar(), (c > '9' || c < '0') && c != '-' && ~c)
    ;
  if (c == -1) return 0;
  for ((c == '-' ? sg = 1, c = gchar() : 0), x = 0; c >= '0' && c <= '9';
       c = gchar())
    x = (x << 1) + (x << 3) + c - '0';
  if (sg) x = -x;
  return 1;
}
inline void print(int x) {
  if (x < 0) {
    putchar('-');
    return print(-x);
  }
  if (x < 10) {
    putchar('0' + x);
    return;
  }
  print(x / 10);
  putchar(x % 10 + '0');
}
template <class T, class T1>
inline bool gn(T &x, T1 &x1) {
  bool ok = gn(x);
  gn(x1);
  return ok;
}
template <class T>
inline void println(T x) {
  print(x);
  putchar('\n');
}
int head[200001], nxt[200001], to[200001], E;
inline void add(int u, int v) {
  nxt[E] = head[u];
  to[E] = v;
  head[u] = E++;
}
int deep[200001];
struct LCA {
  int vst[200001], seq[200001 << 1], rec[200001 << 1], nn;
  inline void dfs(int u, int fa = -1) {
    vst[u] = nn;
    rec[nn] = u;
    seq[nn++] = vst[u];
    for (int e = head[u]; e != -1; e = nxt[e]) {
      int v = to[e];
      if (v == fa) continue;
      deep[v] = deep[u] + 1;
      dfs(v, u);
      rec[nn] = u;
      seq[nn++] = vst[u];
    }
  }
  int mn[200001 << 1][19];
  void pre() {
    dfs(1);
    for (int i = 0; i < nn; i++) mn[i][0] = seq[i];
    for (int j = 1; j < 19; j++)
      for (int i = 0; i < nn; i++) {
        mn[i][j] = min(mn[i][j - 1], mn[min(nn, i + (1 << j - 1))][j - 1]);
      }
  }
  int lca(int u, int v) {
    if (vst[u] > vst[v]) swap(u, v);
    int l = 31 - __builtin_clz(vst[v] - vst[u] + 1);
    int id = min(mn[vst[u]][l], mn[vst[v] - (1 << l) + 1][l]);
    return rec[id];
  }
} lca;
inline int dist(int u, int v) {
  int w = lca.lca(u, v);
  return deep[u] + deep[v] - (deep[w] << 1);
}
inline void update(int &x, int &y, int a, int b, int c, int d) {
  x = a, y = b;
  if (deep[c] > deep[x]) x = c;
  if (deep[c] < deep[y]) y = c;
  if (deep[d] > deep[x]) x = d;
  if (deep[d] < deep[y]) y = d;
  bool A = deep[a] + dist(a, x) != deep[x];
  bool B = deep[b] + dist(b, x) != deep[x];
  bool C = deep[c] + dist(c, x) != deep[x];
  bool D = deep[d] + dist(d, x) != deep[x];
  if (A) y = a;
  if (B) y = b;
  if (C) y = c;
  if (D) y = d;
  if (A && deep[a] > deep[y]) y = a;
  if (B && deep[b] > deep[y]) y = b;
  if (C && deep[c] > deep[y]) y = c;
  if (D && deep[d] > deep[y]) y = d;
  int w = lca.lca(x, y);
  if (deep[a] < deep[w] || deep[b] < deep[w] || deep[c] < deep[w] ||
      deep[d] < deep[w])
    x = 0;
  else if (A && deep[a] + dist(a, y) != deep[y])
    x = 0;
  else if (B && deep[b] + dist(b, y) != deep[y])
    x = 0;
  else if (C && deep[c] + dist(c, y) != deep[y])
    x = 0;
  else if (D && deep[d] + dist(d, y) != deep[y])
    x = 0;
}
int p[200001], pos[200001];
int LL[800000], RR[800000], x[800000], y[800000];
inline void push_up(int u, int ls, int rs) {
  x[u] = 0;
  if (x[ls] && x[rs]) {
    update(x[u], y[u], x[ls], y[ls], x[rs], y[rs]);
  }
}
inline void build(int u, int L, int R) {
  LL[u] = L;
  RR[u] = R;
  if (L + 1 == R) {
    x[u] = y[u] = pos[L];
    return;
  }
  int ls = u << 1, rs = ls | 1, mid = L + R >> 1;
  build(ls, L, mid);
  build(rs, mid, R);
  push_up(u, ls, rs);
}
int l, r, flag, X, Y, xx, yy;
inline void update(int u) {
  int L = LL[u], R = RR[u];
  if (r <= L || R <= l) return;
  if (l <= L && R <= r) {
    x[u] = y[u] = pos[L];
    return;
  }
  int ls = u << 1, rs = ls | 1;
  update(ls), update(rs);
  push_up(u, ls, rs);
}
inline int calc(int u) {
  if (flag) return 0;
  int L = LL[u], R = RR[u];
  if (x[u]) {
    update(xx, yy, X, Y, x[u], y[u]);
    if (xx) {
      X = xx, Y = yy;
      return R - L;
    }
  }
  if (L + 1 == R) {
    flag = 1;
    return 0;
  }
  int ls = u << 1;
  L = calc(ls);
  if (L) return L + calc(ls | 1);
  return 0;
}
int main() {
  int n;
  gn(n);
  for (int i = 1; i <= n; i++) {
    gn(p[i]);
    pos[p[i]] = i;
    head[i] = -1;
  }
  for (int i = 2, pa; i <= n; i++) {
    gn(pa);
    add(pa, i);
  }
  lca.pre();
  build(1, 0, n);
  int q;
  gn(q);
  while (q--) {
    int t;
    gn(t);
    if (t == 1) {
      int x, y;
      gn(x, y);
      swap(p[x], p[y]);
      swap(pos[p[x]], pos[p[y]]);
      l = p[x], r = l + 1;
      update(1);
      l = p[y], r = l + 1;
      update(1);
    } else {
      X = Y = pos[0];
      flag = 0;
      println(calc(1));
    }
  }
}
