#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (2 * k < n - 1) {
    cout << -1 << '\n';
  } else {
    vector<pair<int, int> > edges;
    for (int i = 0; i < n; i++) {
      int cont = 0;
      for (int j = (i + 1) % n; cont < k; j = (j + 1) % n) {
        edges.push_back(pair<int, int>(i, j));
        cont++;
      }
    }
    cout << edges.size() << '\n';
    for (auto x : edges) {
      cout << x.first + 1 << " " << x.second + 1 << '\n';
    }
  }
  return 0;
}
