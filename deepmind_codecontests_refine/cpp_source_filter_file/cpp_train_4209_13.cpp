#include <bits/stdc++.h>
int h[1000];
int main() {
  int n, k, i, j, t, top = 0, a[1000], b[1000], s = 0, max;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < k; i++) {
    for (j = 0; j < n / k; j++) {
      b[j] = a[i + k * j];
    }
    for (j = 1; j < n / k; j++) h[j] = 0;
    max = 0;
    for (j = 0; j < n / k; j++) h[b[j]]++;
    for (j = 1; j < 999; j++)
      if (h[j] > max) max = h[j];
    top += max;
  }
  printf("%d", n - top);
  return 0;
}
