#include <bits/stdc++.h>
int main() {
  long long int d, l = 0, a[10000];
  int n, j;
  scanf("%I64d", &d);
  scanf("%d", &n);
  for (j = 0; j < n; j++) scanf("%I64d", &a[j]);
  for (j = 0; j < n - 1; j++) {
    l = l + d - a[j];
  }
  printf("%I64d", l);
  return (0);
}
