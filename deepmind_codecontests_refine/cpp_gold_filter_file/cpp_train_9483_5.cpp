#include <bits/stdc++.h>
int main() {
  int n, m, i, j;
  int b = 0;
  int a[1000], c[1000];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  for (j = 0; j < m; j++) scanf("%d", &a[j]);
  i = 0;
  j = 0;
  while (i != n && j != m) {
    if (a[j] >= c[i]) {
      j++;
      i++;
      b++;
    } else
      i++;
  }
  printf("%d", b);
}
