#include <bits/stdc++.h>
int main() {
  int p1, p2, p3, p4, a, b, i, j, k, min;
  scanf("%d%d%d%d%d%d", &p1, &p2, &p3, &p4, &a, &b);
  min = 2000;
  if (p1 < min) min = p1;
  if (p2 < min) min = p2;
  if (p3 < min) min = p3;
  if (p4 < min) min = p4;
  if (b < min) min = b;
  if (a > min) a = min;
  printf("%d\n", min - a);
  return 0;
}
