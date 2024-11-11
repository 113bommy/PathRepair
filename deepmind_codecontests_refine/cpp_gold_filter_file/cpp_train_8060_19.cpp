#include <bits/stdc++.h>
int cmp(const void *a, const void *b) {
  return (*(int *)a) < (*(int *)b) ? 1 : -1;
}
int main() {
  int n, k, a, len, t, i, j;
  int s[109];
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  qsort(s, n, sizeof(int), cmp);
  printf("%d", s[k - 1]);
  return 0;
}
