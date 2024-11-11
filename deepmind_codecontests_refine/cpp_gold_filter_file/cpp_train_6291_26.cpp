#include <bits/stdc++.h>
using namespace std;
long long n, arreglo[105], suma = 0, hola, aux, low = 100000;
int main() {
  cin >> n;
  for (long long x = 1; x <= n; x++) {
    cin >> arreglo[x];
  }
  for (long long x = 1; x <= n; x++) {
    for (long long y = 1; y <= arreglo[x]; y++) {
      cin >> hola;
      suma = suma + hola;
    }
    suma = suma * 5;
    aux = arreglo[x] * 15;
    suma = suma + aux;
    if (low > suma) {
      low = suma;
    }
    suma = 0;
    aux = 0;
  }
  cout << low;
  return 0;
}
