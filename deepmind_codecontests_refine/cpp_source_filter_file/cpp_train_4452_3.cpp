#include <bits/stdc++.h>
long long mini(long long x, long long y) {
  if (x < y) return x;
  return y;
}
long long binS1(long long min, long long max, long long n) {
  if (max == min) {
    return max;
  } else if ((max - min) == 1) {
    if (max * (max + 1) <= 2 * n) return max;
    return min;
  }
  long long mid = (max + min) / 2;
  long long reac = (mid < 2000000000) ? (mid * (mid + 1)) / 2 : n + 1;
  if (reac < n) {
    return binS1(mid, max, n);
  } else if (reac == n) {
    return mid;
  } else {
    return binS1(min, mid - 1, n);
  }
}
long long binS2(long long min, long long max, long long n, long long h) {
  if (max == min) {
    return max;
  } else if ((max - min) == 1) {
    long long reac1 = (2 * h * max + 2 * h + max * max + max) / 2;
    long long reac2 = ((h + max) * (h + max - 1)) / 2;
    if ((n - reac1) >= reac2) return max;
    return min;
  }
  long long mid = (max + min) / 2;
  long long reac1 = (2 * h * mid + 2 * h + mid * mid + mid) / 2;
  long long reac2 = ((h + mid) * (h + mid - 1)) / 2;
  if ((n - reac1) > reac2) {
    return binS2(mid, max, n, h);
  } else if ((n - reac1) == reac2) {
    return mid;
  } else {
    return binS2(min, mid - 1, n, h);
  }
}
int main() {
  long long n, h;
  bool flag = false;
  scanf("%I64d %I64d", &n, &h);
  if (h < 2000000000) {
    if ((h * (h + 1)) > (2 * n)) {
      long long k = binS1(0, h - 1, n);
      if (k * (k + 1) == 2 * n)
        printf("%I64d", k);
      else
        printf("%I64d", k + 1);
    } else {
      long long k =
          binS2(0, mini(1000000000000000000 / h, 2000000000 - h), n, h);
      long long res = k + h + k;
      long long rem = (2 * h * k + 2 * h + k * k + k) / 2;
      rem = n - rem;
      rem -= ((h + k) * (h + k - 1)) / 2;
      if (rem == 0)
        printf("%I64d", res);
      else if (res <= n)
        printf("%I64d", res + 1);
      else
        printf("%I64d", res + 2);
    }
  } else {
    long long k = binS1(0, h - 1, n);
    if (k * (k + 1) == 2 * n)
      printf("%I64d", k);
    else
      printf("%I64d", k + 1);
  }
  return 0;
}
