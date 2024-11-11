#include <bits/stdc++.h>
#pragma GCC optimize("avx2, O3")
using namespace std;
signed main() {
  int n;
  cin >> n;
  vector<pair<char, int>> kk(n * 2);
  for (auto& it : kk) {
    cin >> it.first;
    if (it.first == '-') {
      cin >> it.second;
    }
  }
  vector<int> ans(n);
  set<pair<int, int>> gay;
  int c = n - 1;
  for (int i = n * 2 - 1; i >= 0; --i) {
    if (kk[i].first == '+') {
      if (gay.empty()) {
        cout << "NO";
        return 0;
      }
      ans[c--] = gay.begin()->first;
      gay.erase(gay.begin());
    } else {
      if (!gay.empty() && gay.begin()->first < kk[i].first) {
        cout << "NO\n";
        return 0;
      }
      gay.insert({kk[i].second, i});
    }
  }
  if (!gay.empty()) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (auto& it : ans) cout << it << " ";
  return 0;
}
