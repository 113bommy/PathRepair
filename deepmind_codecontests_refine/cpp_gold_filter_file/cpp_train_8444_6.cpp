#include <bits/stdc++.h>
int main() {
  int y, b, r;
  scanf("%d %d %d", &y, &b, &r);
  printf("%d\n", std::min({y, b - 1, r - 2}) * 3 + 3);
  return 0;
}
