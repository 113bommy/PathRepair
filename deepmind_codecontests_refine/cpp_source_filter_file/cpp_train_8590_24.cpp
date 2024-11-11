#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, h;
  scanf("%d%d%d", &n, &d, &h);
  if (d > 2 * h) {
    puts("-1");
    return 0;
  }
  if (d == h) {
    if (d == 1) {
      if (n == 2)
        puts("1 2");
      else
        puts("-1");
      return 0;
    }
    if (d == n - 1) {
      for (int i = 1; i < n; i++) {
        printf("%d %d\n", i, i + 1);
      }
      return 0;
    }
    int i;
    for (i = 1; i <= h; i++) {
      printf("%d %d", i, i + 1);
    }
    i++;
    while (i <= n) {
      printf("2 %d\n", i - h, i);
      i++;
    }
    return 0;
  }
  int i;
  for (i = 1; i <= h; i++) {
    printf("%d %d\n", i, i + 1);
  }
  i++;
  while (i <= n) {
    printf("1 %d\n", i);
    i++;
    for (int j = 1; j < d - h; j++) {
      if (i > n) break;
      printf("%d %d\n", i - 1, i);
      i++;
    }
  }
  return 0;
}
