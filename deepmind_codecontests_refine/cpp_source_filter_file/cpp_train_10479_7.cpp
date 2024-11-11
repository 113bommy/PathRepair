#include <bits/stdc++.h>
using std::max;
using std::min;
using std::swap;
const int maxn = 7850, mod = 1e9 + 7;
inline int inv(int a) {
  int ans = 1, bas = a, x = mod - 2;
  while (x) {
    if (x & 1) ans = 1ll * ans * bas % mod;
    bas = 1ll * bas * bas % mod, x >>= 1;
  }
  return ans;
}
int R, n, id[105][105], a[maxn][maxn], ans[maxn], p1, p2, p3, p4, sinv;
bool legal(int x, int y) { return x * x + y * y <= R * R; }
void Band_Matrix(int B) {
  for (int i = 1; i <= n; ++i) {
    if (!a[i][i]) {
      for (int j = i + 1; j <= min(n, i + B); ++j)
        if (a[j][i]) {
          for (int k = i; k <= min(n, i + 2 * B); ++k) swap(a[i][k], a[j][k]);
          break;
        }
    }
    int t = inv(a[i][i]);
    for (int j = i + 1; j <= min(n, i + B); ++j) {
      int tmp = 1ll * a[j][i] * t % mod;
      if (!tmp) continue;
      for (int k = i; k <= min(n, i + 2 * B); ++k)
        if (a[i][k])
          a[j][k] = (a[j][k] - 1ll * tmp * a[i][k] % mod + mod) % mod;
      a[j][n + 1] = (a[j][n + 1] - 1ll * tmp * a[i][n + 1] % mod + mod) % mod;
    }
  }
  for (int i = n; i; --i) {
    ans[i] = a[i][n + 1];
    for (int j = i + 1; j <= min(n, i + 2 * B); ++j)
      ans[i] = (ans[i] - 1ll * ans[j] * a[i][j] % mod + mod) % mod;
    ans[i] = 1ll * ans[i] * inv(a[i][i]) % mod;
  }
}
int main() {
  scanf("%d %d %d %d %d", &R, &p1, &p2, &p3, &p4),
      sinv = inv(p1 + p2 + p3 + p4);
  p1 = 1ll * p1 * sinv % mod, p2 = 1ll * p2 * sinv % mod,
  p3 = 1ll * p3 * sinv % mod, p4 = 1ll * p4 * sinv % mod;
  for (int i = -R; i <= R; ++i)
    for (int j = -R; j <= R; ++j)
      if (legal(i, j)) id[i + R][j + R] = ++n;
  int Max = 0;
  for (int i = -R; i <= R; ++i)
    for (int j = -R; j <= R; ++j)
      if (legal(i, j)) {
        int Id = id[i + R][j + R];
        a[Id][Id] = 1, a[Id][n + 1] = 1;
        if (legal(i - 1, j))
          a[Id][id[i - 1 + R][j + R]] = mod - p1,
                                  Max = max(Max, Id - id[i - 1 + R][j + R]);
        if (legal(i, j - 1))
          a[Id][id[i + R][j - 1 + R]] = mod - p2,
                                  Max = max(Max, Id - id[i + R][j - 1 + R]);
        if (legal(i + 1, j))
          a[Id][id[i + 1 + R][j + R]] = mod - p3,
                                  Max = max(Max, id[i + 1 + R][j + R] - Id);
        if (legal(i, j + 1))
          a[Id][id[i + R][j + 1 + R]] = mod - p4,
                                  Max = max(Max, id[i + R][j + 1 + R] - Id);
      }
  Band_Matrix(Max);
  return printf("%d\n", a[id[R][R]][n + 1]), 0;
}
