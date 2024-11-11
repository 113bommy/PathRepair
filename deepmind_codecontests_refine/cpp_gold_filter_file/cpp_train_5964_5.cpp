#include <bits/stdc++.h>
inline long long min(long long x, long long y) { return x < y ? x : y; }
int a[2002], b[2002], c[2002], i, j, k, m, n, v, x, z;
long long f[2002], w, y;
int main() {
  for (scanf("%d%d", &n, &m), w = 0x3f3f3f3f3f3f3f3f, i = 1; i <= n;
       f[i++] = 0x3f3f3f3f)
    scanf("%d%d%d", a + i, b + i, c + i);
  for (i = 0; i <= n; i++)
    if (f[i] != 0x3f3f3f3f) {
      for (x = a[i + 1] - 1, y = f[i], z = 0, j = i + 1; j <= n; j++) {
        if (z < c[j]) x += v = (c[j] - z - 1) / m + 1, y += v, z += m * v;
        if (z -= c[j], b[j] < x) break;
        if (x < a[j + 1]) f[j] = min(f[j], y), x = a[j + 1];
      }
      if (j == n + 1) w = min(w, (long long)y * m - z);
    }
  return 0 & printf("%lld\n", w == 0x3f3f3f3f3f3f3f3f ? -1ll : w);
}
