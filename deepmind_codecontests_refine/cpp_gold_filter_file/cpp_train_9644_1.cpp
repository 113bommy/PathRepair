#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double PI = acos(-1);
const long long MOD = 1000000007;
const long long FMOD = 998244353;
const long double eps = 1e-9;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
string s;
long long k;
long long dp[1003][1003][2];
long long a[1003];
long long solve(long long pos, long long cnt, long long fl) {
  if (pos == s.size()) {
    if (a[cnt] == k - 1) {
      return 1;
    }
    return 0;
  }
  if (dp[pos][cnt][fl] != -1) {
    return dp[pos][cnt][fl];
  }
  long long ans = 0;
  if (s[pos] == '1') {
    ans += solve(pos + 1, cnt + 1, fl);
    ans %= MOD;
    ans += solve(pos + 1, cnt, 1);
    ans %= MOD;
  } else {
    if (fl) {
      ans += solve(pos + 1, cnt + 1, fl);
      ans %= MOD;
    }
    ans += solve(pos + 1, cnt, fl);
    ans %= MOD;
  }
  return dp[pos][cnt][fl] = ans;
}
signed main() {
  cin >> s;
  cin >> k;
  if (k == 0) {
    cout << 1;
    return 0;
  }
  if (k == 1) {
    cout << s.size() - 1;
    return 0;
  }
  a[0] = 0;
  a[1] = 0;
  for (long long i = 2; i <= 1000; i++) {
    long long x = __builtin_popcount(i);
    a[i] = a[x] + 1;
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0);
}
