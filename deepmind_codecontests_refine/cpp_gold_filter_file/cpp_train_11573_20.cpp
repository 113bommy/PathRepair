#include <bits/stdc++.h>
const int P = 1000003;
bool f[2][500010][2];
int main() {
  char c;
  int i, j, m, n;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (getchar(), j = 1; j <= m; j++)
      if ((c = getchar()) != '.') {
        f[0][j][i % 2 ^ (c == '1' || c == '4')] = true;
        f[1][i][j % 2 ^ (c <= '2')] = true;
      }
  int ans = 1;
  for (i = 1; i <= n; i++) ans *= 2 - f[1][i][0] - f[1][i][1], ans %= P;
  for (i = 1; i <= m; i++) ans *= 2 - f[0][i][0] - f[0][i][1], ans %= P;
  printf("%d\n", ans);
  return 0;
}
