#include <bits/stdc++.h>
char str[11][11];
int n, m;
int main() {
  int i, j, ans, x, y, k;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) scanf("%s", str[i]);
  ans = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (str[i][j] == 'W') {
        if (i - 1 >= 0 && str[i - 1][j] == 'P')
          ans++, str[i - 1][j] = '.';
        else if (i + 1 < n && str[i + 1][j] == 'P')
          ans++, str[i + 1][j] = '.';
        else if (j - 1 >= 0 && str[i][j - 1] == 'P')
          ans++, str[i][j - 1] = '.';
        else if (j + 1 < m && str[i][j + 1] == 'P')
          ans++, str[i][j + 1] = '.';
      }
    }
  }
  printf("%d", ans);
  return 0;
}
