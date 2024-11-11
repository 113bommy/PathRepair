#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
const int INF = 1e9 + 7;
const double EPS = 1e-10;
struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  friend Point operator-(Point p1, Point p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
  }
  friend bool operator<(Point p1, Point p2) {
    return (p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y);
  }
};
double norma(Point v) { return sqrt(1LL * v.x * v.x + 1LL * v.y * v.y); }
double cross(Point v1, Point v2) {
  return 1LL * v1.x * v2.y - 1LL * v2.x * v1.y;
}
vector<Point> ConvexHull(vector<Point> P) {
  if (P.size() < 3) return P;
  Point p = *(min_element(P.begin(), P.end()));
  sort(P.begin(), P.end(), [p](Point p1, Point p2) {
    double area = cross(p1 - p, p2 - p);
    if (area == 0) return norma(p1 - p) < norma(p2 - p);
    return area > 0;
  });
  vector<Point> C;
  C.push_back(P[0]);
  C.push_back(P[1]);
  int it = 2, szC = 2;
  while (it < P.size()) {
    if (szC > 1 && cross(P[it] - C[szC - 1], C[szC - 2] - C[szC - 1]) <= 0) {
      C.pop_back();
      szC--;
    } else {
      C.push_back(P[it]);
      szC++;
      it++;
    }
  }
  return C;
}
struct data {
  double a, b, c;
  friend bool operator==(data d1, data d2) {
    bool eq1 = abs(d1.a - d2.a) <= EPS;
    bool eq2 = abs(d1.b - d2.b) <= EPS;
    bool eq3 = abs(d1.c - d2.c) <= EPS;
    return eq1 && eq2 && eq3;
  }
  friend bool operator!=(data d1, data d2) { return !(d1 == d2); }
};
vector<int> F;
void buildF(vector<data> &P) {
  F = vector<int>(P.size(), 0);
  for (int itP = 1, len = 0; itP < P.size(); itP++) {
    for (; len != -1 && P[itP] != P[len]; len = len ? F[len - 1] : -1)
      ;
    F[itP] = ++len;
  }
}
bool KMP(vector<data> &P, vector<data> &T) {
  buildF(P);
  for (int itT = 0, itP = 0; itT < T.size(); itT++) {
    for (; itP != -1 && T[itT] != P[itP]; itP = itP ? F[itP - 1] : -1)
      ;
    if (P.size() == ++itP) {
      return true;
    }
  }
  return false;
}
vector<data> getData(vector<Point> &P) {
  int sz = P.size();
  vector<data> Data;
  for (int i = 0; i < sz; i++) {
    Data.push_back({norma(P[i] - P[(i + 1) % sz]),
                    norma(P[(i + 1) % sz] - P[(i + 2) % sz]),
                    norma(P[(i + 2) % sz] - P[i])});
  }
  return Data;
}
bool equals(vector<Point> v1, vector<Point> v2) {
  if (v1.size() != v2.size()) return false;
  if (v1.size() == 2) {
    return norma(v1[0] - v1[1]) == norma(v2[0] - v2[1]);
  }
  for (int i = 0; i < v1.size(); i++) {
    v2.push_back(v2[i]);
  }
  vector<data> P = getData(v1);
  vector<data> T = getData(v2);
  return KMP(P, T);
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<Point> P1(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &P1[i].x, &P1[i].y);
  }
  vector<Point> P2(m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &P2[i].x, &P2[i].y);
  }
  vector<Point> v1 = ConvexHull(P1);
  vector<Point> v2 = ConvexHull(P2);
  if (equals(v1, v2))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
