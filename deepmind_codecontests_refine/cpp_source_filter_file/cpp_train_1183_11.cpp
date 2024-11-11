#include <bits/stdc++.h>
int main() {
  int i, j, k, t = 0, n, a[100];
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++)
      if (a[j] > a[j + 1]) {
        t = a[j];
        a[j] = a[j + 1];
        a[j + 1] = t;
      }
    t = 0;
  }
  if (k >= n)
    printf("-1");
  else
    printf("%d %d", a[n - k], a[n - k]);
}
