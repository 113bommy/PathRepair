#include <bits/stdc++.h>
long long quickpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 1000000007;
    b >>= 1, a = a * a % 1000000007;
  }
  return ans;
}
using namespace std;
const long long N = 1e6 + 100;
const long long maxn = 2e3 + 9;
long long dp[maxn][maxn];
long long a[maxn];
long long n, h, l, r;
long long dfs(long long pos, long long sum = 0) {
  if (pos > n) return 0;
  long long ret = dp[pos][sum];
  if (ret != -1) return dp[pos][sum];
  long long c = (sum + a[pos] - 1) % h;
  long long d = (sum + a[pos]) % h;
  long long a = dfs(pos + 1, c) + (c >= l && c <= r);
  long long b = dfs(pos + 1, d) + (d >= l && d <= r);
  return dp[pos][sum] = max(a, b);
}
void solve() {
  cin >> n >> h >> l >> r;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= h - 1; j++) {
      dp[i][j] = -1;
    }
  }
  cout << dfs(0) << endl;
}
signed main() { solve(); }
