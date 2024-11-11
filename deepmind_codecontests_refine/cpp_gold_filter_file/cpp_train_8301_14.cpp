#include <bits/stdc++.h>
int n, ans, md = 998244353, num[1000010], b[1000010], c[1000010], inv[1000010],
            p[1000010], q[1000010], r[1000010];
int power(int x, int p) {
  int num = 1;
  while (p) {
    if (p & 1) num = (long long)num * x % md;
    x = (long long)x * x % md;
    p >>= 1;
  }
  return num;
}
int main() {
  scanf("%d", &n);
  num[0] = inv[0] = b[0] = p[0] = r[0] = 1;
  for (int i = 1; i <= n; ++i) num[i] = (long long)num[i - 1] * i % md;
  for (int i = 1; i <= n; ++i) b[i] = (long long)b[i - 1] * num[i] % md;
  c[n] = power(b[n], md - 2);
  for (int i = n - 1; i; --i) c[i] = (long long)num[i + 1] * c[i + 1] % md;
  for (int i = 1; i <= n; ++i) inv[i] = (long long)b[i - 1] * c[i] % md;
  for (int i = 0; i <= n + 1; ++i) q[i] = (i & 1 ? md - 1 : 1);
  for (int i = 1; i <= n; ++i) p[i] = (long long)p[i - 1] * 3 % md;
  for (int i = 1; i <= n; ++i) r[i] = (long long)r[i - 1] * p[n] % md;
  for (int i = 1; i <= n; ++i)
    ans = (ans + (long long)q[i + 1] *
                     ((long long)num[n] * inv[i] % md * inv[n - i] % md) % md *
                     p[i] % md * r[n - i] % md) %
          md;
  ans = (ans << 1) % md;
  for (int i = 0; i < n; ++i) {
    long long x =
        (power((1 + md - p[i]) % md, n) + md - (long long)q[n] * r[i] % md) %
        md;
    ans = (ans + 3ll * q[i + 1] % md *
                     ((long long)num[n] * inv[i] % md * inv[n - i] % md) % md *
                     x % md) %
          md;
  }
  printf("%d\n", ans);
  return 0;
}
