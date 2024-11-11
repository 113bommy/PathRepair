#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  char poli;
};
long long cross(Point &O, Point &A, Point &B) {
  long long uno = (long long)((long long)A.x - (long long)O.x),
            dos = (long long)((long long)B.y - (long long)O.y),
            tres = (long long)((long long)A.y - (long long)O.y),
            cuatro = (long long)((long long)B.x - (long long)O.x);
  long long c = (long long)((long long)((long long)uno * (long long)dos) -
                            (long long)((long long)tres * (long long)cuatro));
  return c;
}
bool cmp(Point A, Point B) { return (A.y < B.y || (A.y == B.y && A.x < B.x)); }
vector<Point> convex(vector<Point> &P) {
  int n = P.size(), k = 0;
  vector<Point> H(2 * n);
  for (int i = 0; i < n; i++) {
    while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
    H[k++] = P[i];
  }
  for (int i = n - 2, t = k + 1; i >= 0; i--) {
    while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }
  H.resize(k);
  return H;
}
int main() {
  vector<Point> P;
  Point p;
  int n, m;
  while (cin >> n) {
    P.clear();
    p.poli = 'A';
    while (n--) cin >> p.x >> p.y, P.push_back(p);
    cin >> m;
    p.poli = 'B';
    while (m--) cin >> p.x >> p.y, P.push_back(p);
    sort(P.begin(), P.end(), cmp);
    bool sw = true;
    vector<Point> C = convex(P);
    for (int i = 0; i < C.size() && sw; i++)
      if (C[i].poli == 'B') sw = false;
    if (sw)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
