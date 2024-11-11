#include <bits/stdc++.h>
using namespace std;
int m, n;
int mat[105][105];
int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }
  if (m % 2 != 0) {
    cout << m << endl;
  } else {
    int aux = m;
    bool flag = true;
    int cont = 0;
    bool flag2 = true;
    while (flag) {
      aux = aux / 2;
      if (aux == 1) {
        for (int j = 0; j < n; j++) {
          if (mat[0][j] != mat[1][j]) {
            flag2 = false;
          }
        }
        if (flag2) {
          cont++;
        }
        flag = false;
        break;
      }
      for (int i = 0; i < aux; i++) {
        for (int j = 0; j < n; j++) {
          if (mat[aux - i - 1][j] != mat[aux + i][j]) {
            flag = false;
          }
        }
      }
      if (flag) cont++;
      if (aux % 2 != 0) break;
    }
    for (int i = 0; i < cont; i++) {
      m = m / 2;
    }
    cout << m << endl;
  }
  return 0;
}
