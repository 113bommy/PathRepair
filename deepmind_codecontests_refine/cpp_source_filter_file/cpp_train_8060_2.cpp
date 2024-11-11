#include <bits/stdc++.h>
int main() {
  int k, n, a[100], i, d, j;
  scanf("%d", &n);
  scanf("%d", &k);
  for (i = 0; i <= n - 1; i++) scanf("%d", &a[i]);
  for (i = 0; i <= n - 2; i++)
    for (j = i + 1; j <= n - 1; j++)
      if (a[i] < a[j]) {
        d = a[i];
        a[i] = a[j];
        a[j] = d;
      };
  for (i = 0; i < n - k; i++)
    ;
  printf("%d", a[i]);
  return 0;
}
