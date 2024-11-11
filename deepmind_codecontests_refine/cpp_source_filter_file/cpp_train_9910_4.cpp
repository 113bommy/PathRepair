#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<pair<int, int>, set<pair<int, int>>> cnt;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    cnt[make_pair(x, y)].emplace(z, i);
  }
  map<int, set<pair<int, int>>> cnt2d;
  for (auto e : cnt) {
    auto key = e.first;
    while (cnt[key].size() > 1) {
      for (int i = 0; i < 2; i++) {
        auto it = cnt[key].begin();
        cout << it->second + 1 << ' ';
        cnt[key].erase(it);
      }
      cout << endl;
    }
    if (!cnt[key].empty())
      cnt2d[key.first].emplace(key.second, cnt[key].begin()->second);
  }
  vector<int> cnt1d;
  for (auto e : cnt2d) {
    int x = e.first;
    while (cnt2d[x].size() > 1) {
      for (int i = 0; i < 2; i++) {
        auto it = cnt2d[x].begin();
        cout << it->second + 1 << ' ';
        cnt2d[x].erase(it);
      }
      cout << endl;
    }
    if (!cnt2d[x].empty()) {
      cnt1d.push_back(cnt2d[x].begin()->second);
    }
  }
  for (int i = 0; i < (int)cnt1d.size(); i += 2) {
    cout << cnt1d[i] << ' ' << cnt1d[i + 1] << endl;
  }
  return 0;
}
