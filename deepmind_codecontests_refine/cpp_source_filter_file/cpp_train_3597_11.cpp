#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 100005;
const int M = 1505;
int d[N], d1[N];
int f[M], L[M], R[M], s[M], g[M];
int pw(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * a * ans % mod;
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  int n, m, a, b, k;
  scanf("%d%d%d%d%d", &n, &m, &a, &b, &k);
  int p = 1LL * a * pw(b, mod - 2) % mod;
  int c = 1, m1 = 1, m2 = pw((mod + 1 - p) % mod, k);
  d[0] = m2;
  for (int i = 1; i <= k; i++) {
    c = 1LL * c * (k - i + 1) % mod * pw(i, mod - 2) % mod;
    m1 = 1LL * m1 * p % mod;
    m2 = 1LL * m2 * pw((mod + 1 - p) % mod, mod - 2) % mod;
    d[i] = 1LL * c * m1 % mod * m2 % mod;
  }
  for (int i = 1; i <= m; i++) d1[i] = (d1[i - 1] + d[i - 1]) % mod;
  s[m] = f[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      s[j] = 1LL * d[m - j] *
             ((1LL * (f[i - 1] - R[j] + mod) % mod * d1[j] % mod - g[j] + mod) %
              mod) %
             mod;
    for (int j = 1; j <= m; j++) L[j] = (L[j - 1] + s[j - 1]) % mod;
    for (int j = 1; j <= m; j++)
      f[i] = (f[i] + s[j]) % mod, R[j] = L[m - j + 1];
    for (int j = 1; j <= m; j++)
      g[j] = (g[j - 1] + 1LL * d[j - 1] * L[j] % mod) % mod;
  }
  printf("%d\n", f[n]);
}
