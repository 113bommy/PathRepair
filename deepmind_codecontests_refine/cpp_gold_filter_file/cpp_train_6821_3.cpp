#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> last_row_coloring(n), last_col_coloring(m);
  for (int i = 1; i <= k; i++) {
    int a;
    cin >> a;
    if (a == 1) {
      int r, col;
      cin >> r >> col;
      r--;
      last_row_coloring[r] = make_pair(i, col);
    } else {
      int c, col;
      cin >> c >> col;
      c--;
      last_col_coloring[c] = make_pair(i, col);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (last_row_coloring[i].first < last_col_coloring[j].first) {
        cout << last_col_coloring[j].second;
      } else
        cout << last_row_coloring[i].second;
      cout << " ";
    }
    cout << endl;
  }
}
