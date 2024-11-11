#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int food, wine, h;
int f[N << 1], inv[N << 1];
int fp(int x, int n) {
  int ret = 1;
  while (n) {
    if (n & 1) ret = 1ll * x * ret % mod;
    n >>= 1;
    x = 1ll * x * x % mod;
  }
  return ret;
}
int c(int n, int m) {
  if (n < m) return 0;
  if (m == 0) return 1;
  return 1ll * f[n] * inv[n - m] % mod * inv[m] % mod;
}
int main() {
  f[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < N + N; ++i) {
    f[i] = 1ll * i * f[i - 1] % mod;
    inv[i] = fp(f[i], mod - 2);
  }
  scanf("%d%d%d", &food, &wine, &h);
  if (food == 0) {
    if (wine <= h + 1)
      printf("0\n");
    else
      printf("1\n");
    return 0;
  }
  if (wine == 0) {
    printf("1\n");
    return 0;
  }
  int fz = 0, fm = 1ll * f[food + wine] * inv[food] % mod * inv[wine] % mod;
  for (int i = 1; i <= food + 1; ++i) {
    long long tmp = 1ll * i * (h + 1);
    if (tmp > wine) break;
    tmp = wine - tmp;
    int t = c(food + 1, i);
    fz = (fz + 1ll * t * c(tmp + i - 1, i - 1) % mod) % mod;
  }
  fz = 1ll * fz * fp(fm, mod - 2) % mod;
  printf("%d\n", fz);
  return 0;
}
