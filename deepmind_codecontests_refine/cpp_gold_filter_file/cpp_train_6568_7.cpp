#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long OO = 1LL << 62;
const int mod = 1e9 + 7;
int qpow(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = 1LL * ans * x % mod;
    x = 1LL * x * x % mod;
    y >>= 1;
  }
  return ans;
}
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
namespace io {
const int L = (1 << 21) + 1;
char ibuf[L], *iS, *iT, obuf[L], *oS = obuf, *oT = obuf + L - 1, c, st[55];
int f, tp;
inline char getc() {
  return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
}
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char x) {
  *oS++ = x;
  if (oS == oT) flush();
}
template <class I>
inline void gi(I &x) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') f = -1;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = x * 10 + (c & 15);
  x *= f;
}
template <class I>
inline void print(I x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = -x;
  while (x) st[++tp] = x % 10 + '0', x /= 10;
  while (tp) putc(st[tp--]);
}
inline void gs(char *s, int &l) {
  for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c < 'a' || c > 'z';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
  for (l = 0; c <= 'z' && c >= 'a';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    s[l++] = c;
  s[l] = 0;
}
inline void ps(const char *s) {
  for (int i = 0, n = strlen(s); i < n; i++) putc(s[i]);
}
struct IOFLUSHER {
  ~IOFLUSHER() { flush(); }
} _ioflusher_;
};  // namespace io
using io::getc;
using io::gi;
using io::gs;
using io::print;
using io::ps;
using io::putc;
int n;
const int N = 1e5 + 100;
struct Tag {
  bool w;
  friend Tag operator+(const Tag &a, const Tag &b) { return (Tag){a.w || b.w}; }
  void clear() { w = 0; }
};
struct Node {
  int sum, suf, siz;
  friend Node operator+(const Node &a, const Node &b) {
    return (Node){a.sum + b.sum, max(a.suf + b.sum, b.suf), a.siz + b.siz};
  }
  Node operator+(const Tag &b) { return b.w ? (Node){-siz, -1, siz} : *this; }
  void init() {
    sum = suf = -1;
    siz = 1;
  }
};
struct tree_devide_to_chain {
  Tag tag[N * 4];
  Node s[N * 4];
  void mark(int i, int l, int r, Tag t) {
    s[i] = s[i] + t;
    tag[i] = tag[i] + t;
  }
  void pushdown(int i, int l, int r) {
    mark((i << 1), l, ((l + r) >> 1), tag[i]);
    mark(((i << 1) | 1), ((l + r) >> 1) + 1, r, tag[i]);
    tag[i].clear();
  }
  void update(int i) { s[i] = s[(i << 1)] + s[((i << 1) | 1)]; }
  void build(int i, int l, int r) {
    if (l == r)
      s[i].init();
    else {
      build((i << 1), l, ((l + r) >> 1));
      build(((i << 1) | 1), ((l + r) >> 1) + 1, r);
      update(i);
    }
  }
  void modify(int i, int l, int r, int L, int R, Tag t) {
    if (L <= l && r <= R)
      mark(i, l, r, t);
    else {
      pushdown(i, l, r);
      if (L <= ((l + r) >> 1)) modify((i << 1), l, ((l + r) >> 1), L, R, t);
      if (((l + r) >> 1) < R)
        modify(((i << 1) | 1), ((l + r) >> 1) + 1, r, L, R, t);
      update(i);
    }
  }
  void modify(int i, int l, int r, int k, Node t) {
    if (l == r)
      s[i] = t;
    else {
      pushdown(i, l, r);
      k <= ((l + r) >> 1) ? modify((i << 1), l, ((l + r) >> 1), k, t)
                          : modify(((i << 1) | 1), ((l + r) >> 1) + 1, r, k, t);
      update(i);
    }
  }
  Node query(int i, int l, int r, int L, int R) {
    if (L <= l && r <= R)
      return s[i];
    else {
      pushdown(i, l, r);
      if (R <= ((l + r) >> 1)) return query((i << 1), l, ((l + r) >> 1), L, R);
      if (((l + r) >> 1) < L)
        return query(((i << 1) | 1), ((l + r) >> 1) + 1, r, L, R);
      return query((i << 1), l, ((l + r) >> 1), L, R) +
             query(((i << 1) | 1), ((l + r) >> 1) + 1, r, L, R);
    }
  }
  int head[N], nxt[N * 2], to[N * 2], tot = 1;
  int fa[N], siz[N], son[N], dep[N], top[N];
  int sa[N], L[N], R[N], cnt;
  void link(int a, int b) {
    to[++tot] = b, nxt[tot] = head[a], head[a] = tot;
    to[++tot] = a, nxt[tot] = head[b], head[b] = tot;
  }
  void dfs1(int k) {
    siz[k] = 1;
    son[k] = 0;
    dep[k] = dep[fa[k]] + 1;
    for (int i = head[k]; i; i = nxt[i])
      if (to[i] != fa[k]) {
        fa[to[i]] = k;
        dfs1(to[i]);
        siz[k] += siz[to[i]];
        if (siz[to[i]] > siz[son[k]]) son[k] = to[i];
      }
  }
  void dfs2(int k) {
    sa[L[k] = ++cnt] = k;
    if (!top[k]) top[k] = k;
    if (son[k]) {
      top[son[k]] = top[k];
      dfs2(son[k]);
      for (int i = head[k]; i; i = nxt[i])
        if (to[i] != fa[k] && to[i] != son[k]) dfs2(to[i]);
    }
    R[k] = cnt;
  }
  int lca(int a, int b) {
    while (top[a] ^ top[b])
      dep[top[a]] > dep[top[b]] ? a = fa[top[a]] : b = fa[top[b]];
    return dep[a] < dep[b] ? a : b;
  }
  void chain_work(int a, int b, Tag c) {
    while (top[a] != top[b])
      if (dep[top[a]] > dep[top[b]]) {
        modify(1, 1, n, L[top[a]], L[a], c);
        a = fa[top[a]];
      } else {
        modify(1, 1, n, L[top[b]], L[b], c);
        b = fa[top[b]];
      }
    if (dep[a] > dep[b])
      modify(1, 1, n, L[b], L[a], c);
    else
      modify(1, 1, n, L[a], L[b], c);
  }
  int chain_query(int k) {
    Node ans = {0, -oo, 0};
    while (k) ans = query(1, 1, n, L[top[k]], L[k]) + ans, k = fa[top[k]];
    return ans.suf;
  }
  void init() {
    dfs1(1);
    cnt = 0;
    dfs2(1);
    build(1, 1, n);
  }
};
tree_devide_to_chain T;
int main() {
  int m, i, k, op, t;
  gi(n), gi(m);
  for (i = 2; i <= n; i++) gi(k), T.link(i, k);
  T.init();
  while (m--) {
    gi(op), gi(k);
    if (op == 1) {
      t = T.query(1, 1, n, T.L[k], T.L[k]).sum;
      T.modify(1, 1, n, T.L[k], (Node){t + 1, t + 1, 1});
    } else if (op == 2) {
      t = max(T.chain_query(T.fa[k]), 0);
      T.modify(1, 1, n, T.L[k], (Node){-t - 1, -t - 1, 1});
      if (T.L[k] != T.R[k]) T.modify(1, 1, n, T.L[k] + 1, T.R[k], (Tag){1});
    } else
      ps(T.chain_query(k) >= 0 ? "black\n" : "white\n");
  }
  return 0;
}
