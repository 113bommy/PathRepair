#include <bits/stdc++.h>
int main() {
  int r, g, b, t = 0;
  scanf("%d %d %d", &r, &g, &b);
  r = (r + 1) / 2;
  g = (g + 1) / 2;
  b = (b + 1) / 2;
  if (r > g && r > b) {
    printf("%d", 27 + 3 * r);
  } else if (g > r && g > b) {
    printf("%d", 28 + 3 * g);
  } else if (b > r && b > g) {
    printf("%d", 29 + 3 * b);
  } else if (g == r && g > b) {
    printf("%d", 28 + 3 * r);
  } else if (g == b && g > r) {
    printf("%d", 29 + 3 * b);
  } else if (r == b && r > g) {
    printf("%d", 28 + 3 * r);
  } else if (r == b && b == g) {
    printf("%d", 29 + 3 * r);
  }
  scanf(" ");
}
