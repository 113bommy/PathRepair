#include <bits/stdc++.h>
using namespace std;
string calle;
int maxtiempo, n, casas[500000 + 10], houses, shoping;
bool sepuede(int cant) {
  int t = 0, idxcasa = 0, tam = 0, cantdulces = 0;
  for (int i = (0); i < (n); i++) {
    if (cantdulces == houses) break;
    if (calle[i] == 'H') {
      if (cant > 0)
        cant--, cantdulces++;
      else
        casas[tam++] = i;
    } else if (calle[i] == 'S') {
      cant++;
      if (tam - idxcasa > 0 && cant >= tam - idxcasa) {
        cantdulces += tam - idxcasa;
        cant -= (tam - idxcasa);
        if (cantdulces == houses)
          t += i - casas[idxcasa];
        else
          t += 2 * (i - casas[idxcasa]), idxcasa = tam;
      }
    }
    t++;
  }
  return t <= maxtiempo;
}
int main() {
  while (cin >> n >> maxtiempo >> calle) {
    houses = shoping = 0;
    for (int i = (0); i < (n); i++) {
      if (calle[i] == 'H') houses++;
      if (calle[i] == 'S') shoping++;
    }
    if (shoping - houses >= 0 && 1 + 2 * (n - 1) <= maxtiempo) {
      puts("0");
      continue;
    }
    int L = max(-1, houses - shoping - 1), R = n;
    while (L + 1 < R) {
      int mid = (L + R) / 2;
      if (sepuede(mid))
        R = mid;
      else
        L = mid;
    }
    if (R == n)
      puts("-1");
    else
      cout << R << endl;
  }
  return 0;
}
