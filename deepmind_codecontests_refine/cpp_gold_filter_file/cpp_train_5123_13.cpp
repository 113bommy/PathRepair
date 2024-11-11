#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long mod = 998244353;
long long power(long long a, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) {
      ret = ret * a % mod;
    }
    n >>= 1;
    a = a * a % mod;
  }
  return ret;
}
const long long cute = power(100, mod - 2);
long long prob[200005], fail[200005];
int n;
int main() {
  scanf("%d", &n);
  long long cur = 1, sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", prob + i);
    prob[i] = cute * prob[i] % mod;
    fail[i] = cur * (1 - prob[i] + mod) % mod;
    cur = cur * prob[i] % mod;
    sum = (sum + (fail[i] * i % mod)) % mod;
  }
  sum = (sum + (cur * n)) % mod;
  long long ans = sum * power(cur, mod - 2);
  printf("%lld\n", ans % mod);
  return 0;
}
