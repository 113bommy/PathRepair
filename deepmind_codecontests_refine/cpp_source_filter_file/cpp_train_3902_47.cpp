#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  char mat[n + 1][m + 1];
  int c = 0;
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      if (i % 2 == 1)
        mat[i][j] = '#';
      else if (i % 2 == 0 && j == m && c % 2 == 0 && mat[i][1] != '#') {
        mat[i][m] = '#';
        ++c;
      } else if (i % 2 == 0 && j == 1 && c % 2 == 1) {
        mat[i][1] = '#';
        ++c;
      } else
        mat[i][j] = '.';
    }
  }
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) cout << mat[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
