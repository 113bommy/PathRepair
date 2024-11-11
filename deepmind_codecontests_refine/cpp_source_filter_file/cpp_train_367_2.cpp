#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int n, m, mod;
int inv[maxn], f[maxn][12][maxn >> 1];
inline void read(int &k) {
  int f = 1;
  k = 0;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c <= '9' && c >= '0') k = k * 10 + c - '0', c = getchar();
  k *= f;
}
inline int power(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
int main() {
  read(n);
  read(m);
  read(mod);
  if (n <= 2) return puts("1"), 0;
  for (int i = 1; i <= n; i++) inv[i] = power(i, mod - 2);
  for (int i = 0; i <= n / 2; i++) f[1][0][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= n / 2; k++) {
        f[i][j][k] = f[i][j][k - 1];
        for (int l = 1, tmp = 1; l <= j && k * l <= i; l++) {
          tmp = 1ll * tmp * (f[k][(k == 1) ? 0 : m - 1][k - 1] + l - 1) % mod *
                inv[l] % mod;
          f[i][j][k] =
              (f[i][j][k] + 1ll * f[i - k * l][j - l][k - 1] * tmp) % mod;
        }
      }
    }
  }
  int ans = f[n][m][n >> 1];
  if ((n & 1) == 0) {
    int t = f[n >> 1][m - 1][(n >> 1) - 1] + 1;
    ans = (ans - 1ll * t * (t + 1) / 2 % mod + mod) % mod;
  }
  printf("%d\n", ans);
}
