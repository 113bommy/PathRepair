#include <bits/stdc++.h>
int main() {
  char c[200][200];
  int a[200];
  int flag2[200];
  int n, m, i, len, len2, flag, j, z;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(flag2, 0, sizeof(flag2));
    memset(c, 0, sizeof(c));
    for (i = 0; i < n; i++) {
      scanf("%s", c[i]);
    }
    for (i = 0; i < m; i++) {
      scanf("%d", &a[i]);
      flag2[a[i] - 1] = 1;
    }
    flag = 0;
    len = strlen(c[a[0] - 1]);
    for (i = 1; i < m; i++) {
      len2 = strlen(c[a[i] - 1]);
      if (len != len2) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      printf("No\n");
      continue;
    }
    len = strlen(c[a[0] - 1]);
    for (j = 1; j < m; j++) {
      for (z = 0; z < len; z++) {
        if (c[a[0] - 1][z] == c[a[j] - 1][z]) {
          continue;
        } else {
          c[a[0] - 1][z] = '?';
        }
      }
    }
    int num1 = 0, num2 = 0, len3;
    for (i = 0; i < n; i++) {
      num1 = 0;
      num2 = 0;
      len3 = strlen(c[i]);
      if (flag2[i] == 0) {
        if (len3 != len) {
          continue;
        }
        for (j = 0; j < len; j++) {
          if (c[a[0] - 1][j] == '?') {
            num1++;
          } else if (c[a[0] - 1][j] == c[i][j]) {
            num2++;
          }
        }
        if (num1 + num2 == len) {
          flag = 1;
          break;
        }
      }
    }
    if (flag) {
      printf("No\n");
    } else {
      printf("Yes\n");
      for (i = 0; i < len; i++) {
        printf("%c", c[a[0] - 1][i]);
      }
      puts("");
    }
  }
  return 0;
}
