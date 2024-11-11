#include <bits/stdc++.h>
using namespace std;
struct Punto {
  int x;
  int y;
  int i;
};
bool comparar(Punto p1, Punto p2) {
  int cp1 = p1.y / 1000, cp2 = p2.y / 1000;
  if (cp1 != cp2) return cp1 < cp2;
  if (p1.x == p2.x) return p1.y < p2.y;
  if (cp1 % 2)
    return p1.x < p2.x;
  else
    return p2.x < p1.x;
}
Punto puntos[1100000];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &puntos[i].x, &puntos[i].y);
    puntos[i].i = i + 1;
  }
  sort(puntos, puntos + n, comparar);
  for (int i = 0; i < n; i++) printf("%d ", puntos[i].i);
  printf("\n");
}
