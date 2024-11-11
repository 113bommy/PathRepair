#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  int a, b, x, y, s;
  while (t--) {
    scanf("%d%d%d%d", &a, &b, &x, &y);
    int p1 = a * y;
    int p2 = b * x;
    int p3 = a * (b - y - 1);
    int p4 = b * (a - x - 1);
    p2 = (p2 > p1) ? p2 : p1;
    p4 = (p4 > p3) ? p4 : p3;
    s = (p2 > p4) ? p2 : p4;
    printf("%d", s);
  }
  return 0;
}
