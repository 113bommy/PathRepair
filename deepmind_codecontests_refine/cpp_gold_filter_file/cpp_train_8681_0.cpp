#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '.') {
        ans.push_back({i, j});
        break;
      }
    }
  }
  if ((int)ans.size() == n) {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
    return;
  }
  ans.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[j][i] == '.') {
        ans.push_back({j, i});
        break;
      }
    }
  }
  if ((int)ans.size() == n) {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
    return;
  }
  cout << -1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
