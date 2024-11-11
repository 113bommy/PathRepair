#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
  char c = getchar();
  long long neg = 1;
  long long val = 0;
  while (c != '-' && !isdigit(c)) c = getchar();
  if (c == '-') {
    c = getchar();
    neg = -1;
  }
  while (isdigit(c)) {
    val = (val << 3) + (val << 1) + c - '0';
    c = getchar();
  }
  return neg * val;
}
const long long N = 200020;
long long n, m;
struct Fenwick {
  long long arr[N + 15];
  void modify(long long x, long long d) {
    for (; x <= N; x += x & (-x)) {
      arr[x] = (arr[x] + d) % mod;
    }
  }
  long long query(long long x) {
    long long res = 0;
    for (; x; x -= x & (-x)) {
      res = (res + arr[x]) % mod;
    }
    return res;
  }
} fenwick;
long long top[N], dfn[N], dep[N], fa[N], hson[N], sz[N];
vector<long long> g[N];
void dfs1(long long u) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    dep[v] = dep[u] + 1;
    fa[v] = u;
    dfs1(v);
    sz[u] += sz[v];
    if (sz[v] > sz[hson[u]]) hson[u] = v;
  }
}
long long in[N], out[N];
long long tot;
void dfs2(long long u, long long t) {
  top[u] = t;
  in[u] = dfn[u] = ++tot;
  if (hson[u]) dfs2(hson[u], t);
  for (auto v : g[u])
    if (v != hson[u] && v != fa[u]) dfs2(v, v);
  out[u] = tot;
}
long long qpow(long long a, long long b = mod - 2) {
  long long ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans % mod;
}
long long lazy[N];
void solve() {
  n = qread();
  m = qread();
  for (long long i = 0; i < (long long)n - 1; i++) {
    long long u = qread(), v = qread();
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fa[1] = 1;
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  long long invn = qpow(n);
  while (m--) {
    long long op = qread();
    if (op == 1) {
      long long u = qread(), d = qread();
      if (u != 1) fenwick.modify(dfn[u], d * (n - sz[u]) % mod);
      fenwick.modify(1, d * sz[u] % mod);
      if (hson[u]) fenwick.modify(dfn[u] + 1, d * (mod - sz[hson[u]]) % mod);
      lazy[u] = (lazy[u] + d) % mod;
    } else {
      long long u = qread();
      long long ans = 0;
      while (top[u] != 1) {
        ans = (((ans + fenwick.query(dfn[u])) % mod + mod * 10 -
                fenwick.query(dfn[top[u]] - 1)) %
                   mod +
               lazy[fa[top[u]]] * (mod * 10 - sz[top[u]]) % mod) %
              mod;
        u = fa[top[u]];
      }
      ans = (ans + fenwick.query(dfn[u])) % mod;
      printf("%lld\n", (long long)(ans * invn % mod));
    }
  }
}
signed main() {
  long long T = 1;
  while (T--) solve();
  return 0;
}
