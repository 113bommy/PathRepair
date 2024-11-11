#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string linea;
  scanf("%d", &n);
  cin >> linea;
  vector<int> posicion;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    posicion.push_back(x);
  }
  int distanciaMinima = 1000000000;
  for (int i = 1; i < n; i++) {
    if (linea[i] == 'L' && linea[i - 1] == 'R') {
      distanciaMinima = min(distanciaMinima, posicion[i] - posicion[i - 1]);
    }
  }
  if (distanciaMinima == 1000000000) {
    printf("-1\n");
    return 0;
  }
  if (distanciaMinima % 2 == 0) {
    printf("%d\n", distanciaMinima / 2);
  } else {
    printf("%d\n", distanciaMinima / 2 + 1);
  }
  return 0;
}
