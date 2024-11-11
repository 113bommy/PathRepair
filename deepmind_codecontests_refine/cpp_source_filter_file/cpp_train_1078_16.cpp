#include <bits/stdc++.h>
int d[6] = {1, 10, 16, 13, 4, 19};
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  if (n < 3) {
    puts("-1");
    return 0;
  }
  if (n == 3) {
    puts("210");
    return 0;
  }
  int i;
  putchar('1');
  for (i = 4; i < n; ++i) putchar('0');
  printf("%03d\n", (21 - d[(n - 2) % 21]) * 10);
  return 0;
}
