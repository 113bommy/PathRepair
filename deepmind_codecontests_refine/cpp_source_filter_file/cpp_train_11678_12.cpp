#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename T, typename U>
static inline void amin(T& x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T& x, U y) {
  if (x < y) x = y;
}
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long solve() {
  long long n;
  cin >> n;
  long long m, k;
  cin >> m >> k;
  long long a[n + 1];
  for (long long j = 1; j < n + 1; j++) cin >> a[j];
  long long dp[n + 1][15];
  bool vis[n + 1][15];
  memset(dp, 0, sizeof(dp));
  memset(vis, 0, sizeof(vis));
  long long ans = 0;
  for (long long i = 0; i < n + 1; i++) vis[i][0] = 1;
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 0; j < m; j++) {
      if (vis[i - 1][j] == 0) continue;
      if (j == 0) {
        dp[i][(j + 1) % m] = a[i] - k + dp[i - 1][0];
      } else {
        dp[i][(j + 1) % m] += a[i] + dp[i - 1][j];
      }
      vis[i][(j + 1) % m] = 1;
    }
    for (long long j = 0; j < m; j++) amax(ans, dp[i][j]);
  }
  cout << ans;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
