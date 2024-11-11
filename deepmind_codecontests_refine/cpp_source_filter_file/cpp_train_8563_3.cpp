#include <bits/stdc++.h>
int mine_gcd(int a, int b) {
  if (b == 0) return a;
  return mine_gcd(b, a % b);
}
int getsum(int a, int base) {
  int sum = 0;
  while (a) {
    sum += a % base;
    a /= base;
  }
  return sum;
}
int main() {
  int a;
  long totalsum = 0;
  scanf("%d", &a);
  for (int i = 2; i <= a - 1; i++) totalsum += getsum(a, i);
  int gcd = mine_gcd(totalsum, a - 2);
  printf("%ld/%d\n", totalsum / gcd, a - 2 / gcd);
  return 0;
}
