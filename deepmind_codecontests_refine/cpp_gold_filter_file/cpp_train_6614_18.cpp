#include <bits/stdc++.h>
using namespace std;
int n, m, q, tip, r, c, x, a[110][110];
int input[10010][10], row, column, aux;
int main() {
  cin >> n >> m >> q;
  for (int j = 1; j <= q; j++) {
    cin >> input[j][1];
    if (input[j][1] == 1)
      cin >> input[j][2];
    else if (input[j][1] == 2)
      cin >> input[j][2];
    else {
      cin >> input[j][2];
      cin >> input[j][3];
      cin >> input[j][4];
    }
  }
  for (int j = q; j; j--) {
    if (input[j][1] == 1) {
      row = input[j][2];
      aux = a[row][m];
      for (int i = m; i > 1; i--) a[row][i] = a[row][i - 1];
      a[row][1] = aux;
    } else if (input[j][1] == 2) {
      column = input[j][2];
      aux = a[n][column];
      for (int i = n; i > 1; i--) a[i][column] = a[i - 1][column];
      a[1][column] = aux;
    } else {
      a[input[j][2]][input[j][3]] = input[j][4];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << a[i][j] << " ";
    cout << '\n';
  }
}
