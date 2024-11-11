#include <bits/stdc++.h>
int main() {
  int t, i, j, n;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d", &n);
    printf("%d\n", n);
    for (j = n; j > 0; j--) {
      printf("%d", j);
      if (j > 1) {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
