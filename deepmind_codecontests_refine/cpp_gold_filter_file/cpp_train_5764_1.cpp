#include <bits/stdc++.h>
int main() {
  int a = 3, b, n;
  long long ans, temp;
  scanf("%d%d", &b, &n);
  ans = 1;
  temp = a;
  while (b) {
    if (b % 2) ans = (ans % n) * temp;
    b /= 2;
    temp = temp % n;
    temp = (temp * temp) % n;
  }
  printf("%I64d\n", (ans - 1 + n) % n);
  return 0;
}
