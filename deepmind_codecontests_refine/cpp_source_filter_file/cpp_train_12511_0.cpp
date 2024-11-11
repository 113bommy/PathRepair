#include <bits/stdc++.h>
int main() {
  double n, k;
  scanf("%lf", &n);
  scanf("%lf", &k);
  printf("%lf", n - ((-3 + sqrt(9 + 8 * (n + k))) / 2));
}
