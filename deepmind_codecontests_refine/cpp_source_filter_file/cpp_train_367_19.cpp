#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int fac[MAXN], inv[MAXN], n, d, mods;
int upd(int x, int y) { return x + y >= mods ? x + y - mods : x + y; }
int quick_pow(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1ll * ret * x % mods;
    x = 1ll * x * x % mods;
  }
  return ret;
}
int C(int x, int y) {
  if (x < y) return 0;
  int ans = 1;
  for (int i = 1; i <= y; i++)
    ans = 1ll * ans * (x - i + 1) % mods * inv[i] % mods;
  return ans;
}
void Init(int n) {
  for (int i = 0; i <= n; i++) inv[i] = quick_pow(i, mods - 2);
}
int f[MAXN][11][MAXN];
signed main() {
  n = read(), d = read(), mods = read(), Init(d);
  if (n <= 2) {
    puts("1\n");
    return 0;
  }
  for (int i = 0; i <= n; i++) f[1][0][i] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= d; j++)
      for (int p = 1; p <= n; p++) {
        f[i][j][p] = f[i][j][p - 1];
        for (int k = 1; k <= j && k * p < i; k++)
          f[i][j][p] =
              upd(f[i][j][p],
                  1ll * f[i - k * p][j - k][p - 1] *
                      C(f[p][(p == 1 ? 0 : d - 1)][p - 1] + k - 1, k) % mods);
      }
  if (n & 1)
    printf("%d\n", f[n][d][n / 2]);
  else
    printf("%d\n", upd(f[n][d][n / 2], mods - C(f[n / 2][d][n / 2], 2)));
  return 0;
}
