#include <bits/stdc++.h>
int main() {
  int a[1000000], b[1000000], i, j;
  int q = 0, x, sira;
  scanf("%d %d", &x, &sira);
  for (i = 1; i <= x; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1;; i++) {
    if (q + i >= sira) {
      sira -= q;
      break;
    }
    q += i;
  }
  printf("%d", a[sira]);
}
