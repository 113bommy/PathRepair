#include <bits/stdc++.h>
using namespace std;
int n, m, limit, f[1 << 21], num[1 << 21];
char s[25][100005];
inline int gt(int S) {
  int tot = 0;
  for (int i = 0; i < n; i++)
    if (S >> i & 1) tot++;
  return tot;
}
inline int ksm(int x, int y) {
  int ans1 = 1;
  while (y) {
    if (y & 1) ans1 = 1ll * ans1 * x % 998244353;
    y >>= 1;
    x = 1ll * x * x % 998244353;
  }
  return ans1;
}
inline void fwt(int *a, int flag) {
  for (int i = 2; i <= limit; i *= 2) {
    for (int j = 0; j < limit; j += i) {
      for (int k = 0; k < (i >> 1); k++) {
        int tmpx = a[j + k], tmpy = a[j + k + (i >> 1)];
        a[j + k] = (tmpx + tmpy) % 998244353;
        a[j + k + (i >> 1)] = (tmpx - tmpy + 998244353) % 998244353;
      }
    }
  }
  if (flag == -1) {
    int inv = ksm(limit, 998244353 - 2);
    for (int i = 0; i < limit; i++) a[i] = 1ll * a[i] * inv % 998244353;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  limit = 1 << n;
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int j = 1; j <= m; j++) {
    int x = 0;
    for (int i = 1; i <= n; i++)
      if (s[i][j] == '1') x ^= (1 << (i - 1));
    num[x]++;
  }
  for (int i = 1; i < (1 << n); i++) f[i] = gt(i), f[i] = min(f[i], n - f[i]);
  fwt(f, 0);
  fwt(num, 0);
  for (int i = 0; i < limit; i++) f[i] = 1ll * f[i] * num[i] % 998244353;
  fwt(f, -1);
  int ans = 1e9;
  for (int i = 0; i < (1 << n); i++) ans = min(ans, f[i]);
  printf("%d\n", ans);
  return 0;
}
