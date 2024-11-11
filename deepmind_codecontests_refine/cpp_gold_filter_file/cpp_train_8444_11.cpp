#include <bits/stdc++.h>
int main() {
  int y, b, r;
  scanf("%d%d%d", &y, &b, &r);
  y = y + (y + 1) + (y + 2);
  b = b + (b + 1) + (b - 1);
  r = r + (r - 1) + (r - 2);
  if (y <= b && y <= r) {
    printf("%d", y);
  } else if (b <= y && b <= r) {
    printf("%d", b);
  } else {
    printf("%d", r);
  }
  return 0;
}
