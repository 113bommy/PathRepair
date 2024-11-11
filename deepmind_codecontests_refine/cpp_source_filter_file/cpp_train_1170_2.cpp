#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int cost = 0;
  for (int i = 0; i < n; ++i) {
    vector<char> tiles(m);
    for (int j = 0; j < m; ++j) {
      cin >> tiles[j];
    }
    for (int k = 0; k < m; ++k) {
      if (tiles[k] == '*') continue;
      if (tiles[k] == tiles[k + 1] && k + 1 != m && y < x) {
        cost += y;
        ++k;
      } else {
        cost += x;
      }
    }
  }
  cout << cost << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}
