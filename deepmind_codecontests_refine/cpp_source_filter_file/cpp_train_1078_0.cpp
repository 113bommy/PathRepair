#include <bits/stdc++.h>
int main() {
  int n, i, j, d[5] = {1, 16, 13, 4, 19};
  scanf("%d", &n);
  if (n <= 2) {
    printf("-1\n");
    return 0;
  } else if (n == 3) {
    printf("210\n");
    return 0;
  }
  printf("1");
  for (i = 5; i <= n; i++) printf("0");
  printf("%02d0\n", 21 - d[(n - 3) % 6]);
  return 0;
}
