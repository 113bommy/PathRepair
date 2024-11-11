#include <bits/stdc++.h>
using namespace std;
const int N = 500100, mod = 1e6 + 3;
inline int read() {
  int x = 0, c = getchar(), f = 0;
  for (; c > '9' || c < '0'; f = c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  return f ? -x : x;
}
char a[N];
int g[N][2], f[N][2], n, m, i, j, ans;
int main() {
  n = read();
  m = read();
  ans = 1;
  for (i = 1; i <= m; i++) f[i][0] = f[i][1] = 1;
  g[0][0] = g[0][1] = 1;
  for (i = 1; i <= n; i++) {
    scanf("%s", a + 1);
    for (j = 1; j <= m; j++)
      if (a[j] == '1') {
        g[j][1] = 0;
        g[j][0] = g[j - 1][1];
        f[j][0] = f[j][1];
        f[j][1] = 0;
      } else if (a[j] == '2') {
        g[j][1] = 0;
        g[j][0] = g[j - 1][1];
        f[j][1] = f[j][0];
        f[j][0] = 0;
      } else if (a[j] == '3') {
        g[j][0] = 0;
        g[j][1] = g[j - 1][0];
        f[j][1] = f[j][0];
        f[j][0] = 0;
      } else if (a[j] == '4') {
        g[j][0] = 0;
        g[j][1] = g[j - 1][0];
        f[j][0] = f[j][1];
        f[j][1] = 0;
      } else {
        g[j][0] = g[j - 1][1];
        g[j][1] = g[j - 1][0];
        swap(f[j][0], f[j][1]);
      }
    ans = ans * (g[m][0] + g[m][1]) % mod;
  }
  for (j = 1; j <= m; j++) ans = ans * (f[j][0] + f[j][1]) % mod;
  printf("%d\n", ans);
  return 0;
}
