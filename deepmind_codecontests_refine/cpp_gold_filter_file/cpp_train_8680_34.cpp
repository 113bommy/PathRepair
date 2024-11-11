#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 105;
int n, m, K, ans, jc[N << 1], inv[N << 1], f[2][N][N][N], lst, now;
void up(int &x, int y) {
  x = x - mod + y;
  x = (x < 0) ? x + mod : x;
}
int C(int n, int m) {
  if (n < m) return 0;
  return (long long)jc[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  if (n == 1 || m == 1) return puts("0"), 0;
  jc[0] = jc[1] = inv[0] = inv[1] = 1;
  for (int i = 2; i <= 2 * n; i++)
    jc[i] = (long long)jc[i - 1] * i % mod,
    inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
  for (int i = 2; i <= 2 * n; i++)
    inv[i] = (long long)inv[i] * inv[i - 1] % mod;
  for (int j = 1; j <= n; j++) f[0][j][j][1] = 1;
  for (int i = 2; i <= m; i++) {
    lst = now;
    now ^= 1;
    memset(f[now], 0, sizeof(f[now]));
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= j; k++)
        for (int t = 1; t <= K; t++)
          if (f[lst][j][k][t]) {
            for (int x = k; j + x <= n; x++) {
              int _t = C(x - 1, k - 1);
              if ((long long)t * _t > K) continue;
              up(f[now][j + x][x - k][t * _t], f[lst][j][k][t]);
            }
          }
    for (int j = 2; j <= n; j++)
      for (int t = 1; t <= K; t++)
        up(ans, (long long)f[now][j][0][t] * (m - i + 1) % mod);
  }
  printf("%d\n", ans);
  return 0;
}
