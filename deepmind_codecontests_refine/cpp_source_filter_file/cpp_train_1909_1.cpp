#include <bits/stdc++.h>
const int mo = 1e9 + 7;
int f[4010][4010], i, j, n, m, ans;
char a[4010], b[4010];
int main() {
  scanf("%s\n%s\n", a + 1, b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) {
      f[i][j] = f[i][j - 1];
      if (a[i] == b[j]) (f[i][j] += f[i - 1][j - 1] + 1) %= mo;
    }
  for (i = 1; i <= n; ++i) (ans += f[i][m]) %= mo;
  printf("%d\n", ans);
}
