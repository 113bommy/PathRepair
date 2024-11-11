#include <bits/stdc++.h>
int main() {
  int n, i, x, k, j = 0;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    for (x = 0; x < n; x++) {
      if (i == j && x == j) {
        printf("%d", k);
      } else
        printf("0");
    }
    j++;
    printf("\n");
  }
}
