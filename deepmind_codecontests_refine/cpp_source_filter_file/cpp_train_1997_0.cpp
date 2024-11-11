#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int n, x = 0, y = 0, w = 1, fac[200010], ifac[200010], inv[200010], a[200010];
long long m, sum[200010];
int& qmo(int& x) { return x += (x >> 31) & mod; }
void init(int N) {
  fac[0] = inv[1] = ifac[0] = 1;
  for (int i = 1; i <= N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 2; i <= N; i++)
    inv[i] = mod - 1ll * inv[mod % i] * (mod / i) % mod;
  for (int i = 1; i <= N; i++) ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
}
int C(int n, int m) {
  if (n < m || m < 0) return 0;
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}
int S(int n, long long m) {
  if (n < 0 || m < 0) return 0;
  m = min(1ll * n, m);
  while (x < n) {
    qmo(qmo(w = w + w - mod) -= C(x, y));
    x++;
  }
  while (x > n) {
    w = 1ll * (w - C(x - 1, y) + mod) * inv[2] % mod;
    x--;
  }
  while (y < m) {
    qmo(w += C(x, y + 1) - mod);
    y++;
  }
  while (y > m) {
    qmo(w -= C(x, y));
    y--;
  }
  return w;
}
int main() {
  scanf("%d%lld", &n, &m);
  init(n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
  int res = 0;
  for (int i = 1, nw = inv[2]; i <= n; i++, nw = 1ll * nw * inv[2] % mod) {
    res = (res + 1ll * nw * S(i, m - sum[i])) % mod;
  }
  printf("%d\n", res);
}
