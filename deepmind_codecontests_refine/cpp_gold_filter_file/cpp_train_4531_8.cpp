#include <bits/stdc++.h>
long long n, now, sum;
long long lower(long long n) {
  long long l = 0, r = 1e9, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (3 * mid * mid + 3 * mid < n)
      l = mid + 1;
    else
      r = mid;
  }
  return r;
}
int main() {
  scanf("%I64d", &n);
  if (n == 0)
    printf("0 0\n");
  else {
    long long c = lower(n);
    long long left = n - (3 * (c - 1) * (c - 1) + 3 * (c - 1));
    long long x = c * 2, y = 0;
    if (left >= c) {
      left -= c;
      x -= c, y += 2 * c;
    } else
      x -= left, y += 2 * left, left = 0;
    if (left >= c) {
      left -= c;
      x -= 2 * c;
    } else
      x -= 2 * left, left = 0;
    if (left >= c) {
      left -= c;
      x -= c, y -= 2 * c;
    } else
      x -= left, y -= 2 * left, left = 0;
    if (left >= c) {
      left -= c;
      x += c, y -= 2 * c;
    } else
      x += left, y -= 2 * left, left = 0;
    if (left >= c) {
      left -= c;
      x += 2 * c;
    } else
      x += 2 * left, y, left = 0;
    if (left >= c) {
      left -= c;
      x += c, y += 2 * c;
    } else
      x += left, y += 2 * left, left = 0;
    printf("%I64d %I64d\n", x, y);
  }
}
