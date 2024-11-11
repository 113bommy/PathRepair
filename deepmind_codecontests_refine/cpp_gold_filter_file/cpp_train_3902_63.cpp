#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, m = 0;
  cin >> n >> m;
  char z[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i == 1 && j == m - 1)
        z[i][j] = '#';
      else if (i % 2 == 0)
        z[i][j] = '#';
      else if (i % 2 == 1 && (j == 0 || j == m - 1) && z[i - 2][j] == '.')
        z[i][j] = '#';
      else
        z[i][j] = '.';
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << z[i][j];
    cout << endl;
  }
}
