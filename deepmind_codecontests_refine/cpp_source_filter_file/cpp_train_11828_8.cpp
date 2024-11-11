#include <bits/stdc++.h>
using namespace std;
const int N = 262144;
int n, k, Mo, len, fac[N], inv[N], cnt[N], g[20][N], f[20][N], h[20][N];
int pwr(int x, int y) {
  int z = 1;
  for (; y; y >>= 1, x = (long long)x * x % Mo)
    if (y & 1) z = (long long)z * x % Mo;
  return z;
}
void inc(int &x, int y) { x = x + y >= Mo ? x + y - Mo : x + y; }
void dec(int &x, int y) { x = x - y < 0 ? x - y + Mo : x - y; }
void FWT(int *a, int len) {
  for (int i = 1; i < len; i <<= 1)
    for (int j = 0; j < len; j += i << 1)
      for (int k = 0; k < i; k++) inc(a[j + k + i], a[j + k]);
}
void IFWT(int *a, int len) {
  for (int i = 1; i < len; i <<= 1)
    for (int j = 0; j < len; j += i << 1)
      for (int k = 0; k < i; k++) dec(a[j + k + i], a[j + k]);
}
void power(int n) {
  if (!n) return;
  power(n >> 1);
  for (int i = 0; i <= cnt[n]; i++)
    for (int s = 0; s <= len - 1; s++) h[i][s] = 0;
  for (int i = 0; i <= cnt[n]; i++)
    for (int j = 0; j <= cnt[n] - i; j++)
      for (int s = 0; s <= len - 1; s++)
        (h[i + j][s] += (long long)f[i][s] * f[j][s] % Mo) %= Mo;
  for (int i = 0; i <= cnt[n]; i++)
    for (int s = 0; s <= len - 1; s++) f[i][s] = h[i][s];
  if (n & 1) {
    for (int i = 0; i <= cnt[n]; i++)
      for (int s = 0; s <= len - 1; s++) h[i][s] = 0;
    for (int i = 0; i <= cnt[n]; i++)
      for (int j = 0; j <= cnt[n] - i; j++)
        for (int s = 0; s <= len - 1; s++)
          (h[i + j][s] += (long long)f[i][s] * g[j][s] % Mo) %= Mo;
    for (int i = 0; i <= cnt[n]; i++)
      for (int s = 0; s <= len - 1; s++) f[i][s] = h[i][s];
  }
}
int main() {
  scanf("%d%d%d", &n, &k, &Mo);
  if (n & 1) {
    printf("%d\n", pwr(k, n));
    return 0;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (long long)fac[i - 1] * i % Mo;
  inv[n] = pwr(fac[n], Mo - 2);
  for (int i = n - 1; i >= 0; i--)
    inv[i] = (long long)inv[i + 1] * (i + 1) % Mo;
  for (int s = 1; s <= n; s++) cnt[s] = cnt[s ^ (s & -s)] + 1;
  for (int s = 0; s <= n; s++) g[cnt[s]][s] = inv[s];
  for (len = 1; len <= n; len <<= 1)
    ;
  for (int i = 0; i <= cnt[n]; i++) FWT(g[i], len);
  for (int i = 0; i <= len; i++) f[0][i] = 1;
  power(k);
  IFWT(f[cnt[n]], len);
  int ans = (long long)f[cnt[n]][n] * fac[n] % Mo;
  ans = (pwr(k, n) - ans + Mo) % Mo;
  printf("%d\n", ans);
  return 0;
}
