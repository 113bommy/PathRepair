#include <bits/stdc++.h>
using namespace std;
int T, n, m, tot;
long long f[1000005], sum[3][1000005], g[1000005], phi[1000005], prime[1000005];
bool vst[1000005];
const long long mod = 1e9 + 7, inv3 = 333333336;
inline int read() {
  int w = 0, f = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    w = (w << 1) + (w << 3) + ch - '0', ch = getchar();
  return w * f;
}
int main() {
  phi[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    if (!vst[i]) prime[++tot] = i, phi[i] = i - 1;
    for (int j = 1; j <= tot && i * prime[j] <= 1000000; j++) {
      vst[i * prime[j]] = true;
      if (!(i % prime[j])) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
      phi[i * prime[j]] = phi[i] * phi[prime[j]];
    }
  }
  for (int i = 1; i <= 1000000; i++)
    for (int j = i; j <= 1000000; j += i)
      (f[j] += phi[i] * (j / i) % mod) %= mod;
  for (int i = 1; i <= 1000000; i++) {
    g[i] = (i * (i + 1) % mod * (2 * i + 1) % mod * inv3 % mod -
            3 * i % mod * i % mod + mod + 2 * f[i] % mod) %
           mod,
    sum[0][i] = (sum[0][i - 1] + g[i]) % mod,
    sum[1][i] = (sum[1][i - 1] + g[i] * (i - 1) % mod) % mod,
    sum[2][i] = (sum[2][i - 1] + g[i] * (i - 1) % mod * (i - 1) % mod) % mod;
  }
  T = read();
  for (; T; T--)
    n = read(), m = read(),
    printf("%I64d\n",
           (1ll * n * m % mod * sum[0][min(n, m)] % mod -
            (n + m) * sum[1][min(n, m)] % mod + mod + sum[2][min(n, m)]) %
               mod);
  return 0;
}
