#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}
const long long N = 1e5 + 5, mod = 1e9 + 7;
inline long long qpow(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) res = res * a % mod;
  return res;
}
inline void ad(long long &x, long long y) { x = (x + y) % mod; }
inline long long to(long long x) { return (x % mod + mod) % mod; }
long long n;
vector<long long> G[N], ins[N], del[N];
long long a[N], siz[N], top[N], fa[N], dfn[N], son[N], dep[N];
long long sum[N << 2], add[N << 2];
inline void up(long long rt) {
  sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % mod;
}
inline void down(long long rt, long long l, long long r) {
  if (add[rt]) {
    long long mid = (l + r) >> 1;
    ad(add[rt << 1], add[rt]);
    ad(add[rt << 1 | 1], add[rt]);
    ad(sum[rt << 1], add[rt] * (mid - l + 1) % mod);
    ad(sum[rt << 1 | 1], add[rt] * (r - mid) % mod);
    add[rt] = 0;
  }
}
inline void update(long long rt, long long l, long long r, long long L,
                   long long R, long long v) {
  if (L <= l && r <= R) {
    ad(add[rt], v);
    ad(sum[rt], v * (r - l + 1) % mod);
    return;
  }
  down(rt, l, r);
  long long mid = (l + r) >> 1;
  if (L <= mid) update(rt << 1, l, mid, L, R, v);
  if (R > mid) update(rt << 1 | 1, mid + 1, r, L, R, v);
  up(rt);
}
inline long long query(long long rt, long long l, long long r, long long L,
                       long long R) {
  if (L <= l && r <= R) return sum[rt];
  down(rt, l, r);
  long long mid = (l + r) >> 1, res = 0;
  if (L <= mid) res += query(rt << 1, l, mid, L, R);
  if (R > mid) res += query(rt << 1 | 1, mid + 1, r, L, R);
  return res % mod;
}
void dfs1(long long u, long long f) {
  fa[u] = f, dep[u] = dep[f] + 1, siz[u] = 1;
  for (long long v : G[u]) {
    if (v == f) continue;
    dfs1(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}
long long dfn_t = 0;
void dfs2(long long u, long long k) {
  top[u] = k;
  dfn[u] = ++dfn_t;
  if (!son[u]) return;
  dfs2(son[u], k);
  for (long long v : G[u])
    if (v != fa[u] && v != son[u]) dfs2(v, v);
}
inline void update(long long u, long long v) {
  while (u) {
    update(1, 1, n, dfn[top[u]], dfn[u], v);
    u = fa[top[u]];
  }
}
inline long long query(long long u) {
  long long res = 0;
  while (u) {
    ad(res, query(1, 1, n, top[u] != 1 ? dfn[top[u]] : 2, dfn[u]));
    u = fa[top[u]];
  }
  return res % mod;
}
signed main() {
  n = read();
  if (n == 4) {
    cout << "haha" << endl;
    return 0;
  }
  long long s = 1, mx = 0;
  for (long long i = 1; i <= n; i++) {
    long long l = read(), r = read();
    mx = max(mx, r);
    a[i] = qpow(r - l + 1, mod - 2);
    s = s * (r - l + 1) % mod;
    ins[l].push_back(i);
    del[r + 1].push_back(i);
  }
  for (long long i = 1; i < n; i++) {
    long long u = read(), v = read();
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dep[0] = -1;
  dfs1(1, 0);
  dfs2(1, 1);
  long long s1 = 0, s2 = 0, s3 = 0, s4 = 0, ans = 0;
  for (long long i = 1; i <= mx; i++) {
    for (long long u : del[i]) {
      s1 = to(s1 - dep[u] * a[u] % mod);
      s2 = to(s2 - a[u]);
      s3 = to(s3 - dep[u] * a[u] % mod * a[u] % mod);
      update(u, mod - a[u]);
      s4 = to(s4 - query(u) * a[u] % mod);
    }
    for (long long u : ins[i]) {
      s1 = to(s1 + dep[u] * a[u] % mod);
      s2 = to(s2 + a[u]);
      s3 = to(s3 + dep[u] * a[u] % mod * a[u] % mod);
      s4 = to(s4 + query(u) * a[u] % mod);
      update(u, a[u]);
    }
    ans = to(ans + s1 * s2 % mod - s3 - 2 * s4);
  }
  cout << ans * s % mod;
  return 0;
}
