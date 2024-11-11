#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, z, y;
    scanf("%d%d", &a, &b);
    int c = a - b;
    if (c < 0) {
      c = -c;
    }
    z = c / 5;
    c = c - 5 * z;
    y = c / 2;
    c = c - 2 * y;
    printf("%d", z + y + c);
  }
  return 0;
}
