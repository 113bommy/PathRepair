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
long long dp[50][2];
long long s, x;
long long solve(long long idx, long long carry) {
  if ((1ll << idx) > s) {
    if (carry) return 0;
    return 1;
  }
  if (dp[idx][carry] != -1) return dp[idx][carry];
  long long ans = 0;
  if ((x >> idx) & 1ll) {
    if ((s >> idx) & 1ll) {
      if (carry) {
      } else {
        ans = 2 * solve(idx + 1, 0);
      }
    } else {
      if (carry) {
        ans = 2 * solve(idx + 1, 1);
      } else {
      }
    }
  } else {
    if ((s >> idx) & 1ll) {
      if (carry) {
        ans = solve(idx + 1, 0) + solve(idx + 1, 1);
      } else {
      }
    } else {
      if (carry) {
      } else {
        ans = solve(idx + 1, 0) + solve(idx + 1, 1);
      }
    }
  }
  return dp[idx][carry] = ans;
}
signed main() {
  cin >> s >> x;
  memset(dp, -1, sizeof dp);
  if (s < x) {
    cout << 0;
    return 0;
  }
  long long ans = solve(0, 0);
  if (s == x)
    cout << ans - 2;
  else
    cout << ans;
}
