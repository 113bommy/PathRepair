#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long exp(long long a, long long b) {
  long long ans = 1, apow = a;
  while (b > 0) {
    if (b % 2) ans = (ans * apow) % mod;
    b /= 2;
    apow = (apow * apow) % mod;
  }
  return ans;
}
long long fact[1001], invfact[1001];
int main() {
  long long k, i, j;
  long long n, p, ans, mul, ball, m;
  fact[1] = 1;
  invfact[1] = 1;
  for (i = 2; i <= 1001; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    invfact[i] = exp(fact[i], mod - 2);
  }
  invfact[0] = 1;
  scanf("%lld", &k);
  ans = 1;
  ball = 0;
  for (i = 0; i < k; i++) {
    scanf("%lld", &j);
    p = 1;
    for (m = ball + j - 1, n = 1; n <= j - 1; n++, m--) p = (p * m) % mod;
    p = (p * invfact[j - 1]) % mod;
    ans = (ans * p) % mod;
    ball += j;
  }
  printf("%lld\n", ans);
  return 0;
}
