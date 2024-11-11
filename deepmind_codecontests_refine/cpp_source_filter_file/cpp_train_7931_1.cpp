#include <bits/stdc++.h>
int main() {
  int q, a[100], n, i, j, f = 1, k;
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &n);
    for (j = 0; j < n; j++) scanf("%d", &a[j]);
    for (j = 0; j < n - 1; j++) {
      for (k = j + 1; k < n; k++) {
        if (a[i] == (a[j] - 1) || a[i] == (a[j] + 1)) {
          f = 2;
          break;
        }
      }
    }
    printf("%d\n", f);
    f = 1;
  }
  return 0;
}
