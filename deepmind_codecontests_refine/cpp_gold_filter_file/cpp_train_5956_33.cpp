#include <bits/stdc++.h>
using namespace std;
const long long P = 998244353;
const long long N = 2e5 + 10;
long long modExp(long long a, long long b) {
  long long res = 1;
  for (long long mul = a; b > 0; b /= 2, mul = (mul * mul) % P)
    if (b % 2) res = (res * mul) % P;
  return res;
}
long long fact[N];
long long invFact[N];
long long powK[N];
void initializeConsts(long long k) {
  fact[0] = 1;
  invFact[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % P;
    invFact[i] = modExp(fact[i], P - 2);
  }
  powK[0] = 1;
  for (long long i = 1; i < N; i++) powK[i] = powK[i - 1] * (k - 2) % P;
}
long long nCr(long long n, long long r) {
  return fact[n] * invFact[r] % P * invFact[n - r] % P;
}
long long solve(long long k, long long n) {
  initializeConsts(k);
  long long ans = 0;
  for (long long j = 0; 2 * j <= n; j++)
    ans += powK[n - 2 * j] * nCr(n, j) % P * nCr(n - j, n - 2 * j) % P;
  ans = (modExp(k, n) - (ans % P) + P) % P;
  return (ans * modExp(2, P - 2)) % P;
}
signed main() {
  iostream::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  vector<long long> h(n);
  for (long long &h1 : h) cin >> h1;
  long long mul = 1, n1 = 0;
  for (long long i = 0; i < h.size(); i++)
    if (h[i] == h[(i + 1) % n])
      mul = mul * k % P;
    else
      n1++;
  cout << mul * solve(k, n1) % P << endl;
}
