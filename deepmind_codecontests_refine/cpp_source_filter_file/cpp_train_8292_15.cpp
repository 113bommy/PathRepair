#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const long long M = 998244353;
int n;
long long ans, fact[N] = {1}, inv[N] = {1};
long long choose(int n, int k) {
  return (fact[n] * inv[k] % M) * inv[n - k] % M;
}
long long power(long long base, long long to) {
  long long ret = 1;
  while (to) {
    if (to & 1) ret = ret * base % M;
    to >>= 1;
    base = base * base % M;
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < N; i++)
    fact[i] = i * fact[i - 1] % M, inv[i] = power(fact[i], M - 2);
  for (int i = 1, neg = 1; i <= n; i++, neg *= -1)
    ans += ((2 * neg * choose(n, i) % M) * power(3, i) % M) *
           power(3, n * 1LL * (n - i) % (M - 1)) % M;
  for (int i = 0, neg = -1; i < n; i++, neg *= -1)
    ans += (3 * choose(n, i) * neg % M) *
           (power(1 - power(3, i), n) - power(-power(3, i), n)) % M;
  printf("%lld\n", (ans + M) % M);
}
