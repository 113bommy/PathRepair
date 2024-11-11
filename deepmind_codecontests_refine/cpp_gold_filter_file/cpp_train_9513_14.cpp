#include <bits/stdc++.h>
int main(void) {
  int i, j, k, n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (3 == m) {
      if (3 == n)
        printf("0 0\n0 1\n1 0\n");
      else if (4 == n)
        printf("0 0\n3 0\n0 3\n1 1\n");
      else
        printf("-1\n");
      continue;
    } else {
      j = 1;
      k = 1;
      printf("%d %d\n", -1, 0);
      for (i = 2; i <= m; i++) printf("%d %d\n", j++, k), k += i;
      j = 100000;
      for (i = 1; i <= n - m; i++) printf("%d %d\n", j, k--), j += i;
    }
  }
  return 0;
}
