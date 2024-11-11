#include <bits/stdc++.h>
using namespace std;
inline int Get() {
  int res = 0, q = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') q = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return res * q;
}
const double eps = 1e-12, pi = M_PI;
const int oo = (int)2e9, mod = (int)1e9 + 7;
const long long INF = (long long)1e17;
const int N = (int)1e6;
typedef long long arr[N + 10];
bool pri[N + 10];
arr f, g, phi, sum, sqrsum, prm;
long long s[N + 10][3], n, m;
int T;
void Prepare() {
  phi[1] = 1;
  for (long long i = (2), end = (N); i <= end; ++i) {
    if (!pri[i]) prm[++m] = i, phi[i] = i - 1;
    for (long long j = (1), end = (m); j <= end; ++j) {
      if (i * prm[j] > N) break;
      pri[i * prm[j]] = 1;
      if (i % prm[j])
        phi[i * prm[j]] = phi[i] * (prm[j] - 1);
      else {
        phi[i * prm[j]] = phi[i] * prm[j];
        break;
      }
    }
  }
  for (long long i = (1), end = (N); i <= end; ++i) {
    for (int j = 1; i * j <= N; ++j) {
      g[i * j] = (g[i * j] + i * phi[j]) % mod;
    }
  }
  for (long long i = (1), end = (N); i <= end; ++i)
    sum[i] = (sum[i - 1] + i) % mod, sqrsum[i] = (sqrsum[i - 1] + i * i) % mod,
    g[i] = (g[i] - i + mod) % mod;
  for (long long i = (1), end = (N); i <= end; ++i) {
    f[i] = (i >> 1) * i * i % mod,
    f[i] = (f[i] - 4 * i % mod * sum[i >> 1] % mod + mod) % mod,
    f[i] = (f[i] + 4 * sqrsum[i >> 1]) % mod;
    f[i] = (f[i] << 1) % mod,
    f[i] = (f[i] + 2 * (i * sum[i - 1] - sqrsum[i - 1]) % mod + mod) % mod,
    f[i] = (f[i] + 2 * g[i]) % mod;
    f[i] = (f[i] - i * i % mod + mod) % mod, f[i] = (f[i] + 2 * i) % mod;
    s[i][0] = (s[i - 1][0] + f[i]) % mod,
    s[i][1] = (s[i - 1][1] + f[i] * (i - 1) % mod) % mod;
    s[i][2] = (s[i - 1][2] + f[i] * (i - 1) % mod * (i - 1)) % mod;
  }
}
int main() {
  Prepare();
  for (scanf("%d"
             "\n",
             &T);
       T; --T) {
    scanf(
        "%I64d"
        "%I64d"
        "\n",
        &n, &m);
    long long L = ((n) < (m) ? (n) : (m)), ans = 0;
    ans = (ans + n * m % mod * s[L][0]) % mod;
    ans = (ans - (n + m) * s[L][1] % mod + mod) % mod;
    ans = (ans + s[L][2]) % mod;
    printf(
        "%I64d"
        "\n",
        ans);
  }
  return 0;
}
