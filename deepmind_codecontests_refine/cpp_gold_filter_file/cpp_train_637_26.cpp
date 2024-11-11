#include <bits/stdc++.h>
int main() {
  long long int a, b, m = 0, n = 0;
  scanf("%lld %lld", &a, &b);
  long long int crr[a], krr[b];
  int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  for (long long int i = 0; i < a; i++) {
    scanf("%lld", &crr[i]);
    if (crr[i] % 2 == 1)
      y1++;
    else
      x1++;
  }
  for (long long int i = 0; i < b; i++) {
    scanf("%lld", &krr[i]);
    if (krr[i] % 2 == 1)
      y2++;
    else
      x2++;
  }
  if (y1 <= x2) {
    m = y1;
  }
  if (y1 > x2) {
    m = x2;
  }
  if (x1 <= y2) {
    n = x1;
  }
  if (x1 > y2) {
    n = y2;
  }
  printf("%lld", (m + n));
  return 0;
}
