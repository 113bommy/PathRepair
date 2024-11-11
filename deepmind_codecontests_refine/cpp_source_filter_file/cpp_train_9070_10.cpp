#include <bits/stdc++.h>
#pragma comment(linker, "/stack:20000000")
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
using pr = pair<long long, long long>;
long long w1, h1, w2, h2;
int main(void) {
  scanf("%lld %lld %lld %lld", &w1, &h1, &w2, &h2);
  printf("%lld\n", (h1 + 1) * 2 + w1 + (h2 + 1) * 2 + w2 + (w1 == w2 + 1));
  return 0;
}
