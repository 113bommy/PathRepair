#include <bits/stdc++.h>
using namespace std;
const int MAX = int(5e3);
const int MOD = int(1e9 + 7);
const int oo = INT_MAX;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, d, h;
  while (cin >> n >> d >> h) {
    if (2 * h < d) {
      cout << -1 << "\n";
      continue;
    }
    vector<pair<int, int> > edges;
    for (int i = 2; i <= h + 1; i++) {
      if (i > n) continue;
      edges.push_back({i - 1, i});
    }
    for (int i = h + 2; i <= d + 1; i++) {
      if (i > n) continue;
      if (i == h + 2)
        edges.push_back({1, i});
      else
        edges.push_back({i - 1, i});
    }
    int id = d + 2, node = -1;
    if (h < d)
      node = 1;
    else if (h == d && h != 1)
      node = 2;
    if (node != -1) {
      while (id <= n) {
        edges.push_back({1, id});
        id++;
      }
    }
    if (int(edges.size()) == n - 1)
      for (auto& e : edges) cout << e.first << " " << e.second << "\n";
    else
      cout << -1 << "\n";
  }
  return 0;
}
