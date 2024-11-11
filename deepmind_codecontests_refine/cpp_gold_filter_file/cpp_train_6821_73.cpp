#include <bits/stdc++.h>
using namespace std;
constexpr int mxn = 5050;
pair<int, int> row[mxn], col[mxn];
int32_t main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  fill_n(row, mxn, make_pair(0, -1));
  fill_n(col, mxn, make_pair(0, -1));
  int azyr = 0;
  for (int i = 0; i < k; ++i, ++azyr) {
    int x;
    cin >> x;
    if (x == 1) {
      int r, c;
      cin >> r >> c;
      row[r] = {c, azyr};
    } else {
      int c, c1;
      cin >> c >> c1;
      col[c] = {c1, azyr};
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (j > 1) {
        cout << ' ';
      }
      if (col[j].second > row[i].second) {
        cout << col[j].first;
      } else {
        cout << row[i].first;
      }
    }
    cout << endl;
  }
  return 0;
}
