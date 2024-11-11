#include <bits/stdc++.h>
int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if (a == b || a < b)
    printf("second");
  else
    printf("first");
  return 0;
}
