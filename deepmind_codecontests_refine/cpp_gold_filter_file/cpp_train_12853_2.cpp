#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  cin >> n >> m;
  char a[n][m + 1];
  bool b[n];
  memset(b, 0, sizeof(b));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) cin >> a[i][j];
    a[i][m] = 0;
  }
  int c = 0;
  for (i = 0; i < m; i++) {
    for (j = 1; j < n; j++) {
      if ((!b[j]) && a[j][i] < a[j - 1][i]) {
        c++;
        break;
      }
    }
    if (j == n) {
      for (j = 1; j < n; j++) {
        if (a[j][i] > a[j - 1][i]) b[j] = true;
      }
    }
  }
  cout << c << '\n';
  return 0;
}
