#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char M[n][n];
  int i, j;
  for (i = 0; i < n; i++) {
    string fila;
    cin >> fila;
    for (j = 0; j < n; j++) {
      M[i][j] = fila[j];
    }
  }
  int contador = 0;
  for (i = 1; i < n - 1; i++) {
    for (j = 1; j < n - 1; j++) {
      if (M[i][j] == 'X') {
        if (M[i - 1][j - 1] == 'X' && M[i + 1][j - 1] == 'X' &&
            M[i - 1][j + 1] == 'X' && M[i + 1][j + 1] == 'X') {
          contador++;
        }
      }
    }
  }
  cout << contador;
  return 0;
}
