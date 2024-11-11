#include <bits/stdc++.h>
int main() {
  int x, y;
  scanf("%d", &x);
  if (x % 5 == 0)
    y = x / 5;
  else
    y = x / 5 + 1;
  printf("%d %d", x, y);
  return 0;
}
