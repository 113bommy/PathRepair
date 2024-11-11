#include <bits/stdc++.h>
using namespace std;
int gird[105][105];
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int> > a;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t <= 2) {
      int r;
      cin >> r;
      r--;
      a.push_back(make_pair(t, r));
    } else {
      int x, y, v;
      cin >> x >> y >> v;
      x--, y--;
      for (int j = (a.size() - 1); j >= 0; j--) {
        if (a[j].first == 1 && x == a[j].second) {
          y = (y + 1) % n;
        }
        if (a[j].first == 2 && a[j].second == y) {
          x = (x + 1) % n;
        }
      }
      gird[x][y] = v;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << gird[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
