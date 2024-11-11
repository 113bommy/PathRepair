#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int INF = 2e9;
const long long INFLL = 1e18;
const int MAX_N = 1;
long long N;
long long ans = 0;
long long multi(long long x, long long y) {
  if (y == 0) return 1LL;
  if (y == 1) return x % MOD;
  long long m = multi(x, y / 2);
  if (y % 2) return (m * m % MOD) * x % MOD;
  return (m * m) % MOD;
}
int main() {
  scanf("%lld", &N);
  for (long long k = 1; k <= N; k++) {
    ans = 0LL;
    if (k <= N - 2) {
      long long add = (N - k - 1) % MOD;
      add = (add * 900LL) % MOD;
      add = (add * multi(10, N - k - 2)) % MOD;
      ans = (ans + add) % MOD;
    }
    if (k != N) {
      long long add = (180LL * multi(10LL, N - k - 1)) % MOD;
      ans = (ans + add) % MOD;
    } else {
      ans = 10;
    }
    printf("%lld ", ans);
  }
  return 0;
}
