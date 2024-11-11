#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 505;
const long long M = 1e6 + 5;
long long n, A, B, ans, p[M], gs[M], fa[M], jc[M], inv[M], g[M], f[M], a[M],
    vis[N][N], dp[N][N];
inline long long read() {
  long long res = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    res = res * 10 + c - 48;
    c = getchar();
  }
  return res * f;
}
long long find(long long x) {
  if (fa[x] == x) return x;
  fa[x] = find(fa[x]);
  return fa[x];
}
void Add(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
long long C(long long n, long long m) {
  return jc[n] * inv[m] % mod * inv[n - m] % mod;
}
long long solve(long long A, long long B) {
  if (A == 0) return jc[B];
  if (vis[A][B]) return dp[A][B];
  vis[A][B] = 1;
  long long res = 0;
  if (A > 0) res = (res + solve(A - 1, B) % mod) % mod;
  if (A > 1) res = (res + (A - 1) * solve(A - 2, B) % mod) % mod;
  for (long long i = 1; i <= B; i++) {
    if (A > 0)
      res = (res + jc[i] * C(B, i) % mod * solve(A - 1, B - i) % mod) % mod;
    if (A > 1)
      res = (res + (A - 1) * jc[i + 1] % mod * C(B, i) % mod *
                       solve(A - 2, B - i) % mod) %
            mod;
  }
  dp[A][B] = res;
  return res;
}
signed main() {
  n = read();
  jc[0] = jc[1] = inv[0] = inv[1] = 1;
  for (long long i = 2; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
  for (long long i = 2; i <= n; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (long long i = 2; i <= n; i++) inv[i] = inv[i - 1] * inv[i] % mod;
  for (long long i = 1; i <= n; i++) {
    a[i] = read();
    if (a[i] == 1)
      A++;
    else
      B++;
  }
  if (n <= 500)
    cout << solve(A, B);
  else {
    f[1] = 1;
    f[2] = 2;
    for (long long i = 3; i <= A; i++)
      f[i] = ((i - 1) * f[i - 2] % mod + f[i - 1]) % mod;
    ans = f[A];
    for (long long i = 1; i <= B; i++) ans = ans * (n - i + 1) % mod;
    cout << ans;
  }
  return 0;
}
