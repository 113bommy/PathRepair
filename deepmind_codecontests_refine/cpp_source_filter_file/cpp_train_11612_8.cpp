#include <bits/stdc++.h>
int main() {
  int h1, h2, a, b;
  scanf("%d %d", &h1, &h2);
  scanf("%d %d", &a, &b);
  if (h2 - h1 < 8 * a)
    printf("%d", 0);
  else if (a <= b)
    printf("%d", -1);
  else {
    h1 = h1 + a * 8 - b * 12;
    int count = 1;
    while (h1 + 12 * a < h2) {
      h1 = a * 12 + h1 - b * 12;
      count++;
    }
    printf("%d", count);
  }
  return 0;
}
