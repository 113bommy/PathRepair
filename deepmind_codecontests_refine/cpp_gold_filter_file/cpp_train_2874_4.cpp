#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
const long long M = maxn;
const long long mod = 1e9 + 7;
long long n, val[maxn], ans = 1;
long long vis[maxn], sz[maxn], mn, siz, rt;
long long head[maxn], ecnt;
struct edge {
  long long to, next, w, c;
} e[maxn << 1];
struct BIT {
  long long c[maxn << 1], cnt[maxn << 1], fl[maxn << 1];
  inline long long lowbit(long long x) { return x & -x; }
  void add(long long x, long long val, long long tag) {
    x += M;
    for (; x < maxn * 2; x += lowbit(x))
      if (fl[x] == tag)
        c[x] = c[x] * val % mod, cnt[x]++;
      else
        c[x] = val, cnt[x] = 1, fl[x] = tag;
  }
  void query(long long x, long long tag, long long &p, long long &q) {
    p = 1, q = 0;
    x += M;
    for (; x; x -= lowbit(x))
      if (fl[x] == tag) p = p * c[x] % mod, q += cnt[x];
  }
} T1, T2;
struct node {
  long long s0, s1, w;
} st[maxn];
long long idx;
void adde(long long u, long long v, long long w, long long c) {
  e[++ecnt].to = v;
  e[ecnt].w = w;
  e[ecnt].c = c;
  e[ecnt].next = head[u];
  head[u] = ecnt;
}
long long read() {
  long long res = 0, f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (!isdigit(ch));
  do {
    res = res * 10 + ch - '0';
    ch = getchar();
  } while (isdigit(ch));
  return res * f;
}
long long qpow(long long x, long long k) {
  long long res = 1;
  x = (x % mod + mod) % mod;
  while (k) {
    if (k & 1) res = res * x % mod;
    x = x * x % mod;
    k >>= 1;
  }
  return res;
}
void find(long long u, long long fa) {
  sz[u] = 1;
  long long mx = 0;
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].to;
    if (v == fa || vis[v]) continue;
    find(v, u);
    sz[u] += sz[v];
    mx = max(mx, sz[v]);
  }
  mx = max(mx, siz - sz[u]);
  if (mx < mn) mn = mx, rt = u;
}
void dfs(long long u, long long fa, long long s0, long long s1, long long w) {
  st[++idx] = (node){s0, s1, w};
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].to;
    if (v == fa || vis[v]) continue;
    dfs(v, u, s0 + (e[i].c == 0), s1 + (e[i].c == 1), w * e[i].w % mod);
  }
}
long long tag = 0;
void calc(long long u, long long fa) {
  T1.add(0, 1, ++tag);
  T2.add(0, 1, tag);
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].to;
    if (v == fa || vis[v]) continue;
    idx = 0;
    dfs(v, u, e[i].c == 0, e[i].c != 0, e[i].w);
    for (long long i = (1); i <= (idx); ++i) {
      long long x, y;
      T1.query(2 * st[i].s0 - st[i].s1, tag, x, y);
      ans = ans * qpow(st[i].w, y) % mod * x % mod;
      T2.query(st[i].s0 - st[i].s1 * 2 - 1, tag, x, y);
      ans = ans * qpow(qpow(st[i].w, y) * x % mod, mod - 2) % mod;
    }
    for (long long i = (1); i <= (idx); ++i) {
      T1.add(st[i].s1 - 2 * st[i].s0, st[i].w, tag);
      T2.add(st[i].s1 * 2 - st[i].s0, st[i].w, tag);
    }
  }
}
void solve(long long u) {
  vis[u] = 1;
  calc(u, 0);
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].to;
    if (vis[v]) continue;
    mn = 0x3f3f3f3f;
    siz = sz[v];
    find(v, 0);
    solve(rt);
  }
}
signed main() {
  n = read();
  for (long long i = (2); i <= (n); ++i) {
    long long u = read(), v = read(), w = read(), c = read();
    adde(u, v, w, c);
    adde(v, u, w, c);
  }
  mn = 0x3f3f3f3f, siz = n;
  find(1, 0);
  solve(rt);
  printf("%lld\n", ans);
}
