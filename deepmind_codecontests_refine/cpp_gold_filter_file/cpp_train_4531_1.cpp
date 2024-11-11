#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t;
struct data {
  int x, y;
} w[7];
long long a, b, c, x, y;
long long min(long long a, long long b) { return a > b ? b : a; }
int main() {
  scanf("%lld", &a);
  if (a == 0) {
    printf("0 0\n");
    return 0;
  }
  w[1] = {-2, 0};
  w[2] = {-1, -2};
  w[3] = {+1, -2};
  w[4] = {+2, 0};
  w[5] = {+1, +2};
  w[6] = {-1, +2};
  b = 1, c = 0;
  long long l = 1, r = 1000000000;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (1 + (1 + mid) * mid * 3ll + mid < a)
      b = 1 + (1 + mid) * mid * 3ll + mid, c = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  c++;
  a -= b;
  x = c;
  y = c * 2;
  if (!a) {
    printf("%lld %lld\n", x, y);
    return 0;
  }
  x += min(c, a) * w[1].x;
  y += min(c, a) * w[1].y;
  if (a <= c) {
    printf("%lld %lld\n", x, y);
    return 0;
  }
  a -= c;
  x += min(c, a) * w[2].x;
  y += min(c, a) * w[2].y;
  if (a <= c) {
    printf("%lld %lld\n", x, y);
    return 0;
  }
  a -= c;
  x += min(c, a) * w[3].x;
  y += min(c, a) * w[3].y;
  if (a <= c) {
    printf("%lld %lld\n", x, y);
    return 0;
  }
  a -= c;
  x += min(c, a) * w[4].x;
  y += min(c, a) * w[4].y;
  if (a <= c) {
    printf("%lld %lld\n", x, y);
    return 0;
  }
  a -= c;
  x += min(c, a) * w[5].x;
  y += min(c, a) * w[5].y;
  if (a <= c) {
    printf("%lld %lld\n", x, y);
    return 0;
  }
  a -= c;
  x += w[5].x;
  y += w[5].y;
  if (a <= 1) {
    printf("%lld %lld\n", x, y);
    return 0;
  }
  a -= 1;
  x += min(c, a) * w[6].x;
  y += min(c, a) * w[6].y;
  if (a <= c) {
    printf("%lld %lld\n", x, y);
    return 0;
  }
  a -= c;
  return 0;
}
