#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> &a, pair<long long, long long> &b) {
  return a.first + a.second > b.first + b.second;
}
void solve() {
  long long n, r;
  cin >> n >> r;
  vector<pair<long long, long long>> pos;
  vector<pair<long long, long long>> neg;
  while (n--) {
    long long a, b;
    cin >> a >> b;
    if (b > 0) {
      pos.push_back({a, b});
    } else {
      neg.push_back(make_pair(a, b));
    }
  }
  sort(pos.begin(), pos.end());
  long long cnt = 0;
  for (auto c : pos) {
    if (r >= c.first) {
      r += c.second;
      cnt++;
    } else {
      break;
    }
  }
  sort(neg.begin(), neg.end(), cmp);
  n = neg.size();
  long long dp[n + 1][r + 1];
  for (auto &c : dp)
    for (auto &d : c) d = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j <= r; j++) {
      dp[i][j] =
          max(dp[i - 1][j], ((j - neg[i - 1].second >= neg[i - 1].first &&
                              j - neg[i - 1].second <= r)
                                 ? (dp[i - 1][j - neg[i - 1].second] + 1)
                                 : 0));
    }
  }
  long long val = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j <= r; j++) {
      val = max(val, dp[i][j]);
    }
  }
  cout << val + cnt << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
