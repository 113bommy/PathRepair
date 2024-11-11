#include <bits/stdc++.h>
int main() {
  int w, h, k, t = 0;
  scanf("%d %d %d", &w, &h, &k);
  while (k--) {
    t += 2 * (w + h) - 4;
    w = w - 4;
    h = h - 4;
  }
  printf("%d", t);
  return 0;
}
