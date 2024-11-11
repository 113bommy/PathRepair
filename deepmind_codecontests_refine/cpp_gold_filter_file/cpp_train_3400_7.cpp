#include <bits/stdc++.h>
using namespace std;
namespace FGF {
int n, A, B;
const int N = 1e6 + 5, mo = 998244353, g = 3, gi = (mo + 1) / g;
;
int ans[N], r[N], lim, fac[N], inv[N];
int qpow(int x, int y) {
  int s = 1;
  while (y) {
    if (y & 1) s = 1ll * s * x % mo;
    x = 1ll * x * x % mo, y >>= 1;
  }
  return s;
}
void NTT(int *y, int op) {
  for (int i = 0; i < lim; i++)
    if (r[i] < i) swap(y[i], y[r[i]]);
  for (int l = 1; l < lim; l <<= 1) {
    int wn = qpow(op == 1 ? g : gi, (mo - 1) / (l << 1));
    for (int i = 0; i < lim; i += (l << 1))
      for (int j = 0, w = 1; j < l; j++, w = 1LL * w * wn % mo) {
        int tmp = (y[i + j] - 1LL * w * y[i + j + l] % mo + mo) % mo;
        y[i + j] = (y[i + j] + 1LL * w * y[i + j + l] % mo) % mo,
              y[i + j + l] = tmp;
      }
  }
  if (op == -1) {
    for (int i = 0, inv = qpow(lim, mo - 2); i < lim; i++)
      y[i] = 1LL * y[i] * inv % mo;
  }
}
void solve(int *ans, int n) {
  if (n == 1) {
    ans[1] = 1;
    return;
  }
  if (!n) {
    ans[0] = 1;
    return;
  }
  solve(ans, n >> 1);
  static int tmp[N], g[N];
  for (int i = 0, fac = 1; i <= n / 2; i++, fac = 1ll * fac * i % mo)
    g[i] = 1ll * ans[i] * fac % mo;
  for (int i = 0, fac = 1; i <= n / 2; i++, fac = 1ll * fac * i % mo)
    tmp[n / 2 - i] = 1ll * qpow(n / 2, i) * qpow(fac, mo - 2) % mo;
  for (lim = 1; lim <= n; lim <<= 1)
    ;
  for (int i = 0; i < lim; i++) r[i] = r[i >> 1] >> 1 | (i & 1) * (lim >> 1);
  for (int i = n / 2 + 1; i < lim; i++) g[i] = tmp[i] = 0;
  NTT(g, 1), NTT(tmp, 1);
  for (int i = 0; i < lim; i++) g[i] = 1ll * g[i] * tmp[i] % mo, tmp[i] = 0;
  NTT(g, -1);
  for (int i = 0, fac = 1; i <= n / 2; i++, fac = 1ll * fac * i % mo)
    g[i] = 1ll * g[i + n / 2] * qpow(fac, mo - 2) % mo;
  for (int i = n / 2 + 1; i < lim; i++) g[i] = 0;
  NTT(g, 1), NTT(ans, 1);
  for (int i = 0; i < lim; i++) ans[i] = 1ll * ans[i] * g[i] % mo, g[i] = 0;
  NTT(ans, -1);
  if (n & 1) {
    for (int i = n; i; i--)
      ans[i] = (ans[i - 1] + 1ll * ans[i] * (n - 1) % mo) % mo;
    ans[0] = 1ll * ans[0] * (n - 1) % mo;
  }
}
void work() {
  scanf("%d%d%d", &n, &A, &B);
  solve(ans, n - 1);
  fac[0] = inv[0] = inv[1] = 1;
  for (int i = 1; i <= A + B; i++) fac[i] = 1ll * fac[i - 1] * i % mo;
  for (int i = 2; i <= max(A, B); i++)
    inv[i] = 1ll * inv[mo % i] * (mo - mo / i) % mo;
  for (int i = 2; i <= max(A, B); i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mo;
  printf("%lld", 1ll * ans[A + B - 2] % mo * fac[A + B - 2] % mo * inv[A - 1] %
                     mo * inv[B - 1] % mo);
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}
