#include <bits/stdc++.h>
using namespace std;
const int maxn = 110, maxrate = 60010, inf = 1e9;
void speed() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int n, r, x[maxn], y[maxn], used[maxn], dp[maxn][maxrate];
bool cmp(pair<int, int> p1, pair<int, int> p2) {
  return p1.first + p1.second > p2.first + p2.second;
}
void solve() {
  cin >> n >> r;
  vector<pair<int, int> > pos, neg;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    if (y[i] >= 0)
      pos.push_back({x[i], y[i]});
    else
      neg.push_back({max(x[i], -y[i]), y[i]});
  }
  sort(pos.begin(), pos.end());
  int ans = 0;
  for (int i = 0; i < pos.size(); i++)
    if (r >= pos[i].first) r += pos[i].second, ans++;
  sort(neg.begin(), neg.end(), cmp);
  for (int i = 0; i <= neg.size(); i++)
    for (int j = 0; j < maxrate; j++) dp[i][j] = -inf;
  dp[0][r] = 0;
  int best = 0;
  for (int i = 1; i <= neg.size(); i++) {
    pair<int, int> p = neg[i - 1];
    for (int j = 0; j < maxrate; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - p.second >= p.first && j - p.second < maxrate)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - p.second] + 1);
      best = max(best, dp[i][j]);
    }
  }
  cout << ans + best << '\n';
}
int main() {
  solve();
  return 0;
}
