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
const long long MOD = 998244353ll;
const double EPS = 1e-6;
const long long MAX = maxValue<long long>;
using pr = pair<long long, long long>;
long long n, m, answ;
char s[5050][5050];
long long dp[5050][5050];
long long cnt[5050];
int main(void) {
  scanf("%d %d", &n, &m);
  for (register long long i = 0; i < n; ++i) scanf("%s", s[i]);
  for (register long long i = 0; i < n; ++i) {
    long long l = -1;
    for (register long long j = 0; j < m; ++j) {
      if (s[i][j] == '1') {
        if (l == -1) l = i;
        ++dp[l][i];
      } else
        l = -1;
    }
  }
  for (register long long r = m - 1; r >= 0; --r) {
    memset(cnt, 0, sizeof(cnt));
    for (register long long l = r; l >= 0; --l) {
      cnt[l] += dp[l][r];
    }
    for (register long long l = 0; l <= (r); ++l) {
      cnt[l] += l ? cnt[l - 1] : 0ll;
      answ = max(answ, cnt[l] * (r - l + 1));
    }
  }
  printf("%lld\n", answ);
  return 0;
}
