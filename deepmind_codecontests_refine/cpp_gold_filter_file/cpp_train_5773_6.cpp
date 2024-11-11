#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, m, flag = 0, x;
  scanf("%d", &n);
  scanf("%d", &m);
  if (n % 2 == 0) flag++;
  if (m % 2 == 0) flag++;
  if (m == 1 && n > 2) {
    printf("1\n");
    printf("%d %d 1 1\n", n, m);
    for (i = 1; i <= n; i++) printf("%d 1\n", i);
    printf("1 1");
    return 0;
  }
  if (n == 1 && m > 2) {
    printf("1\n");
    printf("%d %d 1 1\n", n, m);
    for (i = 1; i <= m; i++) printf("1 %d\n", i);
    printf("1 1");
    return 0;
  }
  if (flag == 2) {
    printf("0\n");
    for (i = 1; i <= m; i++) printf("1 %d\n", i);
    for (j = 2; j <= n; j++) printf("%d %d\n", j, m);
    for (i = m - 1; i >= 1; i--) printf("%d %d\n", n, i);
    n--;
    m--;
    while (n > 1) {
      if (n % 2 == 0) {
        for (i = m; i >= 1; i--) printf("%d %d\n", n, i);
      } else {
        for (i = 1; i <= m; i++) printf("%d %d\n", n, i);
      }
      n--;
    }
    printf("1 1");
  } else if (flag == 1) {
    if (n % 2 == 0) {
      printf("0\n");
      for (i = 1; i <= n; i++) printf("%d 1\n", i);
      for (j = 2; j <= m; j++) printf("%d %d\n", n, j);
      n--;
      while (n > 0) {
        if (n % 2 != 0) {
          for (i = m; i >= 2; i--) printf("%d %d\n", n, i);
        } else {
          for (i = 2; i <= m; i++) printf("%d %d\n", n, i);
        }
        n--;
      }
      printf("1 1");
    } else {
      printf("0\n");
      for (i = 1; i <= m; i++) printf("1 %d\n", i);
      for (j = 2; j <= n; j++) printf("%d %d\n", j, m);
      m--;
      while (m > 0) {
        if (m % 2 != 0) {
          for (i = n; i >= 2; i--) printf("%d %d\n", i, m);
        } else {
          for (i = 2; i <= n; i++) printf("%d %d\n", i, m);
        }
        m--;
      }
      printf("1 1");
    }
  } else if (!flag) {
    printf("1\n");
    printf("%d %d 1 1\n", n, m);
    for (i = 1; i <= m; i++) printf("1 %d\n", i);
    n--;
    x = 1;
    while (n > 0) {
      x++;
      if (n % 2 == 0) {
        for (i = m; i >= 1; i--) printf("%d %d\n", x, i);
      } else {
        for (i = 1; i <= m; i++) printf("%d %d\n", x, i);
      }
      n--;
    }
    printf("1 1");
  }
}
