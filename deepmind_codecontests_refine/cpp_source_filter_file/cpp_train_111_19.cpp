#include <bits/stdc++.h>
int main() {
  int n, s = 0, ms = 0, i, mx, k, a[10000];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (!i)
      k = a[i];
    else if (a[i] > k)
      k = a[i];
    s += a[i];
  }
  k--;
  while (ms <= k) {
    k++;
    ms = (n * k) - s;
  }
  printf("%d\n", k);
  return 0;
}
