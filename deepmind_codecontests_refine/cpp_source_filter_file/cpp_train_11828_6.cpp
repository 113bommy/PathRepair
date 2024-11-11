#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
int inv[N], ifac[N], mod, n, K, limn, len, f[N][20], size[N], tmp[20], fac[N];
void prework(int n) {
  ifac[0] = inv[1] = 1;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 2; i <= n; i++)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 1; i <= n; i++) ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
}
int qpower(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
void FWT(int a[N][20]) {
  for (int i = 1; i < limn; i <<= 1)
    for (int j = 0; j < limn; j += i << 1)
      for (int k = 0; k < i; k++)
        for (int t = 0; t <= len; t++)
          a[i + j + k][t] = (a[i + j + k][t] + a[j + k][t]) % mod;
}
void IFWT(int a[N][20]) {
  for (int i = 1; i < limn; i <<= 1)
    for (int j = 0; j < limn; j += i << 1)
      for (int k = 0; k < i; k++)
        for (int t = 0; t <= len; t++)
          a[i + j + k][t] = (a[i + j + k][t] - a[j + k][t]) % mod;
}
int main() {
  scanf("%d%d%d", &n, &K, &mod);
  if (n & 1) {
    cout << qpower(K, n) << endl;
    return 0;
  }
  prework(n);
  limn = 1, len = 0;
  while (limn <= n) limn <<= 1, len++;
  for (int i = 0; i <= n; i++) {
    size[i] = size[i >> 1] + (i & 1);
    f[i][size[i]] = ifac[i];
  }
  FWT(f);
  for (int S = 0; S < limn; S++) {
    tmp[0] = qpower(f[S][0], K);
    for (int j = 0; j < len; j++) {
      int x = 0;
      for (int k = 0; k <= j; k++)
        x = (x + 1ll * (k + 1) * f[S][k + 1] % mod * tmp[j - k]) % mod;
      x = 1ll * x * K % mod;
      for (int k = 0; k < j; k++)
        x = (x - 1ll * (k + 1) * tmp[k + 1] % mod * f[S][j - k]) % mod;
      tmp[j + 1] = 1ll * x * inv[j + 1];
    }
    for (int j = 0; j <= len; j++) f[S][j] = tmp[j];
  }
  IFWT(f);
  int ans = (qpower(K, n) - 1ll * f[n][size[n]] * fac[n]) % mod;
  cout << (ans + mod) % mod << endl;
}
