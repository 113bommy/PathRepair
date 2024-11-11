#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  for (int j = 0; j < m; ++j) {
    int k, pos;
    cin >> k >> pos;
    set<pair<int, int>> k_largest;
    for (int i = 0; i < n; ++i) {
      if (i < k) {
        k_largest.emplace(a[i], -i);
      } else {
        if (a[i] > k_largest.begin()->first) {
          k_largest.emplace(a[i], -i);
          k_largest.erase(k_largest.begin());
        }
      }
    }
    vector<pair<int, int>> k_by_ind;
    for (auto p : k_largest) k_by_ind.emplace_back(-p.second, p.first);
    sort(begin(k_by_ind), end(k_by_ind));
    cout << k_by_ind[pos - 1].second << "\n";
  }
  return 0;
}
