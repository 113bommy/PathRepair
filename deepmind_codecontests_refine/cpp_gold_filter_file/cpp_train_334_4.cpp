#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int n, x, y;
int ans[200005];
vector<pair<int, int>> l[200005];
set<pair<int, int>> s;
pair<int, int> v[200005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    l[x].push_back({y, i});
    v[i] = {x, y};
  }
  for (int i = 1; i <= n; i++) {
    for (auto &j : l[i]) s.insert(j);
    ans[s.begin()->second] = i;
    s.erase(s.begin());
  }
  bool ok = 0;
  for (int i = 1; i <= n; i++) {
    for (auto &j : l[i]) s.insert(j);
    if (s.size() > 1) {
      auto it = s.begin();
      it++;
      if (ans[it->second] <= s.begin()->first) {
        cout << "NO\n";
        for (int j = 1; j <= n; j++) cout << ans[j] << " ";
        cout << "\n";
        swap(ans[s.begin()->second], ans[it->second]);
        for (int j = 1; j <= n; j++) cout << ans[j] << " ";
        ok = 1;
        break;
      }
    }
    s.erase(s.begin());
  }
  if (!ok) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  }
  return 0;
}
