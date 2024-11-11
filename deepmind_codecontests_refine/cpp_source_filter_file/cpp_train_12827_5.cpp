#include <bits/stdc++.h>
int main() {
  int n;
  double x = 0;
  scanf("%d", &n);
  for (float i = 1; i <= n; i++) {
    x = x + (1.0 / i);
  }
  printf("%.8lf", x);
}
