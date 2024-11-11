#include <bits/stdc++.h>
using namespace std;
int n, m, nn, q[333][333];
char a[1111][1111];
long long q1[333], q2[333], d[333];
int main() {
  scanf("%d%d\n", &n, &m);
  nn = n * 4 + 1;
  for (int i = 0; i < nn; i++) gets(a[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      string s = "";
      for (int ii = 0; ii < 3; ii++)
        for (int jj = 0; jj < 3; jj++) s += a[i * 4 + 1 + ii][j * 4 + 1 + jj];
      if (s == ".........") q[i][j] = 3;
      if (s == "....O....") q[i][j] = 3;
      if (s == "..O...O..") q[i][j] = 1;
      if (s == "O.......O") q[i][j] = 2;
      if (s == "..O.O.O..") q[i][j] = 1;
      if (s == "O...O...O") q[i][j] = 2;
      if (s == "O.O...O.O") q[i][j] = 3;
      if (s == "O.O.O.O.O") q[i][j] = 3;
      if (s == "O.OO.OO.O") q[i][j] = 1;
      if (s == "OOO...OOO") q[i][j] = 2;
    }
  for (int i = 0; i < m; i++) {
    if (n % 2 == 0) {
      int t = 0;
      for (int j = 0; j < n; j++)
        if (q[i][j] == 2) t = 1;
      if (!t) q1[i] = 1;
    }
    if (i < m - 1) {
      memset(d, 0, sizeof(d));
      d[0] = 1;
      for (int j = 0; j < n; j++) {
        if (q[j][i] != 1 && q[j][i + 1] != 1)
          d[j + 1] = (d[j + 1] + d[j]) % 1000000007;
        if (j < n - 1 && q[j][i] != 2 && q[j][i + 1] != 2 && q[j + 1][i] != 2 &&
            q[j + 1][i + 1] != 2)
          d[j + 2] = (d[j + 2] + d[j]) % 1000000007;
      }
      q2[i] = d[n];
    }
  }
  for (int i = 0; i < m - 1; i++)
    if (q1[i] && q1[i + 1]) q2[i] = (q2[i] - 1 + 1000000007) % 1000000007;
  memset(d, 0, sizeof(d));
  d[0] = 1;
  for (int i = 0; i < m; i++) {
    d[i + 1] = (d[i + 1] + d[i] * q1[i]) % 1000000007;
    d[i + 2] = (d[i + 2] + d[i] * q2[i]) % 1000000007;
  }
  cout << (d[m]) << endl;
  return 0;
}
