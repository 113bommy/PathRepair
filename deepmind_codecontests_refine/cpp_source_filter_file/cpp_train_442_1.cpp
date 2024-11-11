#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
void go() {
  int n;
  cin >> n;
  int v[n + 5];
  set<int> row;
  set<pair<int, int>> two, three;
  for (int i = 1; i < n + 1; i++) {
    row.insert(i);
  }
  for (int i = 1; i < n + 1; i++) {
    cin >> v[i];
  }
  vector<pair<int, int>> ans;
  for (int i = n; i >= 1; i--) {
    if (v[i] == 0) {
      continue;
    }
    if (v[i] == 1) {
      if (!row.size()) {
        cout << -1 << '\n';
        return;
      }
      int x = *row.begin();
      row.erase(row.begin());
      ans.push_back({i, x});
      two.insert({i, x});
      three.insert({i, x});
    } else if (v[i] == 2) {
      if (!two.size()) {
        cout << -1 << '\n';
        return;
      }
      if (two.size()) {
        auto x = *two.begin();
        two.erase(x);
        three.erase(x);
        ans.push_back({i, x.second});
        three.insert({i, x.second});
      }
    } else if (v[i] == 3) {
      if (!three.size() || !row.size()) {
        cout << -1 << '\n';
        return;
      }
      auto y = *three.begin();
      int x = *row.begin();
      row.erase(x);
      three.erase(y);
      two.erase(y);
      ans.push_back({i, x});
      ans.push_back({y.first, x});
      three.insert({i, x});
    }
  }
  cout << ans.size() << '\n';
  for (auto &i : ans) {
    cout << i.second << ' ' << i.first << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c = 0;
  int t;
  if (!c) {
    t = 1;
  } else {
    cin >> t;
  }
  while (t--) {
    go();
  }
}
