#include <bits/stdc++.h>
using namespace std;
array<int, 301> ds;
array<pair<int, int>, 301> dds;
int main() {
  int n;
  cin >> n;
  for (auto i = 1; i <= n; ++i) {
    scanf("%d", &ds[i]);
  }
  for (auto i = 0; i < n / 2; ++i) {
    dds[i + 1].first = ds[n - i] - ds[n - i - 1];
    dds[i + 1].second = ds[i + 1] - ds[i];
  }
  if (n % 2)
    dds[n / 2 + 1].second = ds[n / 2 + 1] - ds[n / 2] + 1;
  else
    dds[n / 2 + 1].second = 1;
  vector<pair<int, int>> edges;
  int c_k = 0;
  for (auto i = n / 2 + 1; i >= 1; --i) {
    c_k += dds[i].first;
    auto to_add_connected = dds[i].second;
    for (auto j = c_k; j < to_add_connected + c_k; ++j) {
      for (auto k = 0; k < to_add_connected + c_k; ++k) {
        if (k == j) {
          continue;
        } else {
          if (k < j) {
            edges.push_back({k, j});
          }
        }
      }
    }
    c_k += dds[i].second;
  }
  cout << edges.size() << '\n';
  for (auto v : edges) {
    cout << v.first << " " << v.second << "\n";
  }
  cout << '\n';
  return 0;
}
