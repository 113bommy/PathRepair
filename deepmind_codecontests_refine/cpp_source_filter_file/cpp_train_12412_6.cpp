#include <bits/stdc++.h>
using namespace std;
const long long N = 46700;
long long dp[N][3];
long long first = 0;
long long second = 0;
long long mex(long long a, long long b = 1000, long long c = 1500) {
  for (long long i = 0; i < 4; i++)
    if (i != a && i != b && i != c) return i;
  assert(1 == 0);
  return 1;
}
long long get(long long id) {
  long long res = 0;
  for (long long i = 0; i < 5; i++)
    for (long long j = 0; j < 3; j++) {
      res += dp[i + id][j];
      res++;
      res *= 10;
    }
  return res;
}
void prep(long long x, long long y, long long z) {
  for (long long i = 0; i < 3; i++) dp[0][i] = 0;
  map<long long, long long> mp;
  for (long long i = 1; i < N; i++) {
    long long a = 0, b = 0, c = 0;
    if (i - x <= 0)
      a = 0;
    else
      a = dp[i - x][0];
    if (i - y <= 0)
      b = 0;
    else
      b = dp[i - y][1];
    if (i - z <= 0)
      c = 0;
    else
      c = dp[i - z][2];
    dp[i][0] = mex(a, b, c);
    dp[i][1] = mex(a, c);
    dp[i][2] = mex(a, b);
    if (i >= 5) {
      long long val = get(i - 5);
      if (mp.find(val) != mp.end()) {
        first = mp[val];
        second = i - 5;
        return;
      }
      mp[val] = i - 5;
    }
  }
}
long long grundy(long long val, long long typ) {
  if (val <= 0) return 0;
  if (val < first) return dp[val][typ];
  long long id = val;
  id = ((id - first) % (second - first + 1)) + first;
  return dp[id][typ];
}
void solve() {
  long long n, x, y, z;
  cin >> n >> x >> y >> z;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  prep(x, y, z);
  long long xr = 0;
  for (long long i = 0; i < n; i++) xr ^= grundy(a[i], 0);
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    long long old = grundy(a[i], 0);
    long long ne = grundy(a[i] - x, 0);
    if ((xr ^ old ^ ne) == 0) res++;
    ne = grundy(a[i] - y, 1);
    if ((xr ^ old ^ ne) == 0) res++;
    ne = grundy(a[i] - z, 2);
    if ((xr ^ old ^ ne) == 0) res++;
  }
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
