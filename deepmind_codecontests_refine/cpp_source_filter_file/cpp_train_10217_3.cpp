#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
int fac[maxn], invf[maxn], mp[maxn], np[maxn];
int fpow(int x, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    n >>= 1;
  }
  return res;
}
int A(int n, int m) { return 1ll * fac[n] * invf[n - m] % mod; }
int C(int n, int m) {
  return 1ll * fac[n] * invf[m] % mod * 1ll * invf[n - m] % mod;
}
int n, m, a, b;
void init() {
  np[0] = mp[0] = fac[0] = invf[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fac[i] = 1ll * fac[i - 1] * i % mod;
    mp[i] = 1ll * mp[i - 1] * m % mod;
    np[i] = 1ll * np[i - 1] * n % mod;
  }
  invf[maxn - 1] = fpow(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 1; i--)
    invf[i] = 1ll * invf[i + 1] * (i + 1) % mod;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  init();
  int ans = 0;
  for (int i = 0; i <= min(n - 2, m - 1); i++) {
    int temp = 1ll * C(m - 1, i) * A(n - 2, i) % mod;
    temp = 1ll * temp * mp[n - i - 2] % mod;
    if (i < n - 2) {
      temp = 1ll * temp * (2 + i) % mod;
      temp = 1ll * temp * np[n - 3 - i];
    }
    ans = (ans + temp) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
