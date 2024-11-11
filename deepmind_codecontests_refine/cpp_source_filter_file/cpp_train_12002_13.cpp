#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)(1e16);
int n, m, k;
long long dp[5000][72][72];
long long solve(vector<int> &a, int idx, int rem, int K) {
  if (idx == n * m) return K == 0 ? 0 : -INF;
  if (~dp[idx][rem][K]) return dp[idx][rem][K];
  long long ans = -INF;
  if ((idx + 1) % m) {
    ans = solve(a, idx + 1, rem, K);
    if (rem > 0)
      ans = max(ans, solve(a, idx + 1, rem - 1, (K + a[idx]) % k) + a[idx]);
  } else {
    ans = solve(a, idx + 1, m / 2, K);
    if (rem > 0)
      ans = max(ans, solve(a, idx + 1, m / 2, (K + a[idx]) % k) + a[idx]);
  }
  return dp[idx][rem][K] = ans;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  vector<int> a(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i * m + j];
  }
  memset(dp, -1, sizeof dp);
  cout << solve(a, 0, m / 2, k) << endl;
  return 0;
}
