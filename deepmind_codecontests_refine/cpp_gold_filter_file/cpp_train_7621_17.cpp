#include <bits/stdc++.h>
const int N = 105;
const int mod = 998244353;
using namespace std;
int n, l[N], r[N], c[N << 1], g[N << 1], cnt, f[N][N << 1], ans;
template <typename T>
inline T read() {
  T x = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * w;
}
int fpow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) res = 1ll * res * x % mod;
  return res;
}
int main() {
  n = read<int>();
  for (int i = 1; i <= n; i++)
    l[i] = read<int>(), r[i] = read<int>(), c[++cnt] = l[i], c[++cnt] = ++r[i];
  sort(c + 1, c + cnt + 1), cnt = unique(c + 1, c + cnt + 1) - c - 1;
  f[0][cnt] = 1, l[0] = 0, r[0] = c[cnt];
  for (int j = cnt - 1; j >= 1; j--) {
    for (int len = c[j + 1] - c[j], i = (g[0] = 1); i <= n; i++)
      g[i] = 1ll * g[i - 1] * (len + i - 1) % mod * fpow(i, mod - 2) % mod;
    for (int k = 1; k <= n + 1; k++) {
      for (int d = 1, i = k; i <= n; i++, d++) {
        if (!(l[i] <= c[j] && r[i] >= c[j + 1])) break;
        f[i][j] = (1ll * f[k - 1][j + 1] * g[i - k + 1] + f[i][j]) % mod;
      }
    }
    for (int i = 0; i <= n; i++) f[i][j] = (f[i][j] + f[i][j + 1]) % mod;
  }
  ans = f[n][1];
  for (int i = 1; i <= n; i++)
    ans = 1ll * ans * fpow(r[i] - l[i], mod - 2) % mod;
  printf("%d\n", ans);
  return 0;
}
