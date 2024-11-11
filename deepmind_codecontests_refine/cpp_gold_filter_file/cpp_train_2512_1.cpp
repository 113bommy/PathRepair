#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
long long invfact[MAXN], fact[MAXN];
long long power(long long a, long long n) {
  long long result = 1;
  while (n) {
    if (n & 1LL) result = (result * a) % MOD;
    n >>= 1LL;
    a = (a * a) % MOD;
  }
  return result;
}
void prepare() {
  fact[0] = 1;
  invfact[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  invfact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
  for (int i = MAXN - 2; i >= 1; --i) {
    invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
  }
}
long long nPr(int n, int k) {
  long long result = fact[n];
  result = (result * invfact[n - k]) % MOD;
  return result;
}
long long nCr(int n, int k) {
  if (k > n) return 0;
  long long result = fact[n];
  result = (result * invfact[n - k]) % MOD;
  result = (result * invfact[k]) % MOD;
  return result;
}
long long cayley(int n, int k) {
  if (n == k) return 1;
  long long result = power(n, n - k - 1);
  result = (result * k) % MOD;
  return result;
}
int n, m, a, b;
int main() {
  scanf("%d %d %d %d", &n, &m, &a, &b);
  prepare();
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    long long result = nPr(n - 2, i - 1);
    result = (result * nCr(m - 1, i - 1)) % MOD;
    result = (result * power(m, n - 1 - i)) % MOD;
    result = (result * cayley(n, i + 1)) % MOD;
    ans = (ans + result) % MOD;
  }
  printf("%lld\n", ans);
}
