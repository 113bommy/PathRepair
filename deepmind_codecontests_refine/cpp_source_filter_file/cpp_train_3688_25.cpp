#include <bits/stdc++.h>
int q, i, j, m, n, a[10001], s = 0;
int main() {
  scanf("%d", &q);
  for (i = 1; i < q; i++) scanf("%d", &a[i]);
  scanf("%d %d", &n, &m);
  for (j = 1; j < m; j++) s = s + a[j];
  printf("%d", s);
  return 0;
}
