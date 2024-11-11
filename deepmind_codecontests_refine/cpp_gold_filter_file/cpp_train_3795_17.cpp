#include <bits/stdc++.h>
using namespace std;
char mat[110][110];
int main() {
  int n;
  while (cin >> n) {
    memset(mat, '*', sizeof(mat));
    for (int i = 1; i <= n / 2 + 1; i++) {
      for (int j = (n + 1) / 2 + 1 - i; j <= (n + 1) / 2 + i - 1; j++)
        mat[i][j] = 'D';
    }
    for (int i = n / 2 + 2; i <= n; i++) {
      for (int j = i - n / 2; j <= 3 * n / 2 - i + 1; j++) mat[i][j] = 'D';
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n - 1; j++) {
        cout << mat[i][j];
      }
      cout << mat[i][n] << endl;
    }
  }
  return 0;
}
