#include <bits/stdc++.h>
using namespace std;
string a[50];
int pref[50][50];
int stat[50][50][50][50];
int stat2[50][50][50][50];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      pref[i][j] = 0;
      if (i == 0 && j == 0) {
        pref[i][j] = a[i][j] - '0';
      } else if (i == 0) {
        pref[i][j] = pref[i][j - 1] + a[i][j] - '0';
      } else if (j == 0) {
        pref[i][j] = pref[i - 1][j] + a[i][j] - '0';
      } else {
        pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] +
                     a[i][j] - '0';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
          stat[i][j][i1][j1] = 0;
        }
      }
      if (a[i][j] == '0')
        for (int i1 = i; i1 < n; i1++) {
          for (int j1 = j; j1 < m; j1++) {
            int x = 0;
            if (i == 0 && j == 0) {
              if (pref[i1][j1] == 0) {
                x = 1;
              }
            } else if (i == 0) {
              if (pref[i1][j1] - pref[i1][j - 1] == 0) {
                x = 1;
              }
            } else if (j == 0) {
              if (pref[i1][j1] - pref[i - 1][j1] == 0) {
                x = 1;
              }
            } else if (i > 0 && j > 0 &&
                       pref[i1][j1] - pref[i - 1][j1] - pref[i1][j - 1] +
                               pref[i - 1][j - 1] ==
                           0) {
              x = 1;
            }
            if (i == i1 && j == j1) {
              stat[i][j][i1][j1] = x;
            } else if (i == i1) {
              stat[i][j][i1][j1] = x + stat[i][j][i1][j1 - 1];
            } else if (j == j1) {
              stat[i][j][i1][j1] = x + stat[i][j][i1 - 1][j1];
            } else {
              stat[i][j][i1][j1] = x + stat[i][j][i1 - 1][j1] +
                                   stat[i][j][i1][j1 - 1] -
                                   +stat[i][j][i1 - 1][j1 - 1];
            }
          }
        }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int i0 = 0; i0 <= n; i0++) {
        for (int j0 = 0; j0 <= m; j0++) {
          stat2[i0][j0][i][j] = 0;
        }
      }
      for (int i0 = i; i0 >= 0; i0--) {
        for (int j0 = j; j0 >= 0; j0--) {
          stat2[i0][j0][i][j] = stat[i0][j0][i][j] + stat2[i0 + 1][j0][i][j] +
                                stat2[i0][j0 + 1][i][j] -
                                stat2[i0 + 1][j0 + 1][i][j];
        }
      }
    }
  }
  for (int i = 0; i < k; i++) {
    int ans = 0;
    int x1, x2, x3, x4;
    cin >> x1 >> x2 >> x3 >> x4;
    x1--;
    x2--;
    x3--;
    x4--;
    cout << stat2[x1][x2][x3][x4] << "\n";
  }
  return 0;
}
