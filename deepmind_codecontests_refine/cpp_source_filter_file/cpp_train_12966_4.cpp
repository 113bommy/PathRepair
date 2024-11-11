#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  map<long long, long long> row, col;
  row.clear();
  col.clear();
  long long aRow = 0, aCol = 0, res = n * n;
  while (k--) {
    long long x, y;
    cin >> x >> y;
    if (!row[x] && !col[y]) {
      row[x] = 1;
      col[y] = 1;
      res -= (2 * n - 1 - aRow - aCol);
      aRow++;
      aCol++;
      cout << res;
    } else if (row[x] && col[y]) {
      cout << res;
    } else if (row[x]) {
      res -= (n - aCol);
      col[y] = 1;
      aCol++;
      cout << res;
    } else if (col[y]) {
      res -= (n - aRow);
      row[x] = 1;
      aRow++;
      cout << res;
    }
    if (k)
      cout << " ";
    else
      cout << endl;
  }
  return 0;
}
