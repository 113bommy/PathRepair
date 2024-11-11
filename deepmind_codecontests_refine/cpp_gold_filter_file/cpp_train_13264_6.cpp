#include <bits/stdc++.h>
using namespace std;
int n, m, q;
string s[41];
bool a[44][44][44][44];
int p[44][44][44][44];
int z[44][44][44][44];
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k <= n; k++) a[i][j][k][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k <= m; k++) a[i][j][0][k] = 1;
  for (int i = 1; i <= max(n, m); i++) {
    for (int j = 1; j <= i; j++) {
      for (int k = 0; k < n; k++)
        for (int l = 0; l < m; l++)
          if (a[k][l][i - 1][j] && a[k][l][i][j - 1] &&
              s[i + k - 1][j + l - 1] == '0')
            a[k][l][i][j] = true;
      swap(i, j);
      for (int k = 0; k < n; k++)
        for (int l = 0; l < m; l++)
          if (a[k][l][i - 1][j] && a[k][l][i][j - 1] &&
              s[i + k - 1][j + l - 1] == '0')
            a[k][l][i][j] = true;
      swap(i, j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 1; k <= n; k++)
        for (int l = 1; l <= m; l++) {
          p[i][j][k][l] =
              p[i][j][k - 1][l] + p[i][j][k][l - 1] - p[i][j][k - 1][l - 1];
          if (a[i][j][k][l]) p[i][j][k][l]++;
        }
    }
  }
  for (int x1 = n - 1; x1 >= 0; x1--)
    for (int y1 = m - 1; y1 >= 0; y1--)
      for (int x2 = n - 1; x2 >= x1; x2--)
        for (int y2 = m - 1; y2 >= y1; y2--) {
          z[x1][y1][x2][y2] = z[x1 + 1][y1 + 1][x2][y2];
          for (int i = y1 + 1; i <= y2; i++)
            z[x1][y1][x2][y2] += p[x1][i][x2 - x1 + 1][y2 - i + 1];
          for (int i = x1 + 1; i <= x2; i++)
            z[x1][y1][x2][y2] += p[i][y1][x2 - i + 1][y2 - y1 + 1];
          z[x1][y1][x2][y2] += p[x1][y1][x2 - x1 + 1][y2 - y1 + 1];
        }
  for (int i = 0; i < q; i++) {
    int d, b, c, e;
    cin >> b >> c >> d >> e;
    int sum = 0;
    b--;
    c--;
    d--;
    e--;
    cout << z[b][c][d][e] << endl;
  }
}
