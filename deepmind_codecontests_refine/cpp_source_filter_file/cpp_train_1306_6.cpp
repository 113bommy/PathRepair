#include <bits/stdc++.h>
using namespace std;
int main() {
  char t;
  int n, m, sum = 0;
  cin >> n >> m;
  bool check[n][m];
  int row[n], col[m];
  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t;
      if (t == '*') {
        check[i][j] = true;
        sum++;
        row[i]++;
        col[j]++;
      } else
        check[i][j] = false;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((check[i][j] && row[i] + col[j] == sum) ||
          (!check[i][j] && row[i] + col[j] == sum + 1)) {
        cout << "YES" << endl;
        cout << i + 1 << " " << j + 1;
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
