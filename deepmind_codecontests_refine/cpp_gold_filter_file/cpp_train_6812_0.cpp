#include <bits/stdc++.h>
using namespace std;
int r, p, x[102][102][12], i, j, n, m, k, a[102][102], o, y[102][102][12], l,
    mi;
string s;
vector<int> path;
int main() {
  cin >> n >> m >> k;
  int kk = k + 1;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      for (o = 0; o <= k; o++) x[i][j][o] = -1;
  for (i = 1; i <= n; i++) {
    cin >> s;
    for (j = 0; j < m; j++) {
      a[i][j + 1] = s[j] - '0';
      if (i == n) x[n][j + 1][((a[n][j + 1] % kk + kk) % kk)] = a[n][j + 1];
    }
  }
  for (i = n - 1; i > 0; i--) {
    for (j = 1; j <= m; j++) {
      for (o = 0; o <= k; o++) {
        if (x[i + 1][j - 1][o] != -1 && j > 1) {
          if (x[i][j][((o + a[i][j]) % kk + kk) % kk] <
              x[i + 1][j - 1][o] + a[i][j]) {
            x[i][j][((o + a[i][j]) % kk + kk) % kk] =
                x[i + 1][j - 1][o] + a[i][j];
            y[i][j][((o + a[i][j]) % kk + kk) % kk] = 1;
          }
        }
        if (x[i + 1][j + 1][o] != -1 && j < m) {
          if (x[i][j][((o + a[i][j]) % kk + kk) % kk] <
              x[i + 1][j + 1][o] + a[i][j]) {
            x[i][j][((o + a[i][j]) % kk + kk) % kk] =
                x[i + 1][j + 1][o] + a[i][j];
            y[i][j][((o + a[i][j]) % kk + kk) % kk] = 2;
          }
        }
      }
      if (i == 1) {
        if (x[i][j][0] >= mi) {
          mi = x[i][j][0];
          l = j;
          r = 1;
        }
      }
    }
  }
  if (r == 0) {
    cout << -1;
    return 0;
  }
  for (i = 1; i < n; i++) {
    if (y[i][l][p] == 0) {
      cout << -1;
      return 0;
    }
    path.push_back(y[i][l][p]);
    int v = p;
    p = ((p - a[i][l]) % kk + kk) % kk;
    if (y[i][l][v] == 1)
      l--;
    else
      l++;
  }
  cout << mi << endl;
  cout << l << endl;
  for (i = path.size() - 1; i >= 0; i--) {
    if (path[i] == 1)
      cout << "R";
    else
      cout << "L";
  }
  return 0;
}
