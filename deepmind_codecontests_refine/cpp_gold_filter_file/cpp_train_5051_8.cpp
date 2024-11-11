#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int inf = 1000000000;
const int maxn = 1010005;
const int maxa = 300005;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  if (b < 0) return -1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int INF = 10000000;
namespace polysum {
const int D = 1010000;
long long a[D], f[D], g[D], p[D], p1[D], p2[D], b[D], h[D][2], C[D];
long long calcn(int d, long long *a, long long n) {
  if (n <= d) return a[n];
  p1[0] = p2[0] = 1;
  for (int i = 0; i < d + 1; i++) {
    long long t = (n - i + mod) % mod;
    p1[i + 1] = p1[i] * t % mod;
  }
  for (int i = 0; i < d + 1; i++) {
    long long t = (n - d + i + mod) % mod;
    p2[i + 1] = p2[i] * t % mod;
  }
  long long ans = 0;
  for (int i = 0; i < d + 1; i++) {
    long long t =
        g[i] * g[d - i] % mod * p1[i] % mod * p2[d - i] % mod * a[i] % mod;
    if ((d - i) & 1)
      ans = (ans - t + mod) % mod;
    else
      ans = (ans + t) % mod;
  }
  return ans;
}
void init(int M) {
  f[0] = f[1] = g[0] = g[1] = 1;
  for (int i = 2; i < M + 5; i++) f[i] = f[i - 1] * i % mod;
  g[M + 4] = powmod(f[M + 4], mod - 2);
  for (int i = M + 4 - 1; i >= 1; i--) g[i] = g[i + 1] * (i + 1) % mod;
}
long long polysum(long long n, long long *a, long long m) {
  a[m + 1] = calcn(m, a, m + 1);
  for (int i = 1; i < m + 2; i++) a[i] = (a[i - 1] + a[i]) % mod;
  return calcn(m + 1, a, n - 1);
}
long long qpolysum(long long R, long long n, long long *a, long long m) {
  if (R == 1) return polysum(n, a, m);
  a[m + 1] = calcn(m, a, m + 1);
  long long r = powmod(R, mod - 2), p3 = 0, p4 = 0, c, ans;
  h[0][0] = 0;
  h[0][1] = 1;
  for (int i = 1; i < m + 2; i++) {
    h[i][0] = (h[i - 1][0] + a[i - 1]) * r % mod;
    h[i][1] = h[i - 1][1] * r % mod;
  }
  for (int i = 0; i < m + 2; i++) {
    long long t = g[i] * g[m + 1 - i] % mod;
    if (i & 1)
      p3 = ((p3 - h[i][0] * t) % mod + mod) % mod,
      p4 = ((p4 - h[i][1] * t) % mod + mod) % mod;
    else
      p3 = (p3 + h[i][0] * t) % mod, p4 = (p4 + h[i][1] * t) % mod;
  }
  c = powmod(p4, mod - 2) * (mod - p3) % mod;
  for (int i = 0; i < m + 2; i++) h[i][0] = (h[i][0] + h[i][1] * c) % mod;
  for (int i = 0; i < m + 2; i++) C[i] = h[i][0];
  ans = (calcn(m, C, n) * powmod(R, n) - c) % mod;
  if (ans < 0) ans += mod;
  return ans;
}
}  // namespace polysum
long long prime[maxn], cnt;
bool isprime[maxn], vis[maxn];
long long a[maxn];
int n, k;
void Regen() {
  cnt = 0;
  a[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (!vis[i]) {
      prime[cnt++] = i;
      isprime[i] = true;
      a[i] = powmod(i, k);
    }
    for (long long j = 0; j < cnt && i * prime[j] < maxn; j++) {
      vis[i * prime[j]] = true;
      a[i * prime[j]] = a[i] * a[prime[j]] % mod;
      if (i % prime[j] == 0) break;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  if (k == 0) {
    cout << n << endl;
    return 0;
  }
  Regen();
  polysum::init(k + 10);
  long long ans = 0;
  ans = polysum::polysum(n + 1, a, k + 1);
  cout << ans << endl;
}
