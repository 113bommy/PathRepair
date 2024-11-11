#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, mod, cnt, p[105];
int fac[N], ifac[N], pre[N][20];
int Pow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = 1ll * ret * x % mod;
    k >>= 1;
    x = 1ll * x * x % mod;
  }
  return ret;
}
int C(int n, int m) {
  if (n < m || m < 0) return 0;
  int ret = 1ll * fac[n] * ifac[m] * ifac[n - m] % mod;
  for (int i = 1; i <= cnt; i++)
    ret = 1ll * ret * Pow(p[i], pre[n][i] - pre[m][i] - pre[n - m][i]) % mod;
  return ret;
}
void init() {
  int x = mod, phi = mod;
  for (int i = 2; i * i <= x; i++) {
    if (x % i) continue;
    while (x % i == 0) x /= i;
    p[++cnt] = i;
    phi = phi / i * (i - 1);
  }
  if (x != 1) p[++cnt] = x, phi = phi / x * (x - 1);
  ifac[0] = fac[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    int val = i;
    for (int j = 1; j <= cnt; j++) {
      pre[i][j] += pre[i - 1][j];
      while (val % p[j] == 0) val /= p[j], pre[i][j]++;
    }
    fac[i] = 1ll * fac[i - 1] * val % mod;
    ifac[i] = Pow(fac[i], phi - 1);
  }
}
int main() {
  int L, R;
  scanf("%d%d%d%d", &n, &mod, &L, &R);
  init();
  int ans = 0;
  for (int i = L; i <= n; i++)
    ans = (ans + 1ll * C(n, i) *
                     (1ll * C(i, (i + L + 1) / 2) -
                      C(i, min(i, (i + R) / 2) + 1) + mod)) %
          mod;
  cout << ans << "\n";
}
