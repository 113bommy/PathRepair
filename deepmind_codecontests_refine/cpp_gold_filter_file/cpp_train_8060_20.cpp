#include <bits/stdc++.h>
int a[109];
int cmp(const void *a, const void *b) { return (*(int *)b - *(int *)a); }
int main() {
  int n, m, i;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  qsort(a, n, sizeof(a[0]), cmp);
  printf("%d\n", a[m - 1]);
  return 0;
}
