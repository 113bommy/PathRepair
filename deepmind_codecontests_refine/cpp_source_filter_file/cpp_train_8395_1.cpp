#include <bits/stdc++.h>
using namespace std;
const int N = 1e2;
int n, m;
char c[N][N];
vector<int> row, column;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> c[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '#') {
        while (row.size()) row.pop_back();
        while (column.size()) column.pop_back();
        for (int k = 0; k < m; k++) {
          if (c[k][j] == '#') row.push_back(k);
        }
        for (int k = 0; k < n; k++) {
          if (c[i][k] == '#') column.push_back(k);
        }
        for (int r = 0; r < row.size(); r++) {
          for (int k = 0; k < column.size(); k++) {
            int y = column[k], x = row[r];
            if (c[x][y] != '#') {
              cout << "No" << endl;
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
