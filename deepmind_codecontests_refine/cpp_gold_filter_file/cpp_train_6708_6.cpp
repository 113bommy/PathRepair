#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  int colors[m][n];
  int temp[m][n];
  int x, y;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) cin >> colors[i][j];
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      if (i == 0) {
        temp[j][i] = sum + colors[j][i];
        sum = temp[j][i];
      } else {
        x = temp[j][i - 1] + colors[j][i];
        if (j != 0)
          y = temp[j - 1][i] + colors[j][i];
        else
          y = colors[j][i];
        temp[j][i] = (x > y) ? x : y;
      }
    }
  }
  for (int i = 0; i < m; i++) cout << temp[i][n - 1] << " ";
}
