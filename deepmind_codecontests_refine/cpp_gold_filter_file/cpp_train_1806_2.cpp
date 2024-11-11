#include <bits/stdc++.h>
using namespace std;
int t;
long long k, l, r, p;
long long powmod(long long a, long long b, long long mod) {
  long long res = 1 % mod;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return res;
}
int main() {
  cin >> t;
  while (t-- > 0) {
    scanf("%I64d %I64d %I64d %I64d", &k, &l, &r, &p);
    if (p == 2) {
      if (k % 2 == 0) {
        printf("1\n");
      } else
        printf("0\n");
      continue;
    }
    long long a = powmod(k, powmod(2, l, p - 1), p), ans = 1;
    if (a % p != 1) {
      ans = (powmod(a, powmod(2, r - l + 1, p - 1), p) + p - 1) *
            powmod(a + p - 1, p - 2, p) % p;
    } else
      ans = powmod(2, r - l + 1, p);
    if (k % p == 0) ans = 1;
    if (k % 2 == 1 && r > l) {
      a = powmod(2, r - l, p);
      ans = ans * powmod(a, p - 2, p) % p;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
