#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
int main() {
  int n, m, k, x, r, t;
  cin >> n >> m >> k;
  pair<int, int> row[N], col[N];
  for (int i = 0; i < N; i++) {
    row[i].first = 0;
    row[i].second = 0;
    col[i].first = 0;
    col[i].second = 0;
  }
  for (int i = 1; i < k + 1; i++) {
    cin >> x >> r >> t;
    r--;
    if (x == 1) {
      row[r].first = i;
      row[r].second = t;
    }
    if (x == 2) {
      col[r].first = i;
      col[r].second = t;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (row[i].first >= col[j].first)
        cout << row[i].second;
      else
        cout << col[j].second;
      cout << ' ';
    }
    cout << '\n';
  }
  return 0;
}
