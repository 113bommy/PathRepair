#include <bits/stdc++.h>
using namespace std;
int ncr[101];
int a[101][101];
int main() {
  int k, i, j, l, n = 100, c;
  ncr[3] = 1;
  for (i = 4; i <= n; i++) {
    ncr[i] = (ncr[i - 1] * i) / (i - 3);
  }
  scanf("%d", &k);
  c = 100;
  l = 1;
  while (k) {
    if (ncr[c] <= k) {
      k -= ncr[c];
      for (i = l; i < l + c; i++) {
        for (j = l; j < l + c; j++) {
          if (i != j) a[i][j] = 1;
        }
      }
      l = l + c;
      break;
    } else
      c--;
  }
  for (i = 1; i <= 100; i++) {
    for (j = 1; j < i; j++) {
      if (a[i][j]) continue;
      c = 0;
      for (l = 1; l <= 100; l++) {
        if (a[i][l] && a[j][l]) c++;
      }
      if (c <= k) {
        a[i][j] = 1;
        a[j][i] = 1;
        k -= c;
      }
      if (k == 0) break;
    }
  }
  printf("%d\n", n);
  for (i = 1; i <= 100; i++) {
    for (j = 1; j <= 100; j++) printf("%d", a[i][j]);
    printf("\n");
  }
  return 0;
}
