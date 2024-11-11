#include <bits/stdc++.h>
int a[100], i, j, maxim, h, l, n, b;
int main() {
  scanf("%d", &n);
  scanf("%d", &l);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  i = 0;
  j = 0;
  b = l;
  maxim = l;
  while (i < n) {
    if (l % a[i] == 0) {
      b = l / a[i];
    }
    if (b <= maxim) maxim = b;
    i++;
  }
  printf("%d", maxim);
}
