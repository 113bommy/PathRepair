#include <bits/stdc++.h>
int main() {
  long nList[111][111], n = 0, n1, n2;
  scanf("%d", &n);
  for (n2 = n * n, n1 = 0; n1 < n2; n1++)
    nList[(n1 * (n - 1) + (n1 / n) * 2) % n][(n1 + (n >> 1) - n1 / n) % n] =
        n1 + 1;
  for (n2 = 0; n2 < n; n2++) {
    for (n1 = 0; n1 < n; n1++) {
      printf("%d", nList[n1][n2]);
      if (n1 < n - 1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
