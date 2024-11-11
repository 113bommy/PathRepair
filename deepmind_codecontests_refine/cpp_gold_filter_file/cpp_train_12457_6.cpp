#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
constexpr long long infValue =
    std::is_same<T, int>::value ? 2000000007 : 8600000000000000007ll;
template <typename T>
constexpr long long maxValue =
    std::is_same<T, int>::value ? 1000000007 : 1000000000000000001ll;
const long long INF = infValue<long long>;
const long long MOD = 1000000009ll;
const double EPS = 1e-6;
const long long MAX = maxValue<long long>;
long long binPow(long long a, long long x) {
  long long r = 1;
  while (x) {
    if (x & 1) r = r * a % MOD;
    a = a * a % MOD;
    x >>= 1;
  }
  return r;
}
int n, a, b, k;
long long answ;
char s[100101];
int main(void) {
  scanf("%d %d %d %d", &n, &a, &b, &k);
  scanf("%s", s);
  for (register long long i = 0; i < k; ++i) {
    answ += (s[i] == '+' ? 1ll : -1ll) * binPow(a, n - i) * binPow(b, i) % MOD;
    answ = (answ + MOD) % MOD;
  }
  n = (n + 1) / k;
  long long t = binPow(b, k) * binPow(binPow(a, k), MOD - 2) % MOD;
  if (t == 1)
    answ = answ * (n + 0) % MOD;
  else
    answ = answ * (1 - binPow(t, n) + MOD) % MOD *
           binPow(1 - t + MOD, MOD - 2) % MOD;
  printf("%lld\n", answ);
  return 0;
}
