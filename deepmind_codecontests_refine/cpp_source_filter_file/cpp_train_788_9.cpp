#include <bits/stdc++.h>
using namespace std;
const int N = 200050, mod = 1000000007;
int n, a[N], ans1, ans2, tot, fac[N], inv[N];
int C(int x, int y) { return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod; }
int pow(int x, int y) {
  int r = 1;
  while (y) {
    if (y & 1) r = 1ll * r * x % mod;
    x = 1ll * x * x % mod, y >>= 1;
  }
  return r;
}
int main() {
  scanf("%d", &n), fac[0] = 1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), tot += n - 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 0; i <= n; i++) inv[i] = pow(fac[i], mod - 2);
  if (n == 1) {
    printf("%d\n", a[1]);
    return 0;
  }
  if (n & 1) {
    for (int i = 0; i < n; i++)
      a[i] = i & 1 ? (a[i] + a[i + 1]) : (a[i] - a[i + 1]);
    n--;
  }
  for (int i = 1; i <= n; i += 2)
    ans1 = (ans1 + 1ll * a[i] * C(n / 2 - 1, i / 2)) % mod;
  for (int i = 2; i <= n; i += 2)
    ans2 = (ans2 + 1ll * a[i] * C(n / 2 - 1, i / 2 - 1)) % mod;
  printf("%d\n", ((tot & 1 ? ans1 + ans2 : ans1 - ans2) + mod) % mod);
}
