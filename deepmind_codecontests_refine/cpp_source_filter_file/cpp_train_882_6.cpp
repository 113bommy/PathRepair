#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long mx = 2e5 + 10;
int posx[] = {1, -1, 0, 0};
int posy[] = {0, 0, 1, -1};
long long dp[(1 << 18) + 9][50], arr[50], m, n;
map<pair<long long, long long>, long long> mp;
bool Check(long long n, long long i) { return bool(n & (1ll << i)); }
long long Set(long long n, long long i) { return (n | (1ll << i)); }
long long rec(long long mask, long long par, long long level) {
  if (level == m) return 0;
  if (~dp[mask][par]) return dp[mask][par];
  long long ret = 0;
  for (long long i = 0; i < n; i++) {
    if (!Check(mask, i)) {
      long long x = Set(mask, i);
      ret = max(ret, rec(x, i, level + 1) + arr[i] + mp[{par, i}]);
    }
  }
  return dp[mask][par] = ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1, k, a, b, c, d;
  while (t--) {
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    for (long long i = 0; i < n; i++) cin >> arr[i];
    for (long long i = 0; i < k; i++) {
      cin >> a >> b >> c;
      a--, b--;
      mp[{a, b}] = c;
    }
    cout << rec(0, 0, 0) << endl;
  }
  return 0;
}
