#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
const long long mod = 998244353;
long long m;
long long f[N];
long long vis[N], p[N], mu[N], tot = 0;
long long pw1[N], pw2[N];
long long add(long long x) { return x >= mod ? x - mod : x; }
long long sub(long long x) { return x < 0 ? x + mod : x; }
void Add(long long &x, long long y) {
  if ((x += y) >= mod && (x -= mod))
    ;
}
void Sub(long long &x, long long y) {
  if ((x -= y) < 0 && (x += mod))
    ;
}
long long qpow(long long a, long long b) {
  long long res = 1;
  for (; b > 0; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) res = 1ll * res * a % mod;
  return res;
}
void sieve(long long n) {
  mu[1] = vis[1] = 1;
  for (long long i = 2; i <= n; i++) {
    if (!vis[i]) mu[i] = -1, p[++tot] = i;
    for (long long j = 1; j <= tot && p[j] * i <= n; j++) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) {
        mu[i * p[j]] = 0;
        break;
      }
      mu[i * p[j]] = -mu[i];
    }
  }
  return;
}
long long Pro(long long n) {
  if (n <= 0) return 0;
  return 1ll * n % mod * qpow(2, n - 1) % mod;
}
signed main() {
  scanf("%lld", &m);
  sieve((N - 10));
  for (long long i = 1; i <= m; i++) {
    long long x, c;
    scanf("%lld%lld", &x, &c);
    f[x] = c;
  }
  long long ans = 0;
  for (long long i = 1; i <= (N - 10); i++) {
    long long s = 0, t = 0, cnt = 0;
    for (long long j = i; j <= (N - 10); j += i) {
      cnt += f[j];
      Add(s, 1ll * f[j] % mod * j % mod);
      Add(t, 1ll * f[j] % mod * j % mod * j % mod);
    }
    long long sum = 0;
    Add(sum, 1ll * t * Pro(cnt - 1));
    s = 1ll * s * s % mod;
    Sub(s, t);
    if (cnt >= 2)
      Add(sum, 1ll * s * add(Pro(cnt - 2) + qpow(2, cnt - 2)) % mod);
    if (mu[i] == 1) Add(ans, sum);
    if (mu[i] == -1) Sub(ans, sum);
  }
  printf("%lld\n", ans);
  return 0;
}
