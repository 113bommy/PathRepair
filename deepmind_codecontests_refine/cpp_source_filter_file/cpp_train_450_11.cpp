#include <bits/stdc++.h>
using namespace std;
const int INF = 999999999;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;
long long a[2012], b[2012];
long long num[2012], den[2012], den_inv[2012];
long long x, y;
long long gcd(long long a, long long b) {
  if (a % b == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long ret = gcd(b, a % b);
  long long temp = y;
  y = x - y * (a / b);
  x = temp;
  return ret;
}
int main() {
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
  num[0] = 1;
  den[0] = 1;
  den_inv[0] = 1;
  for (int i = 1; i <= 2000; i++) {
    num[i] = ((k + i - 1) * num[i - 1]) % MOD;
    den[i] = (i * den[i - 1]) % MOD;
    gcd(den[i], MOD);
    den_inv[i] = ((x % MOD) + MOD) % MOD;
  }
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      b[i] = (b[i] + num[i - j] * den_inv[i - j] * a[j]) % MOD;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%I64d", b[i]);
  }
  putchar('\n');
  return 0;
}
