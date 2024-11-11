#include <bits/stdc++.h>
using std::max;
using std::min;
using std::sort;
using std::swap;
template <typename T>
void read(T &x) {
  int flag = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -flag;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= flag;
}
const int N = 7e2 + 10, Mod = 1e9 + 7;
int n, f[N][N][10][2];
char s[N];
signed main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= 9; ++i) f[0][0][i][0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= i; ++j)
      for (int k = 1; k <= 9; ++k)
        for (int o = 0; o < 2; ++o)
          for (int p = 0; p <= (o ? 9 : s[i + 1] - '0'); ++p)
            (f[i + 1][j + (p >= k)][k][o | (p < s[i + 1] - '0')] +=
             f[i][j][k][o]) %= Mod;
  int ans = 0;
  for (int k = 1; k <= 9; ++k) {
    int tmp = 1;
    for (int i = 1; i <= n; ++i, tmp = (1ll * tmp * 10 + 1) % Mod)
      (ans += 1ll * tmp * (f[n][i][k][0] + f[n][i][k][1]) % Mod) %= Mod;
  }
  printf("%d\n", ans);
  return 0;
}
