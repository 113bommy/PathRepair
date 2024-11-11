#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
long long get_gcd(long long x, long long y) {
  while (y > 0) {
    int temp = x % y;
    x = y;
    y = temp;
  }
  return x;
}
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    long long u, v;
    for (int i = n + 1;; i++)
      if (isPrime(i)) {
        u = i;
        break;
      }
    for (int i = n;; i--)
      if (isPrime(i)) {
        v = i;
        break;
      }
    long long x = u * v - 2 * (u + v) + 2l * n + 2;
    long long y = 2 * u * v;
    long long gcd = get_gcd(x, y);
    x = x / gcd;
    y = y / gcd;
    printf("%lld/%lld\n", x, y);
  }
  return 0;
}
