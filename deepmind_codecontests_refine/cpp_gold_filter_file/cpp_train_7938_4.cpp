#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  vector<pair<int, int>> ans;
  for (int i = sx; i >= 1; i--) {
    ans.push_back({i, sy});
  }
  for (int i = sx + 1; i <= n; ++i) {
    ans.push_back({i, sy});
  }
  bool last = true;
  for (int j = sy + 1; j <= m; ++j) {
    if (!last) {
      for (int i = 1; i <= n; ++i) {
        ans.push_back({i, j});
      }
    } else {
      for (int i = n; i >= 1; i--) {
        ans.push_back({i, j});
      }
    }
    last = !last;
  }
  for (int j = sy - 1; j >= 1; j--) {
    if (!last) {
      for (int i = 1; i <= n; ++i) {
        ans.push_back({i, j});
      }
    } else {
      for (int i = n; i >= 1; i--) {
        ans.push_back({i, j});
      }
    }
    last = !last;
  }
  for (const auto item : ans) {
    cout << item.first << ' ' << item.second << endl;
  }
  return 0;
}
