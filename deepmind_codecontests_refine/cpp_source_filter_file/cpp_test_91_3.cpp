#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
const int mod = 998244353;
int dp[2][N];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), v[2];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    int k = i & 1;
    v[k].push_back(a[i]);
    dp[k][a[i]] = 1;
    int last = a[i];
    for (auto x : v[k ^ 1]) {
      int y = dp[k ^ 1][x];
      int split = (a[i] + x - 1) / x;
      int st = a[i] / split;
      ans += 1LL * (split - 1) * y * i;
      ans %= mod;
      dp[k][st] += y;
      if (last != st) {
        v[k].push_back(st), last = st;
      }
    }
    for (auto x : v[k ^ 1]) dp[k ^ 1][x] = 0;
    v[k ^ 1].clear();
  }
  cout << ans << endl;
  for (auto x : v[0]) dp[0][x] = 0;
  for (auto x : v[1]) dp[1][x] = 0;
}
int main() {
  ios::sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
}
