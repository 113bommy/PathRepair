#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  long long x, k, y;
  cin >> x >> k >> y;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  bool chk[220000] = {0};
  int j = 0;
  for (int i = 0; i < n && j < m; i++) {
    if (a[i] == b[j]) chk[i] = 1, j++;
  }
  if (j != m) {
    cout << -1 << '\n';
    return 0;
  }
  vector<pair<long long, long long>> neighbors;
  vector<vector<int>> range;
  int last = -1;
  vector<int> tmp;
  for (int i = 0; i < n; i++) {
    if (chk[i] == 1) {
      if (tmp.size()) {
        neighbors.push_back({last, a[i]});
        range.push_back(tmp);
        tmp.clear();
      }
      last = a[i];
    } else {
      tmp.push_back(a[i]);
    }
  }
  if (chk[n - 1] == 0) {
    range.push_back(tmp);
    neighbors.push_back({last, -1});
  }
  long long ans = 0;
  if (y * k < x) {
    for (int i = 0; i < range.size(); i++) {
      bool onlyy = 1;
      for (int j : range[i]) {
        if (j >= max(neighbors[i].first, neighbors[i].second)) onlyy = 0;
      }
      if (onlyy)
        ans += range.size() * y;
      else {
        if (range.size() >= k) {
          ans += x + (range.size() - k) * y;
        } else {
          cout << -1 << '\n';
          return 0;
        }
      }
    }
  } else {
    for (int i = 0; i < range.size(); i++) {
      int xcnt = range[i].size() / k;
      if (xcnt == 0) {
        for (int j : range[i]) {
          if (j > max(neighbors[i].first, neighbors[i].second)) {
            cout << -1 << '\n';
            return 0;
          }
        }
      }
      ans += xcnt * x + (range[i].size() - xcnt * k) * y;
    }
  }
  cout << ans << '\n';
  return 0;
}
