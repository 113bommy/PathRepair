#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
const int mod = 1e9 + 7;
char s[maxn];
int f[2][maxn][2], g[2][maxn][2];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", s + i);
  f[0][1][0] = g[0][1][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (s[i] == 's')
        f[i & 1][j][0] = (g[i & 1 ^ 1][j][0] + f[i & 1 ^ 1][j - 1][1]) % mod;
      else
        f[i & 1][j][1] = (g[i & 1 ^ 1][j][0] + f[i & 1 ^ 1][j - 1][1]) % mod;
    }
    for (int j = i; j; j--)
      g[i & 1][j][0] = (g[i & 1][j + 1][0] + f[i & 1][j][0]);
    memset(g[i & 1 ^ 1], 0, sizeof(g[i & 1 ^ 1]));
    memset(f[i & 1 ^ 1], 0, sizeof(f[i & 1 ^ 1]));
  }
  printf("%d", g[n & 1][1][0]);
  return 0;
}
