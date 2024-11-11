#include <bits/stdc++.h>
int main() {
  int i, j, k, a, n, m, b, x;
  scanf("%d%d", &n, &m);
  if (n == 1 && m == 2 || n == 2 && m == 1) {
    printf("0\n");
    printf("1 1\n");
    printf("%d %d\n", n, m);
    printf("1 1\n");
  } else if (n == 1 || m == 1) {
    printf("1\n");
    printf("%d %d 1 1\n", n, m);
    if (n == 1)
      for (i = 1; i <= m; i++) printf("1 %d\n", i);
    if (m == 1)
      for (i = 1; i <= n; i++) printf("%d 1\n", i);
    printf("1 1\n");
  } else {
    if (n % 2 == 0 || m % 2 == 0) {
      printf("0\n");
      if (n % 2 == 1) {
        for (i = 1; i <= n; i++) printf("%d 1\n", i);
        x = 1;
        for (i = 2; i < m; i++) {
          if (x % 2)
            for (j = n; j > 1; j--) printf("%d %d\n", j, i);
          if (x % 2 == 0)
            for (j = 2; j <= n; j++) printf("%d %d\n", j, i);
          x++;
        }
        for (i = n; i > 1; i--) printf("%d %d\n", i, m);
        for (i = m; i >= 1; i--) printf("1 %d\n", i);
      }
      if (m % 2 == 1 || n % 2 == 0 && m % 2 == 0) {
        for (i = 1; i <= m; i++) printf("1 %d\n", i);
        x = 1;
        for (i = 2; i < n; i++) {
          if (x % 2)
            for (j = m; j > 1; j--) printf("%d %d\n", i, j);
          if (x % 2 == 0)
            for (j = 2; j <= m; j++) printf("%d %d\n", i, j);
          x++;
        }
        for (i = m; i > 1; i--) printf("%d %d\n", n, i);
        for (i = n; i >= 1; i--) printf("%d 1\n", i);
      }
    }
    if (n % 2 && m % 2) {
      printf("1\n");
      printf("%d %d 1 1\n", n, m);
      x = 1;
      for (i = 1; i <= m; i++) {
        if (x % 2)
          for (j = 1; j <= n; j++) printf("%d %d\n", j, i);
        if (x % 2 == 0)
          for (j = n; j > 0; j--) printf("%d %d\n", j, i);
        x++;
      }
      printf("1 1\n");
    }
  }
  return 0;
}
