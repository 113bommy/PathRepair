#include <bits/stdc++.h>
using namespace std;
long long mod = (long long)1e10;
long long multiply(long long a, long long b) {
  long long c = a % mod;
  long long d = b % mod;
  long long e = d / 1000;
  long long f = d % 1000;
  long long prod = c * e;
  prod %= mod;
  prod *= 1000;
  prod %= mod;
  prod += c * f;
  prod %= mod;
  return prod;
}
long long sum_cube(long long x) {
  long long prod = x * (x + 1);
  prod /= 2;
  prod = multiply(prod, 2 * x + 1);
  while (prod % 3 != 0) {
    prod += mod;
  }
  prod /= 3;
  prod %= mod;
  return prod;
}
long long sub_query(long long x, long long y) {
  if (x == 0 || y == 0) return 0;
  if (x == y) {
    long long ans1 = 1;
    if (x % 2 == 0) {
      ans1 *= x * x;
      ans1 /= 2;
      long long sub = x * x + 1;
      ans1 = multiply(sub, ans1);
    } else {
      ans1 *= x * x + 1;
      ans1 /= 2;
      long long sub = x * x;
      ans1 = multiply(sub, ans1);
    }
    return ans1;
  } else if (x > y) {
    long long p = sub_query(y, y);
    long long s = sum_cube(x) - sum_cube(y);
    s %= mod;
    s += mod;
    s = multiply(s, y);
    long long s2 = y * (y - 1);
    s2 /= 2;
    s2 = multiply(x - y, s2);
    return (p + s - s2 + mod) % mod;
  } else {
    long long p = sub_query(x, x);
    long long s = sum_cube(y - 1) - sum_cube(x - 1);
    s %= mod;
    s += mod;
    s = multiply(s, x);
    long long s2 = x * (x + 1);
    s2 /= 2;
    s2 = multiply(y - x, s2);
    return (p + s + s2) % mod;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    long long ans = sub_query(x2, y2) + sub_query(x1 - 1, y1 - 1) -
                    sub_query(x2, y1 - 1) - sub_query(x1 - 1, y2);
    ans %= mod;
    ans += mod;
    ans %= mod;
    mod = (long long)1e9 + 7;
    long long ans2 = sub_query(x2, y2) + sub_query(x1 - 1, y1 - 1) -
                     sub_query(x2, y1 - 1) - sub_query(x1 - 1, y2);
    ans2 %= mod;
    ans2 += mod;
    ans2 %= mod;
    if (ans % mod == ans2) {
      printf("%I64d\n", ans);
    } else {
      printf("...%I64d\n", ans);
    }
    mod = (long long)1e10;
  }
  fflush(stdin);
  getchar();
}
