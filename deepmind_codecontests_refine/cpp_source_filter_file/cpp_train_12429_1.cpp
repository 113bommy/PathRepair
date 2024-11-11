#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, double>, pair<int, int> > > targets;
bool can_move(int i, int j) {
  pair<int, int> p1 = targets[i].second, p2 = targets[j].second;
  int t = targets[j].first.first - targets[i].first.first;
  return t > 0 && (p1.first - p2.first) * (p1.first - p2.first) +
                          (p1.second - p2.second) * (p1.second - p2.second) <=
                      t * t;
}
int main() {
  cout << fixed;
  cout.precision(14);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, t;
    double p;
    cin >> x >> y >> t >> p;
    targets.push_back(make_pair(make_pair(t, p), make_pair(x, y)));
  }
  sort(targets.begin(), targets.end());
  double dp[n];
  for (int i = 0; i < n; i++) dp[i] = targets[i].first.second;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < n; j++)
      if (can_move(i, j)) {
        dp[i] = max(dp[i], targets[i].first.second + dp[j]);
      }
  }
  double res = 0;
  for (int i = 0; i < n; i++) res = max(res, dp[i]);
  cout << res << endl;
  return 0;
}
