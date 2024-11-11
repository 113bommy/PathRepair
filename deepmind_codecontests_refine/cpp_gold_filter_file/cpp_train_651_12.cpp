#include <bits/stdc++.h>
int main() {
  int a, b, c, d, e, f, g, h, j, k, l;
  scanf("%d", &a);
  while (a--) {
    scanf("%d", &b);
    for (c = 1; c <= b; c++) {
      printf("%d ", 4 * b - 2 * c);
    }
    printf("\n");
  }
  return 0;
}
