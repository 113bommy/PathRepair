#include <bits/stdc++.h>
using namespace std;
int const nMax = 101;
char nombres[nMax][nMax];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  bool funciona = true;
  string linea, resultado;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> linea;
    for (int j = 0; j < m; j++) {
      nombres[i][j] = linea[j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      funciona = true;
      for (int k1 = 0; k1 < m; k1++) {
        if (k1 == j) {
          continue;
        }
        if (nombres[i][k1] == nombres[i][j]) {
          funciona = false;
        }
      }
      for (int k2 = 0; k2 < n; k2++) {
        if (k2 == i) {
          continue;
        }
        if (nombres[k2][j] == nombres[i][j]) {
          funciona = false;
        }
      }
      if (funciona) {
        resultado += nombres[i][j];
      }
    }
  }
  cout << resultado;
}
