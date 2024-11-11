#include <bits/stdc++.h>
using namespace std;
template <typename tn>
void read(tn &a) {
  tn x = 0, f = 1;
  char c = ' ';
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  a = x * f;
}
const int N = 2010, K = 201000, mod = 1e9 + 7;
int s[N], n, m, a, b, k, f[N][N];
long long fac[K], ifac[K], q[K];
long long fp(long long a, long long k) {
  long long ans = 1;
  for (; k; k >>= 1, a = a * a % mod)
    if (k & 1) ans = a * ans % mod;
  return ans;
}
int main() {
  read(n);
  read(m);
  read(a);
  read(b);
  read(k);
  long long P = a * fp(b, mod - 2) % mod;
  fac[0] = 1;
  for (int i = 1; i <= k; i++) fac[i] = fac[i - 1] * i % mod;
  ifac[k] = fp(fac[k], mod - 2);
  for (int i = k; i; i--) ifac[i - 1] = ifac[i] * i % mod;
  for (int i = 0; i <= m && i <= k; i++)
    q[i] = fp(P, i) * fp(1 - P, k - i) % mod * fac[k] % mod * ifac[i] % mod *
           ifac[k - i] % mod;
  f[0][m] = 1;
  for (int i = 1; i <= n; i++) {
    s[0] = f[i - 1][0];
    for (int j = 1; j <= m; j++) s[j] = (s[j - 1] + f[i - 1][j]) % mod;
    long long s1 = q[0], s2 = 0;
    for (int j = 1; j <= m; j++) {
      f[i][j] = ((s[m] - s[m - j]) * s1 - s2) % mod * q[m - j] % mod;
      s1 = (s1 + q[j]) % mod;
      s2 = (s2 + s[j] * q[j]) % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) ans = (ans + f[n][i]) % mod;
  cout << (ans + mod) % mod << '\n';
  return 0;
}
