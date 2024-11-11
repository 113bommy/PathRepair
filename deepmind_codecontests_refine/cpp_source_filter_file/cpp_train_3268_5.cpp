#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
constexpr long long infValue =
    std::is_same<T, int>::value ? 2000100007 : 8600000000000000007ll;
template <typename T>
constexpr long long maxValue =
    std::is_same<T, int>::value ? 1000000007 : 1000000000000000001ll;
const long long INF = infValue<long long>;
const long long MOD = 1000000007ll;
const double EPS = 1e-6;
const long long MAX = maxValue<long long>;
long long t[(1000111)];
void add(long long r, long long av) {
  for (; r < (1000111); r |= r + 1) t[r] = (t[r] + av) % MOD;
}
long long sum(long long r) {
  long long s = 0;
  for (; r >= 0; r = (r & r + 1) - 1) s = (s + t[r]) % MOD;
  return (s % MOD + MOD) % MOD;
}
long long get(long long r) {
  long long s = sum(r) - sum(r - 1);
  return (s % MOD + MOD) % MOD;
}
long long n, a[101010], answ;
int main(void) {
  scanf("%lld", &n);
  for (register long long i = 0; i < n; ++i) scanf("%lld", a + i);
  for (register long long i = 0; i < n; ++i) {
    long long s = sum(a[i]) + 1, av = get(a[i]);
    long long dv = s * a[i] - av;
    answ = ((answ + dv) % MOD + MOD) % MOD;
    add(a[i], dv - av);
  }
  printf("%lld\n", answ);
  return 0;
}
