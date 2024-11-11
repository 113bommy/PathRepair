#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, t, cont = 1, mayor = -1, numero = 0;
  cin >> c;
  for (int i = 0; i < c; i++) {
    cin >> t;
    if (i == 0) {
      numero = t;
    } else {
      if (numero < t) {
        cont++;
      } else {
        cont = 1;
      }
      if (cont > mayor) {
        mayor = cont;
      }
      numero = t;
    }
  }
  cout << mayor << endl;
  return 0;
}
