#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> edges;
    int u = 1, v = 2;
    for (int i = 0; i < 2 * n + p; i++) {
      edges.emplace_back(u, v);
      v++;
      if (v == 7) {
        u++;
        v = u + 1;
      }
    }
    for (auto p : edges) {
      cout << p.first << " " << p.second << "\n";
    }
  }
  return 0;
}
