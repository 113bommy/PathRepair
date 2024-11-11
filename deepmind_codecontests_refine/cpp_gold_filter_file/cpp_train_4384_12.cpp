#include <bits/stdc++.h>
int main() {
  int w, h, k;
  int count = 0;
  scanf("%d %d %d", &w, &h, &k);
  for (int i = 0; i < k; i++) {
    count = count + ((w - 2) * 2 + (h - 2) * 2 + 4);
    w -= 4;
    h -= 4;
  }
  printf("%d", count);
  return 0;
}
