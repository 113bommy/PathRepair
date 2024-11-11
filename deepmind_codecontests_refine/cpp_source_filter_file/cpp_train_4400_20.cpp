#include <bits/stdc++.h>
int main() {
  int n, i, j;
  scanf("%d", &n);
  int p[n];
  for (i = 0; i < n; i++) scanf("%d", &p[i]);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (p[j] == i) {
        printf("%d ", j);
        break;
      }
    }
  }
  return 0;
}
