#include <bits/stdc++.h>
using namespace std;
void ordenar(int x[], int m) {
  for (int i = 1; i < m; i++) {
    int j = i;
    while (j > 0 && x[j - 1] < x[j]) {
      swap(x[j - 1], x[j]);
      j--;
    }
  }
}
int main() {
  int n, k, q;
  int p = 0;
  cin >> n;
  cin >> k;
  cin >> q;
  int respuesta[q];
  long long r[n];
  int pantalla[k + 1];
  for (int i = 0; i <= k; i++) {
    pantalla[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> r[i];
  }
  for (int i = 0; i < q; i++) {
    int tipo, amigo;
    cin >> tipo;
    cin >> amigo;
    bool repite = false;
    bool sale = false;
    switch (tipo) {
      case 1:
        for (int j = 0; j < k + 1; j++) {
          if (pantalla[j] == r[amigo - 1]) {
            repite = true;
          }
        }
        if (repite == false) {
          pantalla[k] = r[amigo - 1];
          ordenar(pantalla, k + 1);
        }
        break;
      case 2:
        for (int j = 0; j < k; j++) {
          if (pantalla[j] == r[amigo - 1]) {
            respuesta[p] = 1;
            sale = true;
          }
        }
        if (sale == false) {
          respuesta[p] = 0;
        }
        p++;
        break;
    }
  }
  for (int i = 0; i < p; i++) {
    if (respuesta[i] == 1) {
      cout << "YES" << endl;
    } else if (respuesta[i] == 0) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
