#include <bits/stdc++.h>
int main() {
  int y, b, r, sum;
  scanf("%d", &y);
  scanf("%d", &b);
  scanf("%d", &r);
  if (y <= b - 1 && y <= r - 2) {
    sum = (3 * y) + 3;
  } else if (b <= y + 1 && b <= r - 1) {
    sum = (3 * b);
  } else if (r <= y + 2 && r <= b + 1) {
    sum = (3 * r) - 3;
  }
  printf("%d", sum);
  return 0;
}
