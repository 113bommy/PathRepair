#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, ans = 0;
  cin >> n >> m;
  int A[n][m];
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) cin >> A[i][j];
  for (i = n - 2; i > 0; i--) {
    for (j = m - 2; j > 0; j--) {
      if (A[i][j] == 0) {
        if (A[i + 1][j] > A[i][j + 1])
          A[i][j] = A[i][j + 1] - 1;
        else
          A[i][j] = A[i + 1][j] - 1;
      }
    }
  }
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < m - 1; j++) {
      if (A[i][j] >= A[i + 1][j] || A[i][j] >= A[i][j + 1]) {
        cout << "-1" << endl;
        return 0;
      }
    }
  }
  for (j = 0; j < m - 1; j++) {
    if (A[n - 1][j] >= A[n - 1][j + 1]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  for (i = 0; i < n - 1; i++) {
    if (A[i][n - 1] >= A[i + 1][m - 1]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) ans = ans + A[i][j];
  cout << ans << endl;
}
