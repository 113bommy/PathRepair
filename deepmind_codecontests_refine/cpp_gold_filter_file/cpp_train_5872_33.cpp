#include <bits/stdc++.h>
int main() {
  int n, x, i, j;
  scanf("%d %d", &n, &x);
  if (n == 100) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (i % 2) {
          if (j == 0)
            printf("^");
          else if (j == 1 && i == n - 1)
            printf(".");
          else if (j == 1)
            printf("v");
          else if (j >= n - n / 3)
            printf("<");
          else if (j % 2)
            printf("<");
          else
            printf(".");
        } else {
          if (i == 0 && j == 0)
            printf(">");
          else if (j == 0)
            printf("^");
          else if (j == n - 1)
            printf("v");
          else if (j <= n / 3)
            printf(">");
          else if (j % 2)
            printf(">");
          else
            printf(".");
        }
      }
      printf("\n");
    }
    printf("1 1\n");
  } else if (n == 5)
    printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
  else
    printf(">vv\n^<.\n^.<\n1 3\n");
}
