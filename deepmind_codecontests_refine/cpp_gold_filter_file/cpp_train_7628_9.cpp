#include <bits/stdc++.h>
using namespace std;
struct IO {
  char buf[(1 << 20)], *p1, *p2;
  char pbuf[(1 << 20)], *pp;
  IO() : p1(buf), p2(buf), pp(pbuf) {}
  inline char gc() {
    return getchar();
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, (1 << 20), stdin);
    return p1 == p2 ? ' ' : *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  template <class T>
  inline void read(T &x) {
    register double tmp = 1;
    register bool sign = 0;
    x = 0;
    register char ch = gc();
    for (; !(ch >= '0' && ch <= '9'); ch = gc())
      if (ch == '-') sign = 1;
    for (; (ch >= '0' && ch <= '9'); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); (ch >= '0' && ch <= '9'); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }
  inline void read(char *s) {
    register char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }
  inline void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }
  template <class t>
  inline void write(t x) {
    if (x < 0)
      putchar('-'), write(-x);
    else {
      if (x > 9) write(x / 10);
      putchar('0' + x % 10);
    }
  }
} io;
const long long mod = 1e9 + 7;
const long long mo = 998244353;
const long long N = 1e6 + 5;
long long n, m, K, fa[N], col[N], id[N], vis[N], bl[N], cant[N], fl, bloid, ans;
vector<long long> h[N];
struct Node {
  long long x, y;
};
Node a[N];
inline long long find(long long x) {
  return fa[x] = (x == fa[x]) ? x : find(fa[x]);
}
inline void dfs(long long u, long long color) {
  bl[u] = color;
  for (long long i : h[u]) {
    if (bl[u] == bl[i]) cant[col[i]] = 1;
    if (!bl[i]) dfs(i, color ^ 1);
  }
}
signed main() {
  io.read(n), io.read(m), io.read(K);
  for (long long i = (1); i <= (n); i++) io.read(col[i]);
  for (long long i = (1); i <= (m); i++) {
    long long x, y;
    io.read(x), io.read(y);
    if (col[x] > col[y]) swap(x, y);
    a[i] = (Node){x, y};
    if (col[x] == col[y]) h[x].emplace_back(y), h[y].emplace_back(x);
  }
  sort(a + 1, a + m + 1, [&](Node s, Node t) {
    return (col[s.x] == col[t.x]) ? col[s.y] < col[t.y] : col[s.x] < col[t.x];
  });
  for (long long i = (1); i <= (n); i++)
    if (!bl[i]) {
      bloid += 2;
      dfs(i, bloid);
    }
  long long sum = 0;
  for (long long i = (1); i <= (K); i++)
    if (cant[i]) sum++;
  for (long long i = (1); i <= (sum); i++) ans = (ans + K - i);
  long long j = 1;
  for (long long i = 1; i <= m; i = j + 1) {
    j = i;
    while (j + 1 <= m && col[a[j].x] == col[a[j + 1].x] &&
           col[a[j].y] == col[a[j + 1].y])
      j++;
    if (col[a[i].x] != col[a[i].y]) {
      if (cant[col[a[i].x]]) continue;
      if (cant[col[a[i].y]]) continue;
      for (long long k = (i); k <= (j); k++) {
        long long x = a[k].x, y = a[k].y;
        fa[bl[x]] = bl[x], fa[bl[x] ^ 1] = bl[x] ^ 1;
        fa[bl[y]] = bl[y], fa[bl[y] ^ 1] = bl[y] ^ 1;
      }
      for (long long k = (i); k <= (j); k++) {
        long long x = a[k].x, y = a[k].y;
        fa[find(bl[x])] = find(bl[y] ^ 1);
        fa[find(bl[x] ^ 1)] = find(bl[y]);
      }
      long long del = 0;
      for (long long k = (i); k <= (j); k++) {
        long long x = a[k].x, y = a[k].y;
        del |= (find(bl[x]) == find(bl[x] ^ 1));
        del |= (find(bl[y]) == find(bl[y] ^ 1));
      }
      ans += del;
    }
  }
  io.write(K * (K - 1) / 2 - ans), puts("");
}
