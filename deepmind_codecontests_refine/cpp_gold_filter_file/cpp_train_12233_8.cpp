#include <bits/stdc++.h>
using namespace std;
int criba[1000100 + 1];
void crearcriba() {
  int w[] = {4, 2, 4, 2, 4, 6, 2, 6};
  for (int p = 25; p <= 1000100; p += 10) criba[p] = 5;
  for (int p = 9; p <= 1000100; p += 6) criba[p] = 3;
  for (int p = 4; p <= 1000100; p += 2) criba[p] = 2;
  for (int p = 7, cur = 0; p * p <= 1000100; p += w[cur++ & 7])
    if (!criba[p])
      for (int j = p * p; j <= 1000100; j += (p << 1))
        if (!criba[j]) criba[j] = p;
}
vector<long long> primos;
void buscarprimos() {
  crearcriba();
  for (int i = (2); i < (1000100 + 1); i++)
    if (!criba[i]) primos.push_back(i);
}
long long cota;
vector<long long> divisores;
int main() {
  cin.tie(0), ios_base::sync_with_stdio(0), cout.tie(0);
  cin >> cota;
  buscarprimos();
  for (long long i = 1; i * i <= cota; i++) {
    if (cota % i == 0) {
      if (i != cota / i) {
        divisores.push_back(i);
        divisores.push_back(cota / i);
      } else
        divisores.push_back(i);
    }
  }
  sort(divisores.begin(), divisores.end());
  long long respuesta;
  bool posible = false;
  for (int i = divisores.size() - 1; i >= 0; i--) {
    posible = true;
    for (auto j : primos) {
      if (j * j > divisores[i]) break;
      if (divisores[i] % (j * j) == 0) {
        posible = false;
        break;
      }
    }
    if (posible) {
      respuesta = divisores[i];
      break;
    }
  }
  cout << respuesta << "\n";
  return 0;
}
