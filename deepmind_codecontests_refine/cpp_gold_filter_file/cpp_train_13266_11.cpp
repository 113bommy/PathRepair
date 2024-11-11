#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128000000")
using namespace std;
void solve();
clock_t start;
int main() {
  int t = 1;
  cout.precision(10);
  cout << fixed;
  start = clock();
  while (t--) {
    solve();
  }
  return 0;
}
struct man {
  long long x, k;
  long long mask;
  man() {}
  void scan() {
    cin >> x >> k;
    mask = 0;
    long long num;
    cin >> num;
    for (long long i = 0; i < num; ++i) {
      long long cur;
      cin >> cur;
      --cur;
      mask |= (1 << cur);
    }
  }
  bool operator<(const man& other) const { return k < other.k; }
};
long long n, m, b;
man friends[200];
long long dp[2][1 << 22];
void solve() {
  cin >> n >> m >> b;
  for (long long i = 0; i < n; ++i) friends[i].scan();
  sort(friends, friends + n);
  for (long long i = 0; i < (1 << m); ++i) dp[0][i] = dp[1][i] = 4e18;
  long long ans = 4e18;
  long long w = 0;
  dp[w][0] = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long i = 0; i < (1 << m); ++i) dp[w ^ 1][i] = dp[w][i];
    for (long long mask = 0; mask < (1 << m); ++mask) {
      long long newMask = mask | friends[i].mask;
      dp[w ^ 1][newMask] = min(dp[w ^ 1][newMask], dp[w][mask] + friends[i].x);
      if (newMask + 1 == (1 << m))
        ans = min(ans, dp[w ^ 1][newMask] + b * friends[i].k);
    }
    w ^= 1;
  }
  if (ans + 1 < 4e18)
    cout << ans;
  else
    cout << -1;
}
