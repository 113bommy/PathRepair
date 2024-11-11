#include <bits/stdc++.h>
using namespace std;
inline bool ascending(int i, int j) { return (i < j); }
inline bool descending(int i, int j) { return (i > j); }
const int MN = 5000 + 10;
pair<int, int> row[MN], col[MN];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int type, t, color;
    cin >> type >> t >> color;
    t--;
    if (type == 1) {
      row[t].first = i + 1;
      row[t].second = color;
    } else {
      col[t].first = i + 1;
      col[t].second = color;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (row[i].first >= col[j].first)
        cout << row[i].second << ' ';
      else
        cout << col[j].second << ' ';
    }
    cout << endl;
  }
  return 0;
}
