#include <bits/stdc++.h>
int main() {
  int a, b, c;
  float ans;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  ans = (a * b) / (b + c);
  printf("%f", ans);
  return 0;
}
