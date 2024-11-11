#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[402][402];
int row[402][402], col[402][402], diag1[804][402], diag2[804][402];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i <= m; i++) row[0][i] = 0;
  for (int i = 0; i <= n; i++) col[i][0] = 0;
  for (int i = 2; i <= n + m; i++) diag1[i][0] = 0;
  for (int i = 0; i <= n + m; i++) diag2[i][0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> (a[i] + 1);
    for (int j = 1; j <= m; j++) {
      int inc = (a[i][j] == '1');
      row[i][j] = row[i][j - 1] + inc;
      col[j][i] = col[j][i - 1] + inc;
      diag1[i + j][i] = diag1[i + j][i - 1] + inc;
      diag2[i - j + m][i] = diag2[i - j + m][i - 1] + inc;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 2; k <= max(n, m); k++) {
        if (i >= k && j >= k) {
          if (col[j][i] - col[j][i - k] == 0 &&
              row[i][j] - row[i][j - k] == 0 &&
              diag1[i + j - k + 1][i] - diag1[i + j - k + 1][i - k] == 0)
            ans++;
        }
        if (i >= k && j + k - 1 <= m) {
          if (col[j][i] - col[j][i - k] == 0 &&
              row[i][j + k - 1] - row[i][j - 1] == 0 &&
              diag2[m + i - k + 1 - j][i] - diag2[m + i - j - k + 1][i - k] ==
                  0)
            ans++;
        }
        if (i + k - 1 <= n && j >= k) {
          if (col[j][i + k - 1] - col[j][i - 1] == 0 &&
              row[i][j] - row[i][j - k] == 0 &&
              diag2[m + i + k - 1 - j][i + k - 1] -
                      diag2[m + i + k - 1 - j][i - 1] ==
                  0)
            ans++;
        }
        if (i + k - 1 <= n && j + k - 1 <= m) {
          if (col[j][i + k - 1] - col[j][i - 1] == 0 &&
              row[i][j + k - 1] - row[i][j - 1] == 0 &&
              diag1[i + k - 1 + j][i + k - 1] - diag1[i + k - 1 + j][i - 1] ==
                  0)
            ans++;
        }
        if (j - k + 1 >= 1 && j + k - 1 <= m && i >= k) {
          if (row[i - k + 1][j + k - 1] - row[i - k + 1][j - k] == 0 &&
              diag1[i + j][i] - diag1[i + j][i - k] == 0 &&
              diag2[m + i - j][i] - diag2[m + i - j][i - k] == 0)
            ans++;
        }
        if (j - k + 1 >= 1 && j + k - 1 <= m && i + k - 1 <= n) {
          if (row[i + k - 1][j + k - 1] - row[i + k - 1][j - k] == 0 &&
              diag1[i + j][i + k - 1] - diag1[i + j][i - 1] == 0 &&
              diag2[m + i - j][i + k - 1] - diag2[m + i - j][i - 1] == 0)
            ans++;
        }
        if (i - k + 1 >= 1 && i + k - 1 <= n && j >= k) {
          if (col[j - k + 1][i + k - 1] - col[j - k + 1][i - k] == 0 &&
              diag1[i + j][i + k - 1] - diag1[i + j][i - 1] == 0 &&
              diag2[m + i - j][i] - diag2[m + i - j][i - k] == 0)
            ans++;
        }
        if (i - k + 1 >= 1 && i + k - 1 <= n && j + k - 1 <= m) {
          if (col[j + k - 1][i + k - 1] - col[j + k - 1][i - k] == 0 &&
              diag1[i + j][i] - diag1[i + j][i - k] == 0 &&
              diag2[m + i - j][i + k - 1] - diag2[m + i - j][i - 1] == 0)
            ans++;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
