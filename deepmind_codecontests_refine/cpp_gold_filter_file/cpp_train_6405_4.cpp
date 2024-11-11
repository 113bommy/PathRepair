#include <bits/stdc++.h>
using namespace std;
namespace io {
const int SI = 1 << 21 | 1;
char IB[SI], *IS, *IT, OB[SI], *OS = OB, *OT = OS + SI - 1, c, ch[100];
int f, t;
inline void flush() { fwrite(OB, 1, OS - OB, stdout), OS = OB; }
inline void pc(char x) {
  *OS++ = x;
  if (OS == OT) flush();
}
template <class I>
inline void rd(I &x) {
  for (f = 1, c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                              IS == IT ? EOF : *IS++)
                            : *IS++);
       c < '0' || c > '9';
       c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++))
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15),
      c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                      IS == IT ? EOF : *IS++)
                    : *IS++))
    ;
  x *= f;
}
template <class I>
inline void rda(I *a, int &n) {
  for (int i = 1; i <= n; i++) rd(a[i]);
}
inline void rds(char *s, int &x) {
  for (c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++);
       c < 33 || c > 126;
       c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++))
    ;
  for (x = 0; c >= 33 && c <= 126;
       s[++x] = c, c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                                   IS == IT ? EOF : *IS++)
                                 : *IS++))
    ;
  s[x + 1] = '\0';
}
template <class I>
inline void print(I x, char k = '\n') {
  if (!x) pc('0');
  if (x < 0) pc('-'), x = -x;
  while (x) ch[++t] = x % 10 + '0', x /= 10;
  while (t) pc(ch[t--]);
  pc(k);
}
inline void prints(string s) {
  int x = s.length();
  while (t < x) pc(s[t++]);
  pc('\n'), t = 0;
}
struct Flush {
  ~Flush() { flush(); }
} flusher;
}  // namespace io
using io::print;
using io::prints;
using io::rd;
using io::rda;
using io::rds;
const int N = 3e5 + 7, M = 6e5 + 7;
int q, rt[N], f[N][21], d[N], dfn[N], tot, s[N], t;
struct Undirected_Gragh_edcc {
  int n, m, h[N], e[M * 2], t[M * 2], tot = 1, dfn[N], low[N], num;
  bool b[M * 2];
  int c[N], dcc;
  vector<int> bridge, ec[N];
  inline void add(int x, int y, int o = 1) {
    e[++tot] = y, t[tot] = h[x], h[x] = tot;
    if (o) add(y, x, 0);
  }
  void tarjan(int x, int f) {
    dfn[x] = low[x] = ++num;
    for (int i = h[x]; i; i = t[i])
      if (i ^ f ^ 1) {
        int y = e[i];
        if (!dfn[y]) {
          tarjan(y, i), low[x] = min(low[x], low[y]);
          if (low[y] > dfn[x]) b[i] = b[i ^ 1] = 1, bridge.push_back(i);
        } else
          low[x] = min(low[x], dfn[y]);
      }
  }
  void dfs(int x) {
    c[x] = dcc;
    for (int i = h[x]; i; i = t[i]) {
      int y = e[i];
      if (c[y] || b[i]) continue;
      dfs(y);
    }
  }
  inline void Bridge() {
    for (int i = 1; i <= n; i++)
      if (!dfn[i]) tarjan(i, 0);
  }
  inline void edcc() {
    Bridge();
    for (int i = 1; i <= n; i++)
      if (!c[i]) ++dcc, dfs(i);
  }
  inline void Brighe(vector<int> p) {
    for (int x : p)
      if (!dfn[x]) tarjan(x, 0);
  }
  inline void edcc(vector<int> p) {
    Brighe(p);
    for (int x : p)
      if (!c[x]) ++dcc, dfs(x);
  }
  inline void main() {
    edcc();
    for (int i = 2; i <= tot; i++)
      if (b[i]) ec[c[e[i]]].push_back(c[e[i ^ 1]]);
  }
  inline void init(vector<int> p) {
    tot = 1, num = dcc = 0;
    for (int x : p) h[x] = dfn[x] = low[x] = c[x] = 0;
    for (int i : bridge) b[i] = b[i ^ 1] = 0;
    bridge.clear();
  }
} gragh, g;
void dfs(int x) {
  dfn[x] = ++tot;
  for (int y : gragh.ec[x])
    if (y != f[x][0]) {
      d[y] = d[x] + 1, f[y][0] = x, rt[y] = rt[x];
      for (int i = 1; f[y][i - 1]; i++) f[y][i] = f[f[y][i - 1]][i - 1];
      dfs(y);
    }
}
inline int lca(int x, int y) {
  if (d[x] > d[y]) swap(x, y);
  for (int i = 20; ~i; i--)
    if (d[f[y][i]] >= d[x]) y = f[y][i];
  if (x == y) return x;
  for (int i = 20; ~i; i--)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
inline void virtual_tree(vector<int> &p) {
  sort(p.begin(), p.end(), [](int x, int y) { return dfn[x] < dfn[y]; });
  int o = 0;
  vector<int> q = p;
  for (int x : p) {
    if (t && rt[x] != o)
      while (--t) g.add(s[t + 1], s[t]);
    int lca = ::lca(x, s[t]);
    if (lca != s[t]) {
      while (t && d[s[t - 1]] >= d[lca]) g.add(s[t], s[t - 1]), --t;
      if (s[t] != lca) g.add(s[t], lca), s[t] = lca, q.push_back(lca);
    }
    s[++t] = x, o = rt[x];
  }
  if (t)
    while (--t) g.add(s[t + 1], s[t]);
  p = q;
}
inline void work(int &x, int R) {
  x = x + R > gragh.n ? x + R - gragh.n : x + R;
}
int main() {
  rd(gragh.n), rd(gragh.m), rd(q);
  for (int i = 1, x, y; i <= gragh.m; i++) rd(x), rd(y), gragh.add(x, y);
  gragh.main();
  for (int i = 1; i <= gragh.dcc; i++)
    if (!rt[i]) rt[i] = i, d[i] = 1, dfs(i);
  for (int i = 1, n, m, R = 0; i <= q; i++) {
    rd(n), rd(m);
    vector<int> v, p;
    vector<pair<int, int> > e;
    for (int i = 1, x; i <= n; i++)
      rd(x), work(x, R), v.push_back(x = gragh.c[x]), p.push_back(x);
    for (int i = 1, x, y; i <= m; i++) {
      rd(x), rd(y), work(x, R), work(y, R);
      x = gragh.c[x], y = gragh.c[y];
      if (x == y) continue;
      e.push_back(make_pair(x, y)), p.push_back(x), p.push_back(y);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    virtual_tree(p);
    for (pair<int, int> o : e) g.add(o.first, o.second);
    g.edcc(p);
    int k = g.c[v[0]];
    bool ok = 1;
    for (int x : v) {
      if (g.c[x] != k) ok = 0;
    }
    prints(ok ? "YES" : "NO");
    if (ok) R = (R + i) % gragh.n;
    g.init(p);
  }
  return 0;
}
