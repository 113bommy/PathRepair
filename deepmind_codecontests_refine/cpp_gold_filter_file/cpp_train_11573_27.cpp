#include <bits/stdc++.h>
char *a[500005] = {NULL};
int main() {
  long n, m, i, j;
  long ans = 1;
  long flag = 0;
  scanf("%ld%ld", &n, &m);
  for (i = 1; i <= n; i++) {
    a[i] = (char *)malloc(sizeof(char) * (m + 5));
    a[i][0] = 0;
  }
  for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  for (i = 1; i <= n; i++) {
    flag = 0;
    for (j = 1; j <= m; j++)
      if (a[i][j] != '.') {
        if (j % 2 == 0 && (a[i][j] == '2' || a[i][j] == '1') ||
            j % 2 && (a[i][j] == '4' || a[i][j] == '3'))
          flag = 1;
        else
          flag = 2;
        break;
      }
    if (j > m) ans = ans * 2 % 1000003;
    for (; j <= m; j++)
      if (a[i][j] != '.') {
        if (j % 2 == 0 && (a[i][j] == '2' || a[i][j] == '1') ||
            j % 2 && (a[i][j] == '4' || a[i][j] == '3'))
          flag |= 1;
        else
          flag |= 2;
      }
    if (flag == 3) {
      printf("0\n");
      return 0;
    }
  }
  for (i = 1; i <= m; i++) {
    flag = 0;
    for (j = 1; j <= n; j++)
      if (a[j][i] != '.') {
        if (j % 2 == 0 && (a[j][i] == '3' || a[j][i] == '2') ||
            j % 2 && (a[j][i] == '1' || a[j][i] == '4'))
          flag = 1;
        else
          flag = 2;
        break;
      }
    if (j > n) ans = ans * 2 % 1000003;
    for (; j <= n; j++)
      if (a[j][i] != '.') {
        if (j % 2 == 0 && (a[j][i] == '3' || a[j][i] == '2') ||
            j % 2 && (a[j][i] == '1' || a[j][i] == '4'))
          flag |= 1;
        else
          flag |= 2;
      }
    if (flag == 3) {
      printf("0\n");
      return 0;
    }
  }
  printf("%ld\n", ans);
  return 0;
}
