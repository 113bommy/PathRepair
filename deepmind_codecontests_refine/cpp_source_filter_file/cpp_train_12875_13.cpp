#include <bits/stdc++.h>
int comparefunc(const void *a, const void *b) {
  return (*(int *)a) - (*(int *)b);
}
int main() {
  long long int n, i, j = 1;
  scanf("%lld", &n);
  int a[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  qsort(a, n, sizeof(int), comparefunc);
  for (i = 1; i < n; i++) {
    if (a[i]) {
      if (a[i] != a[i - 1]) j++;
    }
  }
  printf("%d\n", j);
}
