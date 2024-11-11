#include <bits/stdc++.h>
using namespace std;
int a[200005], b[100000], n;
char mat[500][500];
bool cango(int i, int j) {
  if (mat[i][i] == '.' && mat[i - 1][j] == '.' && mat[i + 1][j] == '.' &&
      mat[i][j + 1] == '.' && mat[i][j - 1] == '.')
    return true;
  return false;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> mat[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (cango(i, j)) {
        mat[i - 1][j] = '#';
        mat[i][j - 1] = '#';
        mat[i][j] = '#';
        mat[i + 1][j] = '#';
        mat[i][j + 1] = '#';
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (mat[i][j] == '.') {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
