#include <bits/stdc++.h>
int main() {
  int g = 1, b, i, h = 1, n, a[1000], c = 1;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b = i - 1;
    if (i > 1) {
      h = 1;
      while (b > 0) {
        if (a[i] == a[b]) h++;
        b--;
      }
      if (h == 1) c++;
      if (h != 0 && h > g) {
        g = h;
      }
    }
  }
  printf("%d %d\n", g, c);
  return 0;
}
