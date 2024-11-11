#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, m, k = 0;
  cin >> n;
  vector<pair<pair<int, int>, int>> targets(n);
  vector<int> ans(n, -1);
  for (int i = 0; i < n; ++i) {
    cin >> targets[i].first.first >> targets[i].first.second;
    targets[i].second = i;
  }
  sort(targets.begin(), targets.end());
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, lo = 0, hi = n - 1;
    cin >> x >> y;
    while (lo <= hi) {
      int mid = (hi + lo) / 2;
      int c = targets[mid].second;
      if (ans[c] == -1 &&
          y * y <= targets[mid].first.second * targets[mid].first.second -
                       ((targets[mid].first.first - x) *
                        (targets[mid].first.first - x))) {
        ans[c] = i + 1;
        ++k;
        if (mid > 0 &&
            x == targets[mid].first.first - targets[mid].first.second &&
            x == targets[mid - 1].first.first + targets[mid - 1].first.second &&
            ans[targets[mid - 1].second] == -1)
          ans[targets[mid - 1].second] = i + 1, ++k;
        if (mid < n - 1 &&
            x == targets[mid].first.first + targets[mid].first.second &&
            x == targets[mid + 1].first.first - targets[mid + 1].first.second &&
            ans[targets[mid + 1].second] == -1)
          ans[targets[mid + 1].second] = i + 1, ++k;
        break;
      }
      if (x >= targets[mid].first.first + targets[mid].first.second)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
  }
  cout << k << endl;
  for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
  return 0;
}
