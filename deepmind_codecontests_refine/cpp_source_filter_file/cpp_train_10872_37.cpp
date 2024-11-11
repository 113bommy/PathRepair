#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int i, j;
  if (n == 1 && m == 1) {
    puts("1");
    return 0;
  }
  if (n == 1) {
    if (m == 2)
      puts("4 3");
    else {
      for (i = 0; i < m - 1; i++) printf("2 ");
      printf("%d\n", m - 2);
    }
    return 0;
  }
  if (m == 1) {
    if (n == 2)
      printf("4\n3\n");
    else {
      for (i = 0; i < n - 1; i++) printf("2\n");
      printf("%d\n", n - 2);
    }
    return 0;
  }
  if (n == 2 && m == 2) {
    printf("9 12\n9 12\n");
    return 0;
  }
  if (n == 2) {
    for (i = 0; i < m - 1; i++) printf("8 ");
    printf("%d\n", 4 * (m - 2));
    for (i = 0; i < m - 1; i++) printf("6 ");
    printf("%d\n", 3 * (m - 2));
    return 0;
  }
  if (m == 2) {
    for (i = 0; i < n - 1; i++) printf("8 6\n");
    printf("%d %d\n", 4 * (n - 2), 3 * (n - 2));
    return 0;
  }
  for (i = 1; i < n; i++) {
    for (j = 0; j < m - 1; j++) printf("4 ");
    printf("%d\n", 2 * (n - 2));
  }
  for (i = 0; i < m - 1; i++) printf("%d ", 2 * (m - 2));
  printf("%d\n", (n - 2) * (m - 2));
  return 0;
}
