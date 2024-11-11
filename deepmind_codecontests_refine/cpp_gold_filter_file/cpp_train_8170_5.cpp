#include <bits/stdc++.h>
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a < b)
    puts("-1");
  else if (a == b)
    printf("%d\n", a);
  else {
    int k = ((double)a + b) / (2 * b);
    double x = double(a + b) / (2 * k);
    printf("%.9f\n", x);
  }
  return 0;
}
