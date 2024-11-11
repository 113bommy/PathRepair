#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
};
Point p;
vector<Point> P;
bool cmp(int a, int b) { return a < b; }
double d(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int es_rectangulo(vector<Point>& C) {
  int n = C.size();
  vector<double> dis;
  double aa, bb, cc, dd, ee, ff;
  aa = d(C[0], C[1]);
  bb = d(C[1], C[2]);
  cc = d(C[2], C[3]);
  dd = d(C[3], C[0]);
  ee = d(C[0], C[2]);
  ff = d(C[1], C[3]);
  if (fabs(aa - cc) <= 1e-5 && fabs(bb - dd) <= 1e-5 && fabs(ee - ff) <= 1e-5) {
    if (fabs(aa - bb) <= 1e-5) return 1;
    return 2;
  }
  return 0;
}
void es_posible() {
  int orden[8];
  for (int i = 0; i < 8; i++) orden[i] = i;
  bool posible = false;
  do {
    vector<Point> cuad, rect;
    for (int i = 0; i < 4; i++) cuad.push_back(P[orden[i]]);
    for (int i = 4; i < 8; i++) rect.push_back(P[orden[i]]);
    int x = es_rectangulo(cuad);
    int y = es_rectangulo(rect);
    if (x == 1 && (y == 1 || y == 2)) {
      cout << "YES" << endl;
      cout << orden[0] + 1;
      for (int i = 1; i < 4; i++) cout << " " << orden[i] + 1;
      cout << endl;
      cout << orden[4] + 1;
      for (int i = 5; i < 8; i++) cout << " " << orden[i] + 1;
      cout << endl;
      posible = true;
      break;
    }
  } while (next_permutation(orden, orden + 8, cmp));
  if (!posible) cout << "NO" << endl;
}
int main() {
  while (cin >> p.x >> p.y) {
    P.clear();
    P.push_back(p);
    for (int i = 0; i < 7; i++) {
      cin >> p.x >> p.y;
      P.push_back(p);
    }
    es_posible();
  }
  return 0;
}
