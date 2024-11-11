#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, mod = 998244353;
int n, m, ans;
int f[2][maxn][maxn], s[maxn];
int inv(int a) {
  int b = mod - 2, ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  f[1][1][1] = 2;
  for (int i = 2; i <= n; i++) {
    memset(f[i & 1], 0, sizeof(f[i & 1]));
    for (int j = 1; j <= i - 1; j++)
      for (int k = 1; k <= j; k++) {
        (f[i & 1][max(j, k + 1)][k + 1] += f[(i - 1) & 1][j][k]) %= mod;
        (f[i & 1][j][1] += f[(i - 1) & 1][j][k]) %= mod;
      }
  }
  for (int j = 1; j <= n; j++)
    for (int k = 1; k <= n; k++) (s[j] += f[n & 1][j][k]) %= mod;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i * j < m) (ans += 1ll * s[i] * s[j] % mod) %= mod;
  printf("%d", 1ll * ans * inv(2));
  return 0;
}
