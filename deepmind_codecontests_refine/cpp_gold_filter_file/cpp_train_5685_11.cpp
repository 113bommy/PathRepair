#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  scanf("%d", &n);
  if (n & 1) {
    m = n - 3 >> 1;
    printf("%d\n", 2 * m + 2 + (n - 3) * (n - 1) / 4);
    for (i = 1; i <= 2; i++) printf("3 %d %d %d\n", 1, 2, 3);
    for (i = 1; i <= m; i++) {
      printf("3 %d %d %d\n", 3 + 2 * i - 1, 3 + 2 * i, 3 + 2 * i - 2);
      printf("3 %d %d %d\n", 3 + 2 * i - 1, 3 + 2 * i, 3 + 2 * i - 2);
      for (j = 1; j <= 2 * i; j++)
        printf("4 %d %d %d %d\n", 3 + 2 * i - 1, j, 3 + 2 * i, j % (2 * i) + 1);
    }
  } else {
    m = n - 4 >> 1;
    printf("%d\n", 2 * m + 4 + n * (n - 4) / 4);
    for (i = 1; i <= 4; i++) {
      printf("%d ", 3);
      for (j = 1; j <= 4; j++)
        if (j != i) printf("%d ", j);
      printf("\n");
    }
    for (i = 1; i <= m; i++) {
      printf("3 %d %d %d\n", 4 + 2 * i - 1, 4 + 2 * i, 4 + 2 * i - 2);
      printf("3 %d %d %d\n", 4 + 2 * i - 1, 4 + 2 * i, 4 + 2 * i - 3);
      printf("4 %d %d %d %d\n", 4 + 2 * i - 1, 4 + 2 * i - 2, 4 + 2 * i,
             4 + 2 * i - 3);
      for (j = 1; j <= 2 * i; j++)
        printf("4 %d %d %d %d\n", 4 + 2 * i - 1, j, 4 + 2 * i, j % (2 * i) + 1);
    }
  }
  return 0;
}
