#include <bits/stdc++.h>
using namespace std;
int n, m, k, h;
vector<string> s;
vector<vector<int> > t;
vector<int> tt;
vector<vector<vector<int> > > a;
vector<vector<int> > aa;
vector<int> aaa;
vector<vector<vector<string> > > u;
vector<vector<string> > uu;
vector<string> uuu;
vector<vector<vector<int> > > v;
vector<vector<int> > vv;
vector<int> vvv;
int main() {
  cin >> n >> m >> k;
  k++;
  uuu.assign(k, "");
  uu.assign(m, uuu);
  u.assign(n, uu);
  vvv.assign(k, 0);
  vv.assign(m, vvv);
  v.assign(n, vv);
  s.resize(n);
  aaa.assign(k, -1);
  aa.assign(m, aaa);
  a.assign(n, aa);
  for (int i = 0; i < n; i++) cin >> s[i];
  tt.resize(m);
  t.assign(n, tt);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) t[i][j] = s[i][j] - '0';
  for (int i = 0; i < m; i++) {
    a[0][i][t[0][i] % k] = t[0][i];
    v[0][i][t[0][i] % k] = i + 1;
  }
  for (int i = 0; i < n - 1; i++)
    for (int l = 0; l < k; l++) {
      if (a[i][0][l] != -1) {
        if (a[i][0][l] + t[i + 1][1] >
            a[i + 1][1][(a[i][0][l] + t[i + 1][1]) % k]) {
          a[i + 1][1][(a[i][0][l] + t[i + 1][1]) % k] =
              a[i][0][l] + t[i + 1][1];
          u[i + 1][1][(a[i][0][l] + t[i + 1][1]) % k] = u[i][0][l] + "R";
          v[i + 1][1][(a[i][0][l] + t[i + 1][1]) % k] = v[i][0][l];
        }
      }
      if (a[i][m - 1][l] != -1) {
        if (a[i][m - 1][l] + t[i + 1][m - 2] >
            a[i + 1][m - 2][(a[i][m - 1][l] + t[i + 1][m - 2]) % k]) {
          a[i + 1][m - 2][(a[i][m - 1][l] + t[i + 1][m - 2]) % k] =
              a[i][m - 1][l] + t[i + 1][m - 2];
          u[i + 1][m - 2][(a[i][m - 1][l] + t[i + 1][m - 2]) % k] =
              u[i][m - 1][l] + "L";
          v[i + 1][m - 2][(a[i][m - 1][l] + t[i + 1][m - 2]) % k] =
              v[i][m - 1][l];
        }
      }
      for (int j = 1; j < m - 1; j++)
        if (a[i][j][l] != -1) {
          if (a[i][j][l] + t[i + 1][j + 1] >
              a[i + 1][j + 1][(a[i][j][l] + t[i + 1][j + 1]) % k]) {
            a[i + 1][j + 1][(a[i][j][l] + t[i + 1][j + 1]) % k] =
                a[i][j][l] + t[i + 1][j + 1];
            u[i + 1][j + 1][(a[i][j][l] + t[i + 1][j + 1]) % k] =
                u[i][j][l] + "R";
            v[i + 1][j + 1][(a[i][j][l] + t[i + 1][j + 1]) % k] = v[i][j][l];
          }
          if (a[i][j][l] + t[i + 1][j - 1] >
              a[i + 1][j - 1][(a[i][j][l] + t[i + 1][j - 1]) % k]) {
            a[i + 1][j - 1][(a[i][j][l] + t[i + 1][j - 1]) % k] =
                a[i][j][l] + t[i + 1][j - 1];
            u[i + 1][j - 1][(a[i][j][l] + t[i + 1][j - 1]) % k] =
                u[i][j][l] + "L";
            v[i + 1][j - 1][(a[i][j][l] + t[i + 1][j - 1]) % k] = v[i][j][l];
          }
        }
    }
  for (int i = 1; i < m; i++)
    if (a[n - 1][i][0] > a[n - 1][h][0]) h = i;
  if (a[n - 1][h][0] == -1)
    cout << -1 << "\n";
  else
    cout << a[n - 1][h][0] << "\n"
         << v[n - 1][h][0] << "\n"
         << u[n - 1][h][0] << "\n";
  return 0;
}
