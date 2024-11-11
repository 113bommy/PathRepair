#include <bits/stdc++.h>
int cmpfunc(const void *a, const void *b) {
  return (*(long long int *)a - *(long long int *)b);
}
int main() {
  long long int k, n, a[100000], i, j = 0;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  qsort(a, n, sizeof(long long int), cmpfunc);
  for (i = 0; i < n; i++) {
    j = j + (a[i] * a[n - 1 - i]);
  }
  printf("%lld", j);
  return 0;
}
