#include <bits/stdc++.h>
using namespace std;
int main() {
  int d1, d2, bc, d3;
  int n, a[200000];
  while (scanf("%d", &n) == 1) {
    d3 = 1;
    bc = 0;
    for (d1 = 0; d1 < n; d1++) scanf("%d", a + d1);
    for (d1 = 0; d1 < n; d1++) a[d1] = a[d1] - (n - d1 - 1);
    sort(a, a + n);
    for (d1 = 0; d1 < n; d1++) a[d1] = a[d1] + (n - d1 - 1);
    for (d2 = 1; d2 < n; d2++)
      if (a[d2 - 1] > a[d2]) d3 = 0;
    if (d3)
      for (d1 = 0; d1 < n; d1++) {
        if (d1 == 0)
          printf("%d", a[d1]);
        else
          printf(" %d", a[d1]);
      }
    else
      printf(":(");
    printf("\n");
  }
  return 0;
}
