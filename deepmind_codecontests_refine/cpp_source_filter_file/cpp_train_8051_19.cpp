#include <bits/stdc++.h>
int a, i, n;
double res;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    res += a / 100.0;
  }
  printf("%lf\n", res / n);
  return 0;
}
