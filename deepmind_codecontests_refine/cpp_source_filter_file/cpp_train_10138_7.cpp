#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const long long N = 5e5 + 5;
long long n, arr[N], vis[N][2], dp[N][2];
long long dfs(long long idx, long long p = 1) {
  if (idx > n || idx <= 0) {
    return 0;
  }
  if (dp[idx][p] != -1) return dp[idx][p];
  if (vis[idx][p]) return 1e10;
  vis[idx][p] = 1;
  long long res = 0;
  if (p & 1) {
    res = arr[idx] + dfs(idx - arr[idx], p ^ 1);
  } else {
    res = arr[idx] + dfs(idx + arr[idx], p ^ 1);
  }
  return dp[idx][p] = res;
}
void solve() {
  cin >> n;
  for (long long i = 2; i <= n; i++) {
    cin >> arr[i];
  }
  memset(vis, 0, sizeof(vis));
  memset(dp, -1, sizeof(dp));
  vis[1][0] = 1;
  for (long long i = 2; i <= n; i++) {
    long long res = i - 1 + dfs(i, 1);
    cout << ((res >= 1e10) ? -1 : res) << "\n";
  }
}
int32_t main() {
  long long t = 1;
  for (long long T = 1; T <= t; T++) {
    solve();
  }
}
