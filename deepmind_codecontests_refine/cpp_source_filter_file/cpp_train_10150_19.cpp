#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30), N = 100010, mod = 1e9 + 7;
int n, m;
inline int in() {
  char tmp = getchar();
  int res = 0, f = 1;
  while ((tmp < '0' || tmp > '9') && tmp != '-') tmp = getchar();
  if (tmp == '-') f = -1, tmp = getchar();
  while (tmp >= '0' && tmp <= '9')
    res = (res << 1) + (res << 3) + (tmp ^ 48), tmp = getchar();
  return res * f;
}
char s[1010][1010];
long long f[2][505][505], cur;
int main() {
  n = in(), m = in();
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  if (s[1][1] != s[n][m]) {
    puts("0");
    return 0;
  }
  f[0][1][n] = 1;
  for (int i = 1; i < (n + m) >> 1; i++) {
    cur ^= 1;
    memset(f[cur], 0, sizeof(f[cur]));
    for (int x = 1; x <= i + 1; x++)
      for (int X = n; X >= n - i; X--) {
        int y = i - x + 2, Y = m - (i - (n - X));
        if (x > X || y > Y) continue;
        if (s[x][y] != s[X][Y]) continue;
        (f[cur][x][X] += f[cur ^ 1][x][X]) %= mod;
        (f[cur][x][X] += f[cur ^ 1][x - 1][X]) %= mod;
        (f[cur][x][X] += f[cur ^ 1][x][X + 1]) %= mod;
        (f[cur][x][X] += f[cur ^ 1][x - 1][X + 1]) %= mod;
      }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) (ans += f[cur][i][i]) %= mod;
  if ((n + m) & 1)
    for (int i = 0; i < n; i++) (ans += f[cur][i][i + 1]) % mod;
  printf("%I64d", ans);
  return 0;
}
