#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int w, b;
    cin >> b >> w;
    if (max(w, b) > 3 * min(w, b) + 1) {
      cout << "NO\n";
      continue;
    }
    long long int x = 3, y = 3;
    if (b < w) {
      x = 3;
      y = 4;
      swap(w, b);
    }
    vector<pair<long long int, long long int>> ans;
    for (long long int i = 0; i < w; ++i, x += 2) ans.push_back({x, y});
    for (long long int i = 1; i < w && b > 0; ++i) {
      ans.push_back({ans[i].first - 1, ans[i].second});
      --b;
    }
    if (b > 0) {
      ans.push_back({ans[0].first - 1, ans[0].second});
      --b;
    }
    for (long long int i = 0; i < w && b > 0; ++i) {
      if (b >= 2) {
        ans.push_back({ans[i].first, ans[i].second - 1});
        --b;
        ans.push_back({ans[i].first, ans[i].second + 1});
        --b;
      } else {
        ans.push_back({ans[i].first, ans[i].second - 1});
        --b;
      }
    }
    if (b > 0) {
      ans.push_back({ans[w - 1].first + 1, ans[w - 1].second});
      --b;
    }
    cout << "YES\n";
    for (auto i : ans) cout << i.first << " " << i.second << "\n";
    cout << "\n";
  }
  return 0;
}
