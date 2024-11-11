#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  int n, i, j;
  for (i = 0; i < t; i++) {
    scanf("%d", &n);
    for (j = 0; j < 2 * n; j++) {
      if (j % 2 != 0) {
        printf("%d ", 1);
      }
    }
    printf("\n");
  }
  return 0;
}
