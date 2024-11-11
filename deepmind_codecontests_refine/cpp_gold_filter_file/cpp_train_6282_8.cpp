#include <bits/stdc++.h>
int gcd(int a, int b) {
  if (b > 0) return gcd(b, a % b);
  return a;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[101], b[101];
  for (int i = 0; i < n + 1; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m + 1; i++) scanf("%d", &b[i]);
  int num_sign = a[0] / (int)fabs(a[0]), den_sign = b[0] / (int)fabs(b[0]);
  int sign = num_sign * den_sign;
  a[0] = (int)fabs(a[0]);
  b[0] = (int)fabs(b[0]);
  if (n > m) {
    if (sign == 1)
      printf("Infinity\n");
    else if (sign == -1)
      printf("-Infinity\n");
  } else if (m > n) {
    printf("0/1\n");
  } else if (m == n) {
    int div = gcd(a[0], b[0]);
    if (sign == 1)
      printf("%d/%d\n", a[0] / div, b[0] / div);
    else
      printf("-%d/%d\n", a[0] / div, b[0] / div);
  }
}
