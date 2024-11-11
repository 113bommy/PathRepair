#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
const int inv2 = (Mod + 1) / 2;
const int inv4 = 1ll * inv2 * inv2 % Mod;
int fpow(int a, int b) {
  int ans = 1, t = a;
  while (b) {
    if (b & 1) ans = 1ll * ans * t % Mod;
    t = 1ll * t * t % Mod;
    b >>= 1;
  }
  return ans;
}
void fwt(int* a, int n) {
  for (int step = 1; step < n; step <<= 1)
    for (int i = 0; i < n; i += step << 1)
      for (int j = i; j < i + step; j++) {
        int x = a[j], y = a[j + step];
        a[j] = (x + y) % Mod;
        a[j + step] = (x - y + Mod) % Mod;
      }
  return;
}
void ifwt(int* a, int n) {
  for (int step = 1; step < n; step <<= 1)
    for (int i = 0; i < n; i += step << 1)
      for (int j = i; j < i + step; j++) {
        int x = a[j], y = a[j + step];
        a[j] = 1ll * (x + y) * inv2 % Mod;
        a[j + step] = 1ll * (x - y + Mod) * inv2 % Mod;
      }
  return;
}
int x, y, z;
const int M = 17;
int ans[1 << M];
int f[1 << M];
int g[1 << M];
int h[1 << M];
int a[100010];
int b[100010];
int c[100010];
int main() {
  int n, k, sum = 0;
  scanf("%d %d", &n, &k);
  scanf("%d %d %d", &x, &y, &z);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
    sum ^= a[i];
    b[i] ^= a[i];
    c[i] ^= a[i];
    f[b[i]]++;
    g[c[i]]++;
    h[b[i] ^ c[i]]++;
  }
  fwt(f, 1 << k);
  fwt(g, 1 << k);
  fwt(h, 1 << k);
  for (int i = 0; i < (1 << k); i++) {
    long long p1 = f[i], p2 = g[i], p3 = h[i];
    int c1 = 1ll * (n + p1 + p2 + p3) * inv4 % Mod;
    if (c1 < 0) c1 += Mod;
    int c2 = 1ll * (n + p1 - 2 * c1) * inv2 % Mod;
    if (c2 < 0) c2 += Mod;
    int c3 = 1ll * (n + p2 - 2 * c1) * inv2 % Mod;
    if (c3 < 0) c3 += Mod;
    int c4 = 1ll * (n + p3 - 2 * c1) * inv2 % Mod;
    if (c4 < 0) c4 += Mod;
    int v1 = ((x + y) % Mod + z) % Mod;
    int v2 = ((x + y - z) % Mod + Mod) % Mod;
    int v3 = ((x - y + z) % Mod + Mod) % Mod;
    int v4 = ((x - y - z) % Mod + Mod) % Mod;
    ans[i] = 1ll * fpow(v1, c1) * fpow(v2, c2) % Mod * fpow(v3, c3) % Mod *
             fpow(v4, c4) % Mod;
  }
  ifwt(ans, 1 << k);
  for (int i = 0; i < (1 << k); i++) printf("%d ", ans[i ^ sum]);
  printf("\n");
  return 0;
}
