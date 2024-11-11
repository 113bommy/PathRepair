#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
const int N = 2005;
long long n;
vector<long long> v(N);
long long dp[N][N];
unordered_map<long long, long long> m;
long long rec(long long l, long long r) {
  if (l > r) return 0;
  if (dp[l][r] != -1) return dp[l][r];
  long long &ans = dp[l][r];
  ans = 0;
  if (m[v[l]] == 0) {
    m[v[l]] = 1;
    ans = max(ans, 1 + rec(l + 1, r));
    m[v[l]] = 0;
  }
  if (m[v[r]] == 0) {
    m[v[r]] = 1;
    ans = max(ans, 1 + rec(l, r - 1));
    m[v[l]] = 0;
  }
  return ans;
}
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> v[i];
  memset(dp, -1, sizeof(dp));
  cout << n - rec(1, n);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
