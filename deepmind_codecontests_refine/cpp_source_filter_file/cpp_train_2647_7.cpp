#include <bits/stdc++.h>
int main() {
  int n, x, y, i, l = 0, k = 0;
  int b[1000], c[1000];
  scanf("%d", &n);
  for (i = 0; i < 1000; i++) {
    b[i] = 0;
  }
  for (i = 0; i < 1000; i++) {
    c[i] = 0;
  }
  for (i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    if (b[x] == 0) {
      b[x] = x;
      ++k;
    }
    if (c[y] == 0) {
      c[y] = y;
      ++l;
    }
  }
  printf("%d", (l > k) ? k : l);
}
