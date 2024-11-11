#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int main() {
  int n, m, k, lenght, result = 0;
  long long suma, suma2;
  cin >> n >> m >> k;
  vector<int> valores(m), imprimir(m);
  vector<vector<int> > v(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> v[i][j];
  lenght = 0;
  for (int i = 0; i < n; i++) {
    suma = 0;
    for (int j = 0; j < m; j++) {
      valores[j] = max(valores[j], v[i][j]);
      suma += valores[j];
    }
    if (suma > k) {
      lenght = 0;
      suma = 0;
      valores.assign(m, 0);
      for (int w = i; w >= 0; w--) {
        suma2 = 0;
        for (int j = 0; j < m; j++) suma2 += max(valores[j], v[w][j]);
        if (suma2 > k) break;
        suma = suma2;
        lenght++;
        for (int j = 0; j < m; j++) valores[j] = max(valores[i], v[w][j]);
      }
    } else
      lenght++;
    if (lenght > result) {
      result = lenght;
      imprimir = valores;
    }
  }
  for (int j = 0; j < m; j++) cout << imprimir[j] << (j == m - 1 ? '\n' : ' ');
  return 0;
}
