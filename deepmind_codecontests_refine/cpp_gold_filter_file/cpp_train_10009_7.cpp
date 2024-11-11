#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, a[N][N];
vector<int> rows[N], cols[N];
int findOrderInRow(int row, int x) {
  vector<int>::iterator it;
  it = lower_bound(rows[row].begin(), rows[row].end(), x);
  return (it - rows[row].begin()) + 1;
}
int findOrderInCol(int col, int x) {
  vector<int>::iterator it;
  it = lower_bound(cols[col].begin(), cols[col].end(), x);
  return (it - cols[col].begin()) + 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++) {
    map<int, bool> r;
    for (int j = 1; j <= m; j++) {
      if (r.find(a[i][j]) == r.end())
        rows[i].push_back(a[i][j]), r[a[i][j]] = true;
    }
  }
  for (int j = 1; j <= m; j++) {
    map<int, bool> c;
    for (int i = 1; i <= n; i++) {
      if (c.find(a[i][j]) == c.end())
        cols[j].push_back(a[i][j]), c[a[i][j]] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(rows[i].begin(), rows[i].end());
  }
  for (int i = 1; i <= m; i++) {
    sort(cols[i].begin(), cols[i].end());
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int orderInRow = findOrderInRow(i, a[i][j]);
      int orderInCol = findOrderInCol(j, a[i][j]);
      if (orderInRow > orderInCol) {
        cout << max(rows[i].size(), cols[j].size() + orderInRow - orderInCol)
             << " ";
      } else {
        cout << max(cols[j].size(), rows[i].size() + orderInCol - orderInRow)
             << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
