#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long dp[200001];
long long hh(long long x) { return (x * (x + 1)) / 2; }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long r, g, h;
  cin >> r >> g;
  if (r > g) swap(r, g);
  dp[0] = 1;
  for (long long i = 0;; i++) {
    if (hh(i) <= r + g && hh(i + 1) > r + g) {
      h = i;
      break;
    }
  }
  for (long long i = 1; i <= h; i++) {
    for (long long j = r; j >= i; j--) {
      dp[j] += dp[j - i];
      dp[j] %= mod;
    }
  }
  long long ans = 0;
  long long hx = hh(h);
  for (long long i = 1; i <= h; i++) {
    if ((g + i) >= hx) {
      ans += dp[i];
      ans %= mod;
    }
  }
  cout << ans;
  return 0;
}
