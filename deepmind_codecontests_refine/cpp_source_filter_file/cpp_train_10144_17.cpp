#include <bits/stdc++.h>
using namespace std;
int ht[300][300], tt[300][300][8], n, m, t, tp, tu, td;
void print(const char *s, int k) {
  cout << s << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << setw(2) << tt[i][j][k] << " ";
    cout << endl;
  }
}
int main() {
  int i1, j1, i2, j2, bestDt = 2e9;
  cin >> n >> m >> t >> tp >> tu >> td;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> ht[i][j];
  for (int i = 0; i < n; ++i) {
    tt[i][0][0] = 0;
    tt[i][m - 1][2] = 0;
    for (int j = 1; j < m; ++j) {
      tt[i][j][0] =
          tt[i][j - 1][0] + ((ht[i][j - 1]) == (ht[i][j])
                                 ? tp
                                 : ((ht[i][j - 1]) < (ht[i][j]) ? tu : td));
      tt[i][m - 1 - j][2] =
          tt[i][m - j][2] +
          ((ht[i][m - j]) == (ht[i][m - 1 - j])
               ? tp
               : ((ht[i][m - j]) < (ht[i][m - 1 - j]) ? tu : td));
    }
  }
  for (int j = 0; j < m; ++j) {
    tt[0][j][1] = 0;
    tt[n - 1][j][3] = 0;
    for (int i = 1; i < n; ++i) {
      tt[i][j][1] =
          tt[i - 1][j][1] + ((ht[i - 1][j]) == (ht[i][j])
                                 ? tp
                                 : ((ht[i - 1][j]) < (ht[i][j]) ? tu : td));
      tt[n - 1 - i][j][3] =
          tt[n - i][j][3] +
          ((ht[n - i][j]) == (ht[n - 1 - i][j])
               ? tp
               : ((ht[n - i][j]) < (ht[n - 1 - i][j]) ? tu : td));
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      tt[i][j][5] = tt[i][j][3] - tt[i][j][0];
      tt[i][j][6] = tt[i][j][0] - tt[i][j][1];
      tt[i][j][7] = tt[i][j][2] - tt[i][j][3];
      tt[i][j][8] = tt[i][j][1] - tt[i][j][2];
    }
  for (int imin = 0; imin < n; ++imin)
    for (int jmin = 0; jmin < m; ++jmin) {
      int d1 = tt[imin][jmin][5] - t;
      for (int imax = imin + 2; imax < n; ++imax) {
        int d2 = d1 + tt[imax][jmin][7];
        for (int jmax = jmin + 2; jmax < m; ++jmax) {
          int dt = d2 + tt[imin][jmax][6] + tt[imax][jmax][8];
          if (abs(dt) < bestDt)
            i1 = imin, j1 = jmin, i2 = imax, j2 = jmax, bestDt = abs(dt);
        }
      }
    }
  cout << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << endl;
  return 0;
}
