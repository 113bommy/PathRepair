#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int mp[N], len[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 1; i <= 2 * n; i += 2) {
    int x;
    cin >> x;
    v.push_back({x, i});
  }
  sort(v.rbegin(), v.rend());
  int sz = 1;
  int last = 0;
  vector<pair<int, int> > off_a7, ans;
  for (int i = 0; i < v.size(); i++) {
    mp[sz] = v[i].second;
    mp[sz + 1] = v[i].second + 1;
    if (last) ans.push_back({last, sz});
    last = sz;
    len[sz] = v[i].first;
    off_a7.push_back({sz, v[i].first});
    sz += 2;
  }
  int leaf1 = sz - 2, leaf2 = 1;
  for (int i = 0; i < n; i++) {
    int node = off_a7[i].first;
    if (len[node] + i - 1 < v.size()) {
      int tar = off_a7[i + len[node] - 1].first;
      if (tar == leaf1) {
        off_a7.push_back({node + 1, 0});
        leaf1 = node + 1;
      }
      ans.push_back({node + 1, tar});
    } else if (i - len[node] + 1 >= 0) {
      int tar = off_a7[i - len[node] + 1].first;
      if (tar == leaf2) {
        off_a7.push_back({node + 1, 0});
        leaf2 = node + 1;
      }
      ans.push_back({node + 1, tar});
    } else
      return cout << "NO YOU", 0;
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << mp[ans[i].first] << ' ' << mp[ans[i].second] << "\n";
  }
  return 0;
}
