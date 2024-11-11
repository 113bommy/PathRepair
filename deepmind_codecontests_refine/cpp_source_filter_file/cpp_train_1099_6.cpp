#include <bits/stdc++.h>
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
using namespace std;
int main() {
  int i, j;
  int n;
  scanf("%d", &n);
  if (n == 0) {
    printf("%d\n", 1);
    return 0;
  }
  n = n % 4;
  if (n == 0)
    printf("%d\n", 6);
  else if (n == 1)
    printf("%d\n", 8);
  else if (n == 2)
    printf("%d\n", 4);
  else
    printf("%d\n", 6);
  return 0;
}
