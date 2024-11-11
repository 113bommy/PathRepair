#include <bits/stdc++.h>
int main() {
  int a[100];
  int i, x, t, n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n - 1; i++)
    for (x = i + 1; x < n; x++)
      if (a[i] < a[x]) {
        t = a[i];
        a[i] = a[x];
        a[x] = t;
      }
  printf("%d", a[k - 1]);
  return 0;
}
