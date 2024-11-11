#include <bits/stdc++.h>
int main() {
  int n, m, k, i, j, c, cf = 0;
  scanf("%d %d %d", &n, &m, &k);
  m = m + 1;
  int x[m];
  for (i = 0; i < m; i++) {
    scanf("%d", &x[i]);
  }
  j = 0;
  while (j < m - 1) {
    i = 0, c = 0;
    while (i < n) {
      if ((x[j] & 1 << i) && (x[m - 1] & 1 << i)) {
        i++;
        continue;
      } else {
        c++;
      }
      i++;
    }
    if (c <= k) cf++;
    j++;
  }
  printf("%d", cf);
}
