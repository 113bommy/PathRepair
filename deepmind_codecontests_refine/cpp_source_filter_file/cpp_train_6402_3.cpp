#include <bits/stdc++.h>
using namespace std;
using namespace std;
const double PI = acos(-1.0);
const double MAXN = 1000000.0;
long long inv(long long a, long long m) {
  int p = 1, q = 0, b = m, c, d;
  while (b) {
    c = a / b;
    d = a;
    a = b;
    b = d % b;
    d = p;
    p = q;
    q = d - c * q;
  }
  return p < 0 ? p + m : p;
}
long long power(long long a, long long b) {
  long long k = a, res = 1;
  while (b) {
    if (b & 1) res *= k % 1000000007;
    k = k * k % 1000000007;
    b >>= 1;
  }
  return res;
}
long long c[2100000];
int main(int argc, char *argv[]) {
  long long n;
  while (scanf("%lld", &n) != EOF) {
    memset(c, 0, sizeof(c));
    long long res = (power(2, n + 1) - 1 + 1000000007) % 1000000007;
    c[n] = 1;
    for (int i = n + 1; i <= 2 * n; i++) {
      c[i] = c[i - 1] * i % 1000000007 * inv(i - n, 1000000007) % 1000000007;
    }
    long long count = pow(2, n);
    for (int i = n + 1; i <= 2 * n; i++) {
      count = (2 * count - 2 * c[i - 1] + 2 * 1000000007) % 1000000007;
      res = (res + count) % 1000000007;
    }
    printf("%lld\n", res);
  }
  return 0;
}
