#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 1, mod = 1e9 + 7, inv2 = 5e8 + 4;
int n, q;
int a[N], s[N];
int c[N][K + 5], has[N][K + 5];
int ksm(int a, int x) {
  int tot = 1;
  while (x) {
    if (x & 1ll) tot = 1ll * tot * a % mod;
    a = 1ll * a * a % mod;
    x >>= 1ll;
  }
  return tot;
}
int mul[N], inv[N];
int C(int m, int n) { return 1ll * mul[m] * inv[n] % mod * inv[m - n] % mod; }
int main() {
  mul[0] = inv[0] = 1;
  int lim = N - 5;
  for (int i = 1; i <= lim; i++) mul[i] = 1ll * mul[i - 1] * i % mod;
  inv[lim] = ksm(mul[lim], mod - 2);
  for (int i = lim - 1; i >= 1; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i], s[i] = (s[i - 1] + a[i]) % mod;
  for (int k = 0; k <= K; k++)
    for (int i = 1; i <= n; i++)
      has[i][k] = (has[i - 1][k] + ksm(a[i], k)) % mod,
      c[i][k] = (c[i - 1][k] + ksm(i, k)) % mod;
  while (q--) {
    int l, r, d, len;
    scanf("%d%d%d", &l, &r, &d);
    len = r - l + 1;
    int sum = (s[r] + mod - s[l - 1]) % mod;
    int a0 = 1ll *
             (sum + mod - 1ll * len * (len + 1) % mod * d % mod * inv2 % mod) %
             mod * ksm(len, mod - 2) % mod;
    bool fl = 1;
    for (int k = 1; k <= K; k++) {
      int tot = 0;
      for (int t = 0; t <= k; t++)
        tot = (tot + 1ll * C(k, t) * ksm(d, t) % mod * ksm(a0, k - t) % mod *
                         c[len][t]) %
              mod;
      if (tot != (has[r][k] + mod - has[l - 1][k]) % mod) {
        fl = 0;
        break;
      }
    }
    if (fl)
      puts("Yes");
    else
      puts("No");
  }
}
