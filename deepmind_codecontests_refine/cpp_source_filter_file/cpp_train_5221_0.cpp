#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, block[1550];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> block[i];
  }
  map<int, vector<pair<int, int>>> m;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = i; j <= n; j++) {
      sum += block[j];
      m[sum].push_back({i, j});
    }
  }
  vector<pair<int, int>> ans;
  for (auto i : m) {
    vector<pair<int, int>> pp = i.second;
    int r = -1;
    vector<pair<int, int>> now;
    for (auto j : pp) {
      if (r < j.first) {
        now.push_back({j.first, j.second});
        r = j.second;
      }
    }
    if (now.size() > ans.size()) {
      ans = now;
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
