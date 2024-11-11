#include <bits/stdc++.h>
using namespace std;
int n;
int x, y;
map<int, vector<pair<int, int> > > line;
int l = 0, pre = 0;
long long dist(pair<int, int> x, pair<int, int> y) {
  return abs(x.first - y.first) + abs(x.second - y.second);
}
bool comp(pair<int, int> x, pair<int, int> y) {
  if (x.first == y.first)
    return x.second > y.second;
  else
    return x.first < y.first;
}
void handle_input() {
  cin >> n;
  for (__typeof(0) i = (0); i < (n); ++i) {
    cin >> x >> y;
    line[max(x, y)].push_back(make_pair(x, y));
  }
  line[0].push_back(make_pair(0, 0));
  for (auto i = line.begin(); i != line.end(); ++i)
    sort(i->second.begin(), i->second.end(), comp);
}
void solve() {
  handle_input();
  vector<vector<long long> > dp(line.size() + 1, vector<long long>(2, 1e18));
  dp[0][0] = dp[0][1] = 0;
  for (auto &it : line) {
    ++l;
    pair<int, int> first = it.second[0], second = it.second.back();
    pair<int, int> pre_first = line[pre][0], pre_second = line[pre].back();
    dp[l][0] = min(
        dp[l][0], dp[l - 1][0] + dist(pre_first, second) + dist(first, second));
    dp[l][0] = min(dp[l][0], dp[l - 1][1] + dist(pre_second, second) +
                                 dist(first, second));
    dp[l][1] = min(dp[l][1],
                   dp[l - 1][0] + dist(pre_first, first) + dist(first, second));
    dp[l][1] = min(
        dp[l][1], dp[l - 1][1] + dist(pre_second, first) + dist(first, second));
    pre = it.first;
  }
  cout << min(dp[l][0], dp[l][1]) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
