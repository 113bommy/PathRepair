#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[300005], c[300005], s[300005], d[300005], fa[300005], sn[300005],
    tp[300005], rk[300005], id[300005];
long long cnt, tot;
vector<long long> e[300005];
const long long p = 998244353;
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
inline void addEdge(long long u, long long v) { e[u].push_back(v); }
void dfs1(long long u) {
  s[u] = 1, d[u] = d[fa[u]] + 1;
  for (long long v : e[u]) {
    if (v != fa[u]) {
      fa[v] = u, dfs1(v), s[u] += s[v];
      if (s[sn[u]] < s[v]) sn[u] = v;
    }
  }
}
void dfs2(long long u, long long top) {
  tp[u] = top, id[u] = ++cnt, rk[cnt] = u;
  if (sn[u]) dfs2(sn[u], top);
  for (long long v : e[u])
    if (v != fa[u] && v != sn[u]) dfs2(v, v);
}
inline void add(long long x, long long k) {
  for (long long i = x; i < 300005; i += (i & -i)) c[i] = (c[i] + k) % p;
}
inline long long query(long long x) {
  long long ans = 0;
  for (long long i = x; i; i -= (i & -i)) ans = (ans + c[i]) % p;
  return ans;
}
inline void update(long long l, long long r, long long v) {
  add(l, v), add(r + 1, p - v);
}
inline long long fastPow(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) ans = ans * a % p;
  return ans;
}
inline long long inv(long long x) { return fastPow(x, p - 2); }
signed main() {
  n = read(), m = read();
  long long Inv_n = inv(n);
  for (long long i = 1, u, v; i < n; i++)
    u = read(), v = read(), addEdge(u, v), addEdge(v, u);
  dfs1(1), dfs2(1, 1);
  while (m--) {
    long long opt;
    opt = read();
    if (opt == 1) {
      long long v, r;
      v = read(), r = read();
      a[v] = (a[v] + r) % p, add(1, s[v] * r % p),
      update(id[v], id[v] + s[v] - 1, p - s[v] * r % p);
      if (sn[v])
        update(id[sn[v]], id[sn[v]] + s[sn[v]] - 1, (n - s[sn[v]]) * r % p);
    } else {
      long long v;
      v = read();
      long long ans = (query(id[v]) + a[v] * n % p) % p;
      for (long long i = tp[v]; fa[i]; i = tp[fa[i]])
        ans = (ans + (n - s[v]) * a[fa[i]] % p) % p;
      printf("%d\n", ans * Inv_n % p);
    }
  }
  return 0;
}
