#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
long long n, m, fac[maxn], inv[maxn], idx;
long long vis[maxn], mn, rt, sz[maxn], siz;
long long head[maxn], ecnt;
struct edge {
  long long to, next, w;
} e[maxn << 1];
map<long long, long long> cnt;
pair<long long, long long> dig[maxn];
void adde(long long u, long long v, long long w) {
  e[++ecnt].to = v;
  e[ecnt].w = w;
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
void dfs(long long u, long long fa, long long d1, long long d2, long long d) {
  if (d >= 0) cnt[d1]++, dig[++idx] = make_pair(d2, d);
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].to;
    if (v == fa || vis[v]) continue;
    dfs(v, u, (d1 + e[i].w * fac[d + 1]) % m, (d2 * 10 + e[i].w) % m, d + 1);
  }
}
long long calc(long long u, long long d) {
  cnt.clear();
  idx = 0;
  long long res = 0;
  if (d)
    dfs(u, 0, d % m, d % m, 0);
  else
    dfs(u, 0, d, d, -1);
  for (long long i = (1); i <= (idx); ++i) {
    long long x = dig[i].first, y = dig[i].second;
    long long z = (-x * inv[y + 1] + m) % m;
    if (cnt.find(z) != cnt.end()) res += cnt[z];
    if (d == 0 && x == 0) res++;
  }
  if (d == 0) res += cnt[0];
  return res;
}
long long solve(long long u) {
  vis[u] = 1;
  long long res = calc(u, 0);
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].to;
    if (vis[v]) continue;
    res -= calc(v, e[i].w);
    mn = 0x3f3f3f3f;
    siz = sz[v];
    find(v, 0);
    res += solve(rt);
  }
  return res;
}
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, x, y);
  long long t = x;
  x = y;
  y = t - a / b * y;
}
long long Inv(long long a, long long b) {
  long long x, y;
  exgcd(a, b, x, y);
  x = (x % b + b) % b;
  return x;
}
signed main() {
  n = read();
  m = read();
  fac[0] = 1;
  for (long long i = (1); i <= (n); ++i)
    fac[i] = fac[i - 1] * 10 % m, inv[i] = Inv(fac[i], m);
  for (long long i = (2); i <= (n); ++i) {
    long long u = read() + 1, v = read() + 1, w = read();
    adde(u, v, w);
    adde(v, u, w);
  }
  mn = 0x3f3f3f3f;
  siz = n;
  find(1, 0);
  printf("%lld\n", solve(rt));
}
