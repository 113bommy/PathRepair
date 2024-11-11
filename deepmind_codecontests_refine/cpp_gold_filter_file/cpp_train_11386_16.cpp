#include <bits/stdc++.h>
using namespace std;
int cmp(double x, double y) {
  return ((x + 1e-9 < y) ? -1 : (x - 1e-9 > y) ? 1 : 0);
}
bool dist(double A, double B, double C, double x, double y, double r) {
  double di = fabs(A * x - B * y + C) / (sqrt(A * A + B * B));
  if (cmp(di, r) <= 0) return false;
  return true;
}
int main() {
  double y1, y2, yw, xb, yb, r, xw;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  yw = yw - r - yb;
  double ini = 0, fin = xb, mid, auxi;
  bool distancia;
  while (cmp(ini, fin) < 0) {
    mid = (ini + fin) * 0.5;
    double aux = 2 * mid - xb;
    aux = aux * -1;
    auxi = yw / (xb - mid);
    auxi = auxi * aux;
    auxi += yb;
    distancia = dist(yw, mid + aux, yb * mid + aux * (yw + yb), 0, y2, r);
    if (cmp(y1 + r, auxi) < 0 && cmp(auxi, y2 - r) < 0 && distancia) {
      cout << fixed << setprecision(10) << mid << endl;
      return 0;
    }
    if (cmp(y2 - r, auxi) <= 0 || !distancia)
      ini = mid;
    else
      fin = mid;
  }
  cout << -1 << endl;
  return 0;
}
