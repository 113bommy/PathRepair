#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  int i, j;
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      if (a[j] < a[i]) {
        a[i] = a[j] + a[i];
        a[j] = a[i] - a[j];
        a[i] = a[i] - a[j];
      }
    }
  if (n % 2 == 1)
    printf("%d", a[n / 2]);
  else
    printf("%d", a[n / 2 - 1]);
}
