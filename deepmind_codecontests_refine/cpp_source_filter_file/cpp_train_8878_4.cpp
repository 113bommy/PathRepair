#include <bits/stdc++.h>
int a[180000], luck[180000];
int main() {
  int i, k, sum, mod, d, x, y, j;
  memset(luck, 0, sizeof(luck));
  for (i = 1; i < 180000; i++) {
    k = i;
    d = 0;
    while (k > 0) {
      mod = k % 10;
      if (mod == 4 || mod == 7) {
        a[d] = mod;
        d++;
      }
      k = k / 10;
    }
    sum = 0;
    for (j = d - 1; j >= 0; j--) sum = sum * 10 + a[j];
    luck[i] = sum;
  }
  while (scanf("%d%d", &x, &y) != EOF) {
    for (i = x; i < 180000; i++) {
      if (luck[i] == y) {
        printf("%d", i);
        printf("\n");
        break;
      }
    }
  }
  return 0;
}
