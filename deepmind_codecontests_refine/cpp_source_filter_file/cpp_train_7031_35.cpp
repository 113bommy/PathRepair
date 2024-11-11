#include <bits/stdc++.h>
int main() {
  int min = 1000000000;
  int a, b;
  for (int i = 0; i < 4; i++) {
    int a;
    scanf("%d", &a);
    if (a < min) min = a;
  }
  scanf("%d %d", &a, &b);
  if (b < min) min = b;
  printf("%d\n", min - a > 0 ? min - a : 0);
  return 0;
}
