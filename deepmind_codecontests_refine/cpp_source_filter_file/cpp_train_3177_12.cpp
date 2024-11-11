#include <bits/stdc++.h>
int main() {
  int a, b, c;
  int x, y, z;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
  int a1 = a - x;
  int a2 = b - y;
  int a3 = c - z;
  if (a1 >= 0) a1 = a1 / 2;
  if (a2 >= 0) a2 = a2 / 2;
  if (a3 >= 0) a3 = a3 / 2;
  if (a1 + a2 + a3 == 0)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
