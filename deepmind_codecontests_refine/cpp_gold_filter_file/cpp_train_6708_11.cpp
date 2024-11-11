#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  int inp[m][n];
  int final[n][m];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> inp[i][j];
    }
  }
  final[0][0] = inp[0][0];
  for (int i = 1; i < m; i++) {
    final[0][i] = final[0][i - 1] + inp[i][0];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j == 0) {
        final[i][j] = final[i - 1][j] + inp[0][i];
      } else if (final[i - 1][j] <= final[i][j - 1]) {
        final[i][j] = final[i][j - 1] + inp[j][i];
      } else if (final[i - 1][j] > final[i][j - 1]) {
        final[i][j] = final[i - 1][j] + inp[j][i];
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cout << final[n - 1][i] << " ";
  }
  cout << endl;
}
