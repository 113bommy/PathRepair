#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 10, mod = 1e9 + 7;
long long dp[N], f[N];
long long t10[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  int m = 6;
  for (int i = 0; i < m; i++) cin >> f[i];
  dp[0] = 0;
  vector<pair<long long, long long>> v;
  for (int i = 0; i < m; i++) {
    if (i)
      t10[i] = 10 * t10[i - 1];
    else
      t10[i] = 1;
    long long x = 3 * (k - 1);
    long long cur = 1;
    while (x) {
      long long tmp = min(cur, x);
      long long w = t10[i] * 3 * tmp;
      if (w > N) break;
      v.push_back({w, f[i] * tmp});
      x -= tmp;
      cur *= 2;
    }
  }
  sort(v.begin(), v.end());
  fill(dp, dp + N, -1e15);
  dp[0] = 0;
  for (auto u : v) {
    for (int i = N - 1; i >= u.first; i--)
      dp[i] = max(dp[i], dp[i - u.first] + u.second);
  }
  for (int i = 0; i < m; i++) {
    for (int j = N - 1; j > -1; j--)
      for (int k = 1; k < 10; k++) {
        int tmp = k * t10[i];
        if (tmp > j) break;
        dp[j] = max(dp[j], dp[j - tmp] + (k % 3 == 0 ? k / 3 * f[i] : 0));
      }
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << dp[x] << '\n';
  }
}
