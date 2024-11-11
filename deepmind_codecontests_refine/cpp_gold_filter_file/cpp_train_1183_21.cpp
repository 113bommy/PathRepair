#include <bits/stdc++.h>
int main() {
  int n, k, i, j, dy, s = 0;
  scanf("%d %d", &n, &k);
  int dizi[n];
  for (i = 0; i < n; i++) scanf(" %d", &dizi[i]);
  for (i = 0;; i++) {
    dy = 0;
    for (j = 0; j < n - i - 1; j++)
      if (dizi[j] > dizi[j + 1]) {
        dizi[j] ^= dizi[j + 1];
        dizi[j + 1] ^= dizi[j];
        dizi[j] ^= dizi[j + 1];
        dy = 1;
      };
    if (dy == 0) break;
  }
  for (i = n - 1; i >= 0; i--) {
    s++;
    if (s == k) {
      printf("%d 0", dizi[i]);
      return 0;
    }
  }
  printf("-1");
  return 0;
}
