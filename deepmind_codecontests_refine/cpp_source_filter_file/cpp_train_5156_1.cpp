#include <bits/stdc++.h>
int main() {
  int a, b, c, d, e;
  scanf("%1d%1d%1d%1d%1d", &a, &b, &c, &d, &e);
  long long int n = 10000 * a + 1000 * c + 100 * e + 10 * d + b, ret = 1;
  for (int i = 0; i < 5; i++) ret = (ret * n) % 100000;
  printf("%I64d", ret);
}
