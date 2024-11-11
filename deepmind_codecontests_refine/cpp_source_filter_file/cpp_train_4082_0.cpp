#include <bits/stdc++.h>
using namespace std;
inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
char inputbuf[1 << 23], *p1 = inputbuf, *p2 = inputbuf;
inline int read() {
  int res = 0;
  char ch =
      (p1 == p2 && (p2 = (p1 = inputbuf) + fread(inputbuf, 1, 1 << 21, stdin),
                    p1 == p2)
           ? EOF
           : *p1++);
  bool f = true;
  for (; ch < '0' || ch > '9';
       ch = (p1 == p2 &&
                     (p2 = (p1 = inputbuf) + fread(inputbuf, 1, 1 << 21, stdin),
                     p1 == p2)
                 ? EOF
                 : *p1++))
    if (ch == '-') f = false;
  for (; ch >= '0' && ch <= '9';
       ch = (p1 == p2 &&
                     (p2 = (p1 = inputbuf) + fread(inputbuf, 1, 1 << 21, stdin),
                     p1 == p2)
                 ? EOF
                 : *p1++))
    res = res * 10 + (ch ^ 48);
  return f ? res : -res;
}
const int N = 1.5e5 + 15, P = 998244353;
int n, q, cnt, dfn, to[N << 1], nxt[N << 1], head[N];
int dep[N], fa[N], siz[N], son[N], id[N], top[N];
long long invn, tag[N];
inline long long poww(long long x, long long y) {
  long long res = 1;
  for (; y; y >>= 1, x = x * x % P)
    if (y & 1) res = res * x % P;
  return res;
}
inline void madd(long long &x, const long long &y) {
  x += y;
  if (x >= P) x -= P;
}
inline void add_edge(int x, int y) {
  to[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}
struct BIT {
  long long s[N];
  inline void add(int i, const long long &v) {
    for (; i <= n; i += i & -i) madd(s[i], v);
  }
  inline long long sum(int i) {
    long long res = 0;
    for (; i; i -= i & -i) madd(res, s[i]);
    return res;
  }
  inline void modify(const int &l, const int &r, const long long &v) {
    if (l <= r) add(l, v), add(r + 1, -v);
  }
} bit;
void dfs1(int u, int f) {
  fa[u] = f;
  siz[u] = 1;
  dep[u] = dep[f] + 1;
  for (register int i = head[u], v; i; i = nxt[i])
    if ((v = to[i]) ^ f) {
      dfs1(v, u);
      siz[u] += siz[v];
      if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int tf) {
  top[u] = tf;
  id[u] = ++dfn;
  if (!son[u]) return;
  dfs2(son[u], tf);
  for (register int i = head[u]; i; i = nxt[i])
    if (!id[to[i]]) dfs2(to[i], to[i]);
}
void modify(int x, long long d) {
  if (!d) return;
  bit.modify(1, id[x] - 1, d * siz[x] % P);
  bit.modify(id[x] + siz[x], n, d * siz[x] % P);
  bit.modify(id[x], id[x], d * n % P);
  if (son[x])
    bit.modify(id[son[x]], id[son[x]] + siz[son[x]] - 1,
               d * (n - siz[son[x]]) % P);
  madd(tag[x], d);
}
void query(int x) {
  long long ans = bit.sum(id[x]);
  for (; x; x = fa[top[x]]) madd(ans, tag[fa[top[x]]] * (n - siz[top[x]]) % P);
  printf("%lld\n", (ans * invn % P + P) % P);
}
void input() {
  int x, y;
  n = read();
  q = read();
  for (register int i = 2, iend = n; i <= iend; ++i) {
    x = read();
    y = read();
    add_edge(x, y);
    add_edge(y, x);
  }
}
signed main() {
  int x;
  long long d;
  input();
  invn = poww(n, P - 2);
  dfs1(1, 0);
  dfs2(1, 1);
  for (; q; --q) {
    if (read() & 1)
      x = read(), d = read(), modify(x, d);
    else
      query(read());
  }
  return 0;
}
