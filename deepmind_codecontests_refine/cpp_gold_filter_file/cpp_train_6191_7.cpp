#include <bits/stdc++.h>
using namespace std;
template <typename AA>
inline void CMax(AA &u, AA v) {
  if (v > u) u = v;
}
template <typename AA>
inline void CMin(AA &u, AA v) {
  if (v < u) u = v;
}
const double eps = 1E-8;
const int Inf = 0x3f3f3f3f, oo = 0x7fffffff, Mod = 998244353;
const long long Lnf = 0x3f3f3f3f3f3f3f3f;
template <typename AA>
void read(AA &x) {
  int s = 0;
  char c;
  for (c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar())
    ;
  c == '-' ? (s = 1, x = 0) : (x = c - '0');
  while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
  if (s) x = -x;
}
template <typename AA, typename... Args>
void read(AA &t, Args &...args) {
  read(t);
  read(args...);
}
template <typename AA>
void print(AA k) {
  int num = 0;
  static char stk[23];
  if (k < 0) {
    putchar('-');
    k = -k;
  }
  while (k) stk[++num] = k % 10 + 48, k /= 10;
  if (!num)
    putchar('0');
  else
    while (num) putchar(stk[num--]);
  putchar('\n');
}
inline int Log2(int x) {
  if (!x)
    return 0;
  else
    return 31 - __builtin_clz(x);
}
void gch(char &ch) {
  do {
    ch = getchar();
  } while (ch == ' ' || ch == '\n');
}
long long Pow(long long d, long long m) {
  long long f = 1;
  while (m) {
    if (m & 1) f = f * d % Mod;
    d = d * d % Mod;
    m >>= 1;
  }
  return f;
}
int T = 1, N, M, S, Q, K;
int TN;
multiset<int> m[200020];
struct G {
  int la[200020], nx[400400], to[400400], num, wi[200020];
  void add(int u, int v) {
    to[++num] = v;
    nx[num] = la[u];
    la[u] = num;
    to[++num] = u;
    nx[num] = la[v];
    la[v] = num;
  }
} e1, e2;
struct Tarjan {
  int stk[200020], top;
  int dfn[200020], low[200020], ord;
  void dfs(int now, int ffa) {
    dfn[now] = low[now] = ++ord;
    stk[++top] = now;
    for (int nxt, eg = e1.la[now]; eg; eg = e1.nx[eg]) {
      nxt = e1.to[eg];
      if (nxt == ffa) continue;
      if (!dfn[nxt]) {
        dfs(nxt, now);
        CMin(low[now], low[nxt]);
        if (dfn[now] <= low[nxt]) {
          e2.add(++TN, now);
          e2.wi[TN] = 1E9;
          int t;
          do {
            t = stk[top--];
            e2.add(TN, t);
          } while (t != nxt);
        }
      } else
        CMin(low[now], dfn[nxt]);
    }
  }
} tar;
struct Sgement {
  int p[200020 << 2];
  void modify(int id, int l, int r, int d, int w) {
    if (l == r)
      p[id] = w;
    else {
      int mid = (l + r) >> 1;
      if (d <= mid)
        modify(id << 1, l, mid, d, w);
      else
        modify(id << 1 | 1, mid + 1, r, d, w);
      p[id] = min(p[id << 1], p[id << 1 | 1]);
    }
  }
  int query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return p[id];
    int mid = (l + r) >> 1, ans = 1E9;
    if (ql <= mid) CMin(ans, query(id << 1, l, mid, ql, qr));
    if (qr > mid) CMin(ans, query(id << 1 | 1, mid + 1, r, ql, qr));
    return ans;
  }
} g;
struct Cactus {
  int fa[200020], siz[200020], son[200020], top[200020], dep[200020];
  int dfn[200020], ord;
  void dfs1(int now, int ffa) {
    fa[now] = ffa;
    siz[now] = 1;
    dep[now] = dep[ffa] + 1;
    for (int nxt, eg = e2.la[now]; eg; eg = e2.nx[eg]) {
      nxt = e2.to[eg];
      if (nxt == ffa) continue;
      dfs1(nxt, now);
      siz[now] += siz[nxt];
      if (siz[nxt] > siz[son[now]]) son[now] = nxt;
    }
  }
  void dfs2(int now, int ttp) {
    top[now] = ttp;
    dfn[now] = ++ord;
    if (son[now]) dfs2(son[now], ttp);
    for (int nxt, eg = e2.la[now]; eg; eg = e2.nx[eg]) {
      nxt = e2.to[eg];
      if (nxt == fa[now] || nxt == son[now]) continue;
      dfs2(nxt, nxt);
    }
  }
  int lca(int u, int v) {
    while (top[u] != top[v])
      dep[top[u]] < dep[top[v]] ? v = fa[top[v]] : u = fa[top[u]];
    return dep[u] < dep[v] ? u : v;
  }
  void deal(int u, int v) {
    int cf = lca(u, v);
    int mn = 1E9;
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]])
        CMin(mn, g.query(1, 1, TN, dfn[top[v]], dfn[v])), v = fa[top[v]];
      else
        CMin(mn, g.query(1, 1, TN, dfn[top[u]], dfn[u])), u = fa[top[u]];
    }
    CMin(mn, g.query(1, 1, TN, min(dfn[u], dfn[v]), max(dfn[u], dfn[v])));
    if (cf <= N)
      print(mn);
    else
      print(min(mn, e2.wi[fa[cf]]));
  }
} f;
signed main() {
  e1.num = 1;
  e2.num = 1;
  read(N, M, Q);
  TN = N;
  for (int a = (1); a <= (N); ++a) read(e1.wi[a]);
  for (int a = (1); a <= (M); ++a) {
    int u, v;
    read(u, v);
    e1.add(u, v);
  }
  tar.top = 0;
  tar.ord = 0;
  tar.dfs(1, 0);
  for (int a = (N + 1); a <= (TN); ++a) m[a].clear();
  f.ord = 0;
  f.dfs1(1, 0);
  f.dfs2(1, 1);
  for (int a = (1); a <= (N); ++a) {
    e2.wi[a] = e1.wi[a];
    g.modify(1, 1, TN, f.dfn[a], e2.wi[a]);
  }
  for (int a = (N + 1); a <= (TN); ++a) {
    for (int nxt, eg = e2.la[a]; eg; eg = e2.nx[eg]) {
      nxt = e2.to[eg];
      if (f.dep[nxt] <= f.dep[a]) continue;
      m[a].insert(e2.wi[nxt]);
    }
    int mn = *(m[a].begin());
    g.modify(1, 1, TN, f.dfn[a], mn);
  }
  while (Q--) {
    char id;
    int p, t;
    gch(id);
    read(p, t);
    if (id == 'C') {
      int ffa = f.fa[p];
      if (ffa) m[ffa].erase(m[ffa].find(e2.wi[p]));
      e2.wi[p] = t;
      if (ffa) m[ffa].insert(t);
      g.modify(1, 1, TN, f.dfn[p], t);
      if (ffa) g.modify(1, 1, TN, f.dfn[ffa], *(m[ffa].begin()));
    } else
      f.deal(p, t);
  }
  return 0;
}
