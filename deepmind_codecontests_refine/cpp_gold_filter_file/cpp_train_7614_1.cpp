#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, h;
  cin >> n >> m >> h;
  int a[m], b[n];
  int mat[n][m];
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      if (mat[i][j]) mat[i][j] = min(a[j], b[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << mat[i][j] << " \n"[j == m - 1];
    }
  }
  return 0;
}
