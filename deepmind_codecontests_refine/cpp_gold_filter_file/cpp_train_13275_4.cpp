#include <bits/stdc++.h>
long long n;
int main() {
  scanf("%I64d", &n);
  n %= 360;
  n = (n + 405) % 360 - 1;
  printf("%d\n", n / 90);
  scanf("\n");
  return 0;
}
