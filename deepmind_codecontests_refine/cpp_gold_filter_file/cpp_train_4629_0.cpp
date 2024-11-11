#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long b, long long c) {
  long long v = 1;
  for (; b; b >>= 1, a = a * a % c)
    if (b & 1) v = v * a % c;
  return v;
}
long long inv(long long x) { return qpow(x, mod - 2, mod); }
const int maxn = 5 + 1e5;
void odd(void) {}
int main() {
  int n;
  cin >> n;
  if (n < 4)
    puts("NO");
  else {
    puts("YES");
    if (n == 4) {
      printf(
          "1 * 2 = 2\n"
          "2 * 3 = 6\n"
          "4 * 6 = 24\n");
    } else if (n == 5) {
      printf(
          "2 * 4 = 8\n"
          "5 - 3 = 2\n"
          "1 + 2 = 3\n"
          "3 * 8 = 24\n");
    } else if (n % 2 == 0) {
      printf(
          "2 * 3 = 6\n"
          "4 * 6 = 24\n"
          "24 * 1 = 24\n");
      while (n > 4) {
        printf("%d - %d = 1\n", n, n - 1);
        printf("1 * 24 = 24\n");
        n -= 2;
      }
    } else {
      printf(
          "2 * 4 = 8\n"
          "5 - 3 = 2\n"
          "1 + 2 = 3\n"
          "3 * 8 = 24\n");
      while (n > 5) {
        printf("%d - %d = 1\n", n, n - 1);
        printf("1 * 24 = 24\n");
        n -= 2;
      }
    }
  }
}
