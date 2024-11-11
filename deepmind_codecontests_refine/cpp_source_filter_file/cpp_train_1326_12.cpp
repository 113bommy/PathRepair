#include <bits/stdc++.h>
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int a, b, c, mx = 0;
  scanf("%d%d", &a, &b);
  if (a > mx) mx = a;
  if (b > mx) mx = b;
  a = gcd(6, 6 - mx + 1);
  if (mx == 0)
    printf("0/1\n");
  else if (mx == 6)
    printf("1/1\n");
  else
    printf("%d/%d\n", (6 - mx + 1) / a, 6 / a);
  return 0;
}
