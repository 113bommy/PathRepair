#include <bits/stdc++.h>
using namespace std;
int const p = 1e9 + 7, inv = (p + 1) / 2;
int a[131073], b[131073], c[131073], r[18][131073], s[18][131073], fib[131073];
void fwtor(int *f, int n, int op) {
  for (int len = 2; len <= n; len <<= 1)
    for (int i = 0; i < n; i += len)
      for (int j = i; j < i + (len >> 1); j++)
        if (op == 1)
          f[j + (len >> 1)] += f[j], f[j + (len >> 1)] %= p;
        else
          f[j + (len >> 1)] += (p - f[j]), f[j + (len >> 1)] %= p;
}
void fwtand(int *f, int n, int op) {
  for (int len = 2; len <= n; len <<= 1)
    for (int i = 0; i < n; i += len)
      for (int j = i; j < i + (len >> 1); j++)
        if (op == 1)
          f[j] += f[j + (len >> 1)], f[j] %= p;
        else
          f[j] += (p - f[j + (len >> 1)]), f[j] %= p;
}
void fwtxor(int *f, int n, int op) {
  for (int len = 2; len <= n; len <<= 1)
    for (int i = 0; i < n; i += len)
      for (int j = i; j < i + (len >> 1); j++) {
        f[j] += f[j + (len >> 1)], f[j] %= p,
            f[j + (len >> 1)] = (((f[j] - 2 * f[j + (len >> 1)]) % p) + p) % p;
        if (op == -1)
          f[j] = 1ll * f[j] * inv % p,
          f[j + (len >> 1)] = 1ll * f[j + (len >> 1)] * inv % p;
      }
}
int main() {
  int q, x, n, m;
  scanf("%d", &q);
  n = (1 << 17), m = 17;
  for (int i = 0; i < q; i++) scanf("%d", &x), a[x]++;
  for (int i = 0; i < n; i++)
    b[i] = c[i] = a[i], r[__builtin_popcount(i)][i] = a[i];
  for (int i = 0; i <= m; i++) fwtor(r[i], n, 1);
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k < n; k++)
        s[i][k] += 1ll * r[j][k] * r[i - j][k] % p, r[i][k] %= p;
  for (int i = 0; i <= m; i++) fwtor(s[i], n, -1);
  fib[1] = 1;
  for (int i = 2; i < n; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % p;
  for (int i = 0; i < n; i++)
    a[i] = 1ll * fib[i] * s[__builtin_popcount(i)][i] % p;
  fwtxor(c, n, 1);
  for (int i = 0; i < n; i++) c[i] = 1ll * c[i] * c[i] % p;
  fwtxor(c, n, -1);
  for (int i = 0; i < n; i++)
    b[i] = 1ll * b[i] * fib[i] % p, c[i] = 1ll * c[i] * fib[i] % p;
  fwtand(a, n, 1), fwtand(b, n, 1), fwtand(c, n, 1);
  for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * b[i] % p * c[i] % p;
  fwtand(a, n, -1);
  int ans = 0;
  for (int i = 0; i < m; i++) ans += a[1 << i], ans %= p;
  printf("%d\n", ans);
  return 0;
}
