#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long MOD = 998244353;
const int MAXN = 200000 + 5;
const int MAXM = 200000 + 5;
long long b[MAXM];
long long qpow(long long a, long long n) {
  a %= MOD;
  long long ans = 1;
  long long tmp = a;
  while (n) {
    if (n & 1) ans = ans * tmp % MOD;
    tmp = tmp * tmp % MOD;
    n >>= 1;
  }
  return ans;
}
long long inv(long long a) { return qpow(a, MOD - 2); }
int main() {
  long long n, A;
  int m;
  while (~scanf("%lld%d%lld", &n, &m, &A)) {
    long long ans = 1;
    for (int i = 1; i <= m; i++) {
      scanf("%d", &b[i]);
      long long c = b[i] - b[i - 1];
      ans = ans * (qpow(A, 2 * c) + qpow(A, c)) * inv(2) % MOD;
    }
    ans = ans * qpow(A, n - 2 * b[m]) % MOD;
    printf("%lld\n", ans);
  }
  return 0;
}
