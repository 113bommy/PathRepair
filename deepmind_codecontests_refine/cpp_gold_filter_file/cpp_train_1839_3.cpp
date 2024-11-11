#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Edge {
  int x, y, wt;
};
int n, m;
Edge a[N];
set<pair<int, int>> b[N];
int solve() {
  for (int i = 1; i <= m; i++) {
    auto [x, y, wt] = a[i];
    auto it = b[x].lower_bound({wt, -1});
    int len;
    if (it == b[x].begin()) {
      len = 1;
    } else {
      it--;
      assert(it->first < wt);
      len = it->second + 1;
    }
    it = b[y].lower_bound({wt, len});
    if (it == b[y].begin())
      it = b[y].insert({wt, len}).first;
    else {
      it--;
      if (it->first < wt && it->second < len) {
        it = b[y].insert({wt, len}).first;
      } else
        continue;
    }
    it++;
    while (it != b[y].end() && !(it->first > wt && it->second > len)) {
      it = b[y].erase(it);
    }
  }
  int ans = 1;
  for (int i = 1; i <= n; i++)
    for (auto [_, len] : b[i]) ans = max(ans, len);
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].x >> a[i].y >> a[i].wt;
  }
  cout << solve();
}
