#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n, long long m = (long long)(1e9 + 7)) {
  return (n % m + m) % m;
}
inline long long gcd(long long a, long long b) {
  return (b == 0LL) ? a : gcd(b, a % b);
}
inline long long modPow(long long a, long long b,
                        long long m = (long long)(1e9 + 7)) {
  long long ret = 1LL;
  while (b > 0LL) {
    if (b & 1) ret = mod(ret * a, m);
    a = mod(a * a, m);
    b >>= 1;
  }
  return ret;
}
inline bool leapYear(int year) {
  return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}
int main() {
  int n, k;
  while (scanf("%d %d", &n, &k) == 2) {
    if (n * (n + 1) / 2 < k)
      printf("no solution\n");
    else {
      for (int y = (0); y < ((n)); y++) printf("0 %d\n", y);
    }
  }
  return 0;
}
