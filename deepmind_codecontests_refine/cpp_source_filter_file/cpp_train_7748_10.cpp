#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int n, k;
long long dp[2000][2000];
long long solve(int idx, int last) {
  if (idx > k) return 0;
  if (idx == k) {
    return 1;
  }
  if (dp[idx][last] != -1) {
    return dp[idx][last];
  }
  long ans = solve(idx + 1, last);
  for (int i = 2; i * last <= n; i++) {
    ans += solve(idx + 1, last * i) % mod;
  }
  dp[idx][last] = ans % mod;
  return ans % mod;
}
int main() {
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 1) << endl;
  ;
  return 0;
}
