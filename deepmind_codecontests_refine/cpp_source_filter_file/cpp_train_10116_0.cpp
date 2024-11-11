#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool smin(T &a, const T &b) {
  return a > b ? a = b : a;
}
template <typename T>
inline bool smax(T &a, const T &b) {
  return a < b ? a = b : a;
}
const long long N = (long long)1e5 + 5, mod = (long long)0;
long long dp[N], odp[N], a[N], o[N], b[N], sum[N];
long long cmp(long long first, long long second) {
  return b[first] > b[second];
}
int32_t main() {
  long long n;
  cin >> n;
  for (long long j = 0; j < n; ++j) cin >> a[j], o[j] = j;
  memset(dp, 63, sizeof dp);
  dp[0] = 0;
  for (long long bit = 0; bit < 4; ++bit) {
    memcpy(odp, dp, sizeof dp);
    memset(dp, 63, sizeof dp);
    for (long long j = 0; j < n; ++j) {
      b[j] = a[j] & ((1ll << (bit)) - 1);
    }
    sort(o, o + n, cmp);
    for (long long j = 0; j < n; ++j) {
      long long i = o[j];
      sum[j + 1] = sum[j] + (a[i] >> bit & 1);
    }
    for (long long over = 0; over <= n; ++over) {
      long long cur_nover = sum[over];
      long long ones = over - sum[over] + sum[n] - sum[over];
      long long zeros = n - ones;
      {
        long long add = ones;
        long long nover = cur_nover + add;
        dp[nover] = min(dp[nover], odp[over] + add);
      }
      {
        long long add = zeros;
        long long nover = cur_nover;
        dp[nover] = min(dp[nover], odp[over] + add);
      }
    }
  }
  cout << dp[0] << '\n';
}
