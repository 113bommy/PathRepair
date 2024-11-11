#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, k;
  cin >> m >> n >> k;
  int a[m][n], b[m][n], i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
      b[i][j] = 0;
    }
  }
  for (j = 0; j < n; j++) {
    for (i = m - 1; i >= 0; i--) {
      if (i == m - 1)
        b[i][j] = a[i][j];
      else if (i + k > m - 1)
        b[i][j] = a[i][j] + b[i + 1][j];
      else
        b[i][j] = a[i][j] + b[i + 1][j] - b[i + k][j];
    }
  }
  int s = 0, t = 0;
  for (j = 0; j < n; j++) {
    int c = 0, mx = 0, z = 0;
    for (i = 0; i < m; i++) {
      if (b[i][j] > mx && a[i][j] == 1) {
        mx = b[i][j];
        z = c;
      }
      if (a[i][j] == 1) c++;
    }
    s += mx;
    t += z;
  }
  cout << s << " " << t;
  return 0;
}
