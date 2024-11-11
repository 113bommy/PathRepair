#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int no, row[n], col[m], a, b;
  int trow[n], tcol[m];
  memset(row, -1, sizeof(row));
  memset(col, -1, sizeof(col));
  memset(trow, -1, sizeof(trow));
  memset(tcol, -1, sizeof(tcol));
  for (int i = 0; i < k; i++) {
    cin >> no >> a >> b;
    if (no == 1) {
      row[a - 1] = b;
      trow[a - 1] = i;
    } else {
      col[a - 1] = b;
      tcol[a - 1] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (trow[i] == -1 && tcol[j] == -1)
        cout << 0;
      else if (trow[i] == -1)
        cout << col[j];
      else if (tcol[j] == -1)
        cout << row[i];
      else {
        if (trow[i] > tcol[j])
          cout << row[i];
        else
          cout << col[j];
      }
      if (j != m - 1) cout << " ";
    }
    cout << endl;
  }
}
