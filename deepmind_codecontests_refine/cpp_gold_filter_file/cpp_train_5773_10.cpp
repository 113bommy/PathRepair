#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, m;
  scanf("%d %d", &n, &m);
  if (n == 1 && m > 2) {
    printf("1\n1 %d 1 1\n", m);
    for (i = 1; i <= m; i++) printf("1 %d\n", i);
    printf("1 1\n");
    return 0;
  }
  if (m == 1 && n > 2) {
    printf("1\n%d 1 1 1\n", n);
    for (i = 1; i <= n; i++) printf("%d 1\n", i);
    printf("1 1\n");
    return 0;
  }
  if ((n & 1) && (m & 1)) {
    printf("1\n%d %d 1 1\n", n, m);
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) {
        if (i % 2 == 1)
          printf("%d %d\n", i, j);
        else
          printf("%d %d\n", i, m + 1 - j);
      }
    printf("1 1\n");
  } else if ((n % 2 == 0 && m % 2 == 0) || (n % 2 == 0 && m % 2 == 1)) {
    printf("0\n");
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) {
        if (i == 1 || i == n) {
          if (i % 2 == 1)
            printf("%d %d\n", i, j);
          else
            printf("%d %d\n", i, m + 1 - j);
        } else {
          if (j > 1) {
            if (i % 2 == 1)
              printf("%d %d\n", i, j);
            else
              printf("%d %d\n", i, m + 2 - j);
          }
        }
      }
    for (i = n - 1; i >= 1; i--) printf("%d %d\n", i, 1);
  } else if (n % 2 == 1 && m % 2 == 0) {
    printf("0\n");
    for (j = 1; j <= m; j++) printf("%d %d\n", 1, j);
    for (j = m; j >= 1; j--)
      for (i = 2; i <= n; i++) {
        if ((m - j) % 2 == 0)
          printf("%d %d\n", i, j);
        else
          printf("%d %d\n", n + 2 - i, j);
      }
    printf("1 1\n");
  }
  return 0;
}
