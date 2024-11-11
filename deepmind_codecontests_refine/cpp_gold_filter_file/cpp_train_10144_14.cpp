#include <bits/stdc++.h>
using namespace std;
int ht[300][300], tt[8][300][300], n, m, t, tp, tu, td;
void print(const char *s, int k) {
  cout << s << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << setw(2) << tt[k][i][j] << " ";
    cout << endl;
  }
}
int main() {
  int i1, j1, i2, j2, bestDt = 2e9;
  cin >> n >> m >> t >> tp >> tu >> td;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> ht[i][j];
  for (int i = 0; i < n; ++i) {
    tt[0][i][0] = 0;
    tt[2][i][m - 1] = 0;
    for (int j = 1; j < m; ++j) {
      tt[0][i][j] =
          tt[0][i][j - 1] + ((ht[i][j - 1]) == (ht[i][j])
                                 ? tp
                                 : ((ht[i][j - 1]) < (ht[i][j]) ? tu : td));
      tt[2][i][m - 1 - j] =
          tt[2][i][m - j] +
          ((ht[i][m - j]) == (ht[i][m - 1 - j])
               ? tp
               : ((ht[i][m - j]) < (ht[i][m - 1 - j]) ? tu : td));
    }
  }
  for (int j = 0; j < m; ++j) {
    tt[1][0][j] = 0;
    tt[3][n - 1][j] = 0;
    for (int i = 1; i < n; ++i) {
      tt[1][i][j] =
          tt[1][i - 1][j] + ((ht[i - 1][j]) == (ht[i][j])
                                 ? tp
                                 : ((ht[i - 1][j]) < (ht[i][j]) ? tu : td));
      tt[3][n - 1 - i][j] =
          tt[3][n - i][j] +
          ((ht[n - i][j]) == (ht[n - 1 - i][j])
               ? tp
               : ((ht[n - i][j]) < (ht[n - 1 - i][j]) ? tu : td));
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      tt[5][i][j] = tt[3][i][j] - tt[0][i][j];
      tt[6][i][j] = tt[0][i][j] - tt[1][i][j];
      tt[7][i][j] = tt[2][i][j] - tt[3][i][j];
      tt[8][i][j] = tt[1][i][j] - tt[2][i][j];
    }
  for (int imin = 0; imin < n; ++imin)
    for (int jmin = 0; jmin < m; ++jmin) {
      int d1 = tt[5][imin][jmin] - t;
      for (int imax = imin + 2; imax < n; ++imax) {
        int d2 = d1 + tt[7][imax][jmin];
        for (int jmax = jmin + 2; jmax < m; ++jmax) {
          int dt = d2 + tt[6][imin][jmax] + tt[8][imax][jmax];
          if (abs(dt) < bestDt)
            i1 = imin, j1 = jmin, i2 = imax, j2 = jmax, bestDt = abs(dt);
        }
      }
    }
  cout << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << endl;
  return 0;
}
