#include <bits/stdc++.h>
int main() {
  int t, i, j, n;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d", &n);
    printf("%d\n", n);
    for (j = 1; j <= n; j++) {
      printf("%d", j);
      if (j < n) {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
