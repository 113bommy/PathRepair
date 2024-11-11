#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const int INF = 1e9 + 7;
const int MOD = 998244353;
long long qpow(long long n, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * (n % MOD) % MOD;
    k >>= 1;
    n = n * n;
  }
  return res;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long ans = qpow(2, m + n) % MOD;
  printf("%lld\n", ans);
}
