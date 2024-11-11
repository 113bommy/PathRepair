#include <bits/stdc++.h>
using namespace std;
const long long N = 1000010;
const long long p = 998244353;
struct edge {
  long long v, nxt;
} g[N << 1];
long long tot = 0, head[N];
inline void add(long long u, long long v) {
  g[++tot] = edge{v, head[u]};
  head[u] = tot;
  g[++tot] = edge{u, head[v]};
  head[v] = tot;
}
long long n, q, tree[N], tag[N];
inline long long lowbit(long long x) { return x & (-x); }
inline void Add(long long ps, long long x) {
  while (ps <= n) (tree[ps] += x) %= p, ps += lowbit(ps);
}
inline long long Query(long long ps) {
  long long ans = 0;
  while (ps) (ans += tree[ps]) %= p, ps -= lowbit(ps);
  return ans;
}
long long fa[N], sz[N], son[N], dfn[N], tpos[N], top[N], cnt = 0;
inline void dfs1(long long u) {
  sz[u] = 1;
  for (long long i = head[u]; i; i = g[i].nxt) {
    long long v = g[i].v;
    if (v == fa[u]) continue;
    fa[v] = u;
    dfs1(v);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
inline void dfs2(long long u, long long tp) {
  top[u] = tp;
  dfn[++cnt] = u;
  tpos[u] = cnt;
  if (son[u]) dfs2(son[u], tp);
  for (long long i = head[u]; i; i = g[i].nxt) {
    long long v = g[i].v;
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}
inline long long pw(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = 1ll * ans * x % p;
    x = 1ll * x * x % p;
    y >>= 1;
  }
  return ans;
}
signed main() {
  scanf("%lld%lld", &n, &q);
  for (long long i = 1, u, v; i < n; ++i) scanf("%lld%lld", &u, &v), add(u, v);
  dfs1(1);
  dfs2(1, 1);
  long long tmp = pw(n, p - 2);
  while (q--) {
    long long opt, u, d;
    scanf("%lld%lld", &opt, &u);
    if (opt == 1) {
      scanf("%lld", &d);
      if (u != 1) Add(tpos[u], d * (n - sz[u]) % p);
      Add(1, d * sz[u] % p);
      if (son[u]) Add(tpos[son[u]], d * (p - sz[son[u]]) % p);
      (tag[u] += d) %= p;
    } else {
      long long ans = 0;
      while (top[u] != 1) {
        (ans += Query(tpos[u]) - Query(tpos[top[u]] - 1)) %= p;
        (ans -= tag[fa[top[u]]] * sz[top[u]]) %= p;
        u = fa[top[u]];
      }
      (ans += Query(tpos[u])) %= p;
      printf("%lld\n", 1ll * (ans + p) % p * tmp % p);
    }
  }
  return 0;
}
