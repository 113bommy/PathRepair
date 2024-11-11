#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100000;
const long long mod = 1e9 + 7;
struct edge {
  long long to, nxt;
} e[maxn * 3 + 5];
set<long long> g[maxn + 5];
map<long long, long long> c[maxn + 5];
long long h[maxn + 5], cnt = 0;
long long n;
long long a[maxn + 5];
long long ans = 0;
long long Gcd(long long a, long long b) {
  if (b == 0) return a;
  return Gcd(b, a % b);
}
long long GCD(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return Gcd(a, b);
}
void add(long long u, long long v) {
  cnt++;
  e[cnt].to = v;
  e[cnt].nxt = h[u];
  h[u] = cnt;
  return;
}
void add(long long a, long long b, long long x, long long y) {
  c[a][b] += c[x][y];
  return;
}
void dfs(long long u, long long fa) {
  for (set<long long>::iterator it = g[fa].begin(); it != g[fa].end(); it++) {
    long long gcd = GCD(*it, a[u]);
    g[u].insert(gcd);
    add(u, gcd, fa, *it);
    long long cnt = c[u][gcd];
    gcd = gcd % mod;
    cnt *= gcd;
    cnt %= mod;
    ans = (ans + cnt) % mod;
  }
  g[u].insert(a[u]);
  c[u][a[u]]++;
  ans = (ans + a[u]) % mod;
  for (register long long i = h[u]; i; i = e[i].nxt) {
    long long v = e[i].to;
    if (v == fa) continue;
    dfs(v, u);
  }
  return;
}
signed main() {
  scanf("%lld", &n);
  for (register long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  long long u, v;
  for (register long long i = 1; i <= n - 1; i++) {
    scanf("%lld%lld", &u, &v);
    add(u, v);
    add(v, u);
  }
  dfs(1, 0);
  printf("%lld\n", ans);
  return 0;
}
