#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> d(n);
  for (auto &i : d) cin >> i.first, i.second = &i - &d[0] + 1;
  sort(d.begin(), d.end());
  vector<pair<int, int>> e;
  vector<int> a;
  a.push_back(2 * d.back().second - 1);
  for (int i = 1; i < d.back().first; ++i) a.push_back(-1);
  a.push_back(2 * d.back().second);
  int l = 0, r = a.size() - 1;
  d.pop_back();
  while (!d.empty()) {
    auto p = d.back();
    d.pop_back();
    if (a[l + 1] == -1) {
      ++l;
      a[l] = 2 * p.second - 1;
      if (p.first == r - l + 1) {
        ++r;
        a.push_back(2 * p.second);
      } else {
        e.push_back({l + p.first - 1, 2 * p.second});
      }
    } else {
      ++r;
      a.push_back(2 * p.second);
      e.push_back({r - p.first + 1, 2 * p.second - 1});
    }
  }
  for (size_t i = 1; i < a.size(); ++i) cout << a[i - 1] << " " << a[i] << "\n";
  for (auto &i : e) cout << a[i.first] << " " << i.second << "\n";
  return 0;
}
