#include <bits/stdc++.h>
int main() {
  int s, a, b, c;
  scanf("%d%d%d%d", &s, &a, &b, &c);
  if (a == 0 && b == 0 && c == 0)
    puts("0.0 0.0 0.0");
  else {
    double ans = 1.0 * s / (a + b + c);
    printf("%.8f %.8f %.8f\n", a * ans, b * ans, c * ans);
  }
  return 0;
}
