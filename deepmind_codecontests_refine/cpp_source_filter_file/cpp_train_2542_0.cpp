#include <bits/stdc++.h>
int compare(const void *a, const void *b) { return (*(int *)a) - (*(int *)b); }
int main() {
  int n, x[102] = {0}, i, k = 1;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
  }
  qsort(x, n, sizeof(int), compare);
  for (i = 2; i <= n; i++) {
    if (x[i] < i / k) k++;
  }
  printf("%d", k);
  return 0;
}
