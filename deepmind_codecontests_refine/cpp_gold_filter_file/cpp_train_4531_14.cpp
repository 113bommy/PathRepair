#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
template <class T>
inline T bigmod(T p, T e, T M) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    long long int t = bigmod(p, e / 2, M);
    return (T)((t * t) % M);
  }
  return (T)((long long int)bigmod(p, e - 1, M) * (long long int)p) % M;
}
template <class T>
inline T bigexp(T p, T e) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    long long int t = bigexp(p, e / 2);
    return (T)((t * t));
  }
  return (T)((long long int)bigexp(p, e - 1) * (long long int)p);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
int dx4[] = {1, 0, -1, 0};
int dy4[] = {0, 1, 0, -1};
int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long int lo, hi, mid, n, r, p, q, i1x, i1y, i2x, i2y, i3x, i3y, i4x, i4y,
    i5x, i5y, i6x, i6y;
unsigned long long int tmp;
int main() {
  scanf("%I64d", &n);
  n++;
  lo = 1LL;
  hi = 1000000000LL;
  r = 0;
  while (lo <= hi) {
    mid = (lo + hi) / 2LL;
    tmp = 3 * mid * (mid + 1) * (unsigned long long int)1;
    tmp -= mid;
    if (tmp >= n) {
      hi = mid - 1;
      r = max(r, mid);
    } else
      lo = mid + 1;
  }
  r = lo;
  mid = r - 1;
  tmp = 3 * mid * (mid + 1) * (unsigned long long int)1;
  tmp -= mid;
  n = n - tmp;
  p = (n) / (r);
  q = (n) % (r);
  if (q == 0)
    q = r, p = n / r;
  else
    p = n / r + 1, q = n % r;
  i1x = r - 1;
  i1y = -2 * (r - 1);
  i2x = i1x + (r - 1) + 1;
  i2y = 2;
  i3x = i2x - (r - 1) - 2;
  i3y = 2 * r;
  i4x = i3x - (2 * (r - 1)) - 1;
  i4y = i3y - 2;
  i5x = i4x - (r - 1) + 1;
  i5y = i4y - (2 * (r - 1)) - 2;
  i6x = i5x + (r - 1) + 2;
  i6y = i5y - (2 * (r - 1));
  if (p == 1) {
    i1x = i1x + (q - 1);
    i1y = i1y + (2 * (q - 1));
    printf("%I64d %I64d", i1x, i1y);
  } else if (p == 2) {
    i2x = i2x - (q - 1);
    i2y = i2y + (2 * (q - 1));
    printf("%I64d %I64d", i2x, i2y);
  } else if (p == 3) {
    i3x = i3x - (2 * (q - 1));
    printf("%I64d %I64d", i3x, i3y);
  } else if (p == 4) {
    i4x = i4x - (q - 1);
    i4y = i4y - (2 * (q - 1));
    printf("%I64d %I64d", i4x, i4y);
  } else if (p == 5) {
    i5x = i5x + (q - 1);
    i5y = i5y - (2 * (q - 1));
    printf("%I64d %I64d", i5x, i5y);
  } else if (p == 6) {
    i6x = i6x + (2 * (q - 1));
    printf("%I64d %I64d", i6x, i6y);
  }
  return 0;
}
