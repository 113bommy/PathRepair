#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N][N], n, i, j, m, x;
int main() {
  cin >> n >> m;
  x = ((n) > (m) ? (n) : (m));
  a[1][1] = 1;
  a[2][1] = 3;
  a[2][2] = 4;
  for (i = 3; i <= x; i++)
    if (i % 2 == 0) {
      for (j = 1; j < i; j++) a[i][j] = 1;
      a[i][i] = (n - 2) / 2;
    } else {
      a[i][1] = 2;
      for (j = 2; j < i; j++) a[i][j] = 1;
      a[i][i] = (n + 1) / 2;
    }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) cout << a[m][j] * a[n][i] << ' ';
    cout << endl;
  }
}
