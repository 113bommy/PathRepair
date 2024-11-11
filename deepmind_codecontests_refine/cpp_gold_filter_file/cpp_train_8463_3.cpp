#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, rowS, rowE, colS, colE, f;
  string a[100];
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0, f = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i][j] == '*') {
        rowS = i;
        f = 1;
        break;
      }
    }
    if (f) break;
  }
  for (i = n - 1, f = 0; i >= 0; i--) {
    for (j = 0; j < m; j++) {
      if (a[i][j] == '*') {
        rowE = i;
        f = 1;
        break;
      }
    }
    if (f) break;
  }
  for (i = 0, f = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (a[j][i] == '*') {
        colS = i;
        f = 1;
        break;
      }
    }
    if (f) break;
  }
  for (i = m - 1, f = 0; i >= 0; i--) {
    for (j = 0; j < n; j++) {
      if (a[j][i] == '*') {
        colE = i;
        f = 1;
        break;
      }
    }
    if (f) break;
  }
  for (i = rowS; i <= rowE; i++) {
    for (j = colS; j <= colE; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}
