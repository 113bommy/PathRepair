#include <bits/stdc++.h>
int main() {
  int a, b, c, d;
  scanf("%d%d", &a, &b);
  d = abs(a - b) / 2;
  printf("%d %d\nn", std::min(a, b), d);
}
