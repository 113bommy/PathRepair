#include <bits/stdc++.h>
int main() {
  char a[1000][100], x;
  int n, m, t = 0, i, j;
  scanf("%d%d\n", &n, &m);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%c", &a[i][j]);
      if (a[i][j] != a[i][j - 1] && j > 2) t = 1;
    }
    scanf("%c", &x);
    if (t == 1) {
      printf("NO");
      return 0;
    }
    t = 0;
  }
  for (i = 1; i < n; i++)
    if (a[i][1] != a[i + 1][1]) {
      printf("NO");
      return 0;
    }
  printf("YES");
  return 0;
}
