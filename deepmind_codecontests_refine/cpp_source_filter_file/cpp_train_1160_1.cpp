#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int idx = 0;
  vector<int> v(n);
  cin >> v[0];
  int tmp = v[0];
  vector<vector<pair<int, int> > > kek(n + 1);
  for (int i = 1; i < n; i++) {
    cin >> v[i];
    if (v[i] != tmp) {
      kek[tmp].push_back({idx, i - 1});
      idx = i;
      tmp = v[i];
    }
  }
  kek[tmp].push_back({idx, n - 1});
  vector<ll> dp(n + 1);
  dp[n] = kek[n].size();
  int ans = dp[n];
  for (int i = n - 1; i > 0; i--) {
    dp[i] = dp[i + 1];
    for (auto x : kek[i]) {
      if (x.first != 0 && x.second != n - 1) {
        if (v[x.first - 1] < i && v[x.second + 1] < i) {
          dp[i] += n - i + 1;
        } else if (v[x.first - 1] < i) {
          dp[i] += v[x.second + 1] - i;
        } else if (v[x.second + 1] < i) {
          dp[i] += v[x.first - 1] - i;
        } else {
          dp[i] += v[x.second + 1] + v[x.first - 1] - n - i - 1;
        }
      } else if (x.first == 0 && x.second != n - 1) {
        if (v[x.second + 1] < i) {
          dp[i] += n - i + 1;
        } else {
          dp[i] += v[x.second + 1] - i;
        }
      } else if (x.first != 0 && x.second == n - 1) {
        if (v[x.first - 1] < i) {
          dp[i] += n - i + 1;
        } else {
          dp[i] += v[x.first - 1] - i;
        }
      } else {
        dp[i] = n - i + 1;
      }
    }
    ans += dp[i];
  }
  cout << ans;
  return 0;
};
