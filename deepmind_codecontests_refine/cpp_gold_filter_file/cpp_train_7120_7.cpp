#include <bits/stdc++.h>
using namespace std;
char s[222][222];
int main() {
  int i, j, m, flag, n;
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    int sum1 = 0, sum2 = 0;
    for (i = 1; i <= n; i++) {
      flag = 0;
      for (j = 1; j <= n; j++)
        if (s[i][j] == '.') {
          flag = 1;
          break;
        }
      if (flag) sum1++;
    }
    for (j = 1; j <= n; j++) {
      flag = 0;
      for (i = 1; i <= n; i++)
        if (s[i][j] == '.') {
          flag = 1;
          break;
        }
      if (flag) sum2++;
    }
    if (sum1 != n && sum2 != n) {
      printf("-1\n");
      continue;
    }
    if (sum1 == n) {
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
          if (s[i][j] == '.') {
            printf("%d %d\n", i, j);
            break;
          }
      }
      continue;
    }
    if (sum2 == n) {
      for (j = 1; j <= n; j++) {
        for (i = 1; i <= n; i++)
          if (s[i][j] == '.') {
            printf("%d %d\n", i, j);
            break;
          }
      }
      continue;
    }
  }
  return 0;
}
