#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 2e5 + 7;
const long long inf = 1e16;
const double pi = acos(-1.0);
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long fpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long n, m, t;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    if (n == 1) {
      printf("-1\n");
      continue;
    }
    if ((2 * n + 3) % 3 == 0) {
      for (int i = 0; i < n - 2; ++i) printf("2");
      printf("33\n");
    } else {
      for (int i = 0; i < n - 1; ++i) printf("2");
      printf("3\n");
    }
  }
  return 0;
}
