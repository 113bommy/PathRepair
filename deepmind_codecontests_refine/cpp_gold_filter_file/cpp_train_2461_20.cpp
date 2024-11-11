#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx")
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int mod = 1e9 + 7, N = 705;
int ans, n, dig[N], f[N][N][10][2];
char s[N];
signed main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) dig[i] = s[i] ^ 48;
  for (int i = 0; i <= 9; i++) f[0][0][i][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 1; k <= 9; k++)
        for (int lim = 0; lim <= 1; lim++)
          for (int x = 0; x <= (lim ? 9 : dig[i + 1]); x++)
            (f[i + 1][j + (x >= k)][k][lim | (x < dig[i + 1])] +=
             f[i][j][k][lim]) %= mod;
  for (int k = 1; k <= 9; k++)
    for (int i = 1, mul = 1; i <= n; i++)
      ans = (ans + 1ll * mul * (f[n][i][k][0] + f[n][i][k][1]) % mod) % mod,
      mul = (1ll * mul * 10 + 1) % mod;
  write(ans);
}
