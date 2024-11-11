#include <bits/stdc++.h>
int main() {
  int n, i;
  double a, sum = 0;
  scanf("%d", &n);
  i = 0;
  while (i < n) {
    scanf("%lf", &a);
    sum += a;
    i++;
  }
  printf("%lf\n", (sum / n));
  return 0;
}
