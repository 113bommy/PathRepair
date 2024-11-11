#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const long long Mod = 998244353;
int n, a[N], b[N], c[2 * N], t;
long long f[N], g[N], ans, inv[N];
long long in(long long x) {
  long long b = Mod - 2, ans = 1;
  while (b) {
    if (b & 1) ans = (1ll * (ans) * (x) % Mod);
    x = (1ll * (x) * (x) % Mod);
    b >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  inv[0] = inv[1] = 1;
  for (int i = 2; i < N; ++i)
    inv[i] = (1ll * (Mod - Mod / i) * (inv[Mod % i]) % Mod);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &a[i], &b[i]), c[++t] = a[i], c[++t] = ++b[i];
  sort(c + 1, c + 1 + t);
  t = unique(c + 1, c + 1 + t) - c - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(c + 1, c + 1 + t, a[i]) - c;
    b[i] = lower_bound(c + 1, c + 1 + t, b[i]) - c;
  }
  f[0] = 1;
  for (int j = t - 1; j; j--) {
    long long l = c[j + 1] - c[j];
    g[0] = 1;
    for (int i = 1; i <= n; i++)
      g[i] =
          ((1ll * ((1ll * (g[i - 1]) * ((l + i - 1)) % Mod)) * (inv[i]) % Mod));
    for (int i = n; i; i--)
      if (a[i] <= j && j < b[i])
        for (int c = 1, k = i - 1; ~k; k--, c++) {
          f[i] = (f[i] + (1ll * (g[c]) * (f[k]) % Mod)) % Mod;
          if (a[k] > j || j >= b[k]) break;
        }
  }
  ans = f[n];
  for (int i = 1; i <= n; i++)
    ans = (1ll * (ans) * (in(c[b[i]] - c[a[i]])) % Mod);
  printf("%lld", ans);
}
