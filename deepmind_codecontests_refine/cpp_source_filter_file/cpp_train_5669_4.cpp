#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
bool ispoweroftwo(long long n) { return n & (!(n & (n - 1))); }
long long mod = 1000000007;
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, -1, 0, 1};
bool test = 0;
const long long inf = 1e18;
const long long N = 2e5 + 5;
long long n;
long long cache[5005][5005];
long long a[5005];
long long dp(long long l, long long r, long long p) {
  if (l > r) return 0;
  if (l == r) return 1;
  long long &ans = cache[l][r];
  if (ans != -1) return ans;
  ans = (r - l + 1);
  long long mnx = 1e9;
  for (long long i = l; i <= r; ++i) mnx = min(mnx, a[i] - p);
  if (mnx == 0) return ans = 0;
  long long prev = l, ans1 = 0;
  for (long long i = l; i <= r; ++i) {
    if (a[i] == mnx + p) {
      ans1 += dp(prev + 1, i - 1, p + mnx);
      prev = i;
    }
  }
  if (prev != r) ans1 += dp(prev + 1, r, p + mnx);
  ans1 += mnx;
  ans = min(ans, ans1);
  return ans;
}
void solve(long long tc = 0) {
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  memset(cache, -1, sizeof(cache));
  cout << dp(1, n, 0);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  if (test) cin >> t;
  for (long long i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}
