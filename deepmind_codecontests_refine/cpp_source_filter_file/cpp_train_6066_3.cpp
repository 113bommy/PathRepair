#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:2048000000000000")
using namespace std;
struct point {
  long long x, y;
  long double len() { return sqrt((long double)(x * x + y * y)); }
  long long size() { return (x * x + y * y); }
  bool operator==(point p) { return (x == p.x && y == p.y); }
  long long rast(point p) {
    return ((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
  }
  point(long long new_x = -1e12, long long new_y = -1e12) {
    x = new_x;
    y = new_y;
  }
  friend bool operator<(point a, point p) {
    return (a.x < p.x || (a.x == p.x && a.y < p.y));
  }
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  long long operator*(point p) { return x * p.x + y * p.y; }
  point operator*(long long q) { return point(x * q, y * q); }
  long long operator^(point p) { return p.x * y - x * p.y; }
  point operator/(long long a) { return point(x / a, y / a); }
  friend istream &operator>>(istream &is, point &p) { return is >> p.x >> p.y; }
  friend ostream &operator<<(ostream &os, const point &p) {
    return os << p.x << " " << p.y;
  }
};
int main() {
  int t;
  cin >> t;
  for (int ii = 1; ii <= t; ii++) {
    point a[6];
    map<point, vector<int> > o;
    point obsh;
    for (int i = 0; i <= 5; i++) {
      cin >> a[i];
      o[a[i]].push_back(i / 2);
      if (o[a[i]].size() > 1) obsh = a[i];
    }
    point x, y;
    point a1, a2, b1, b2, c1, c2;
    if (obsh == point(-1e12, -1e12)) {
      cout << "NO" << endl;
      continue;
    }
    int x1 = o[obsh][0];
    bool b[3];
    b[0] = b[1] = b[2] = 1;
    b[x1] = 0;
    if (a[2 * x1 + 1] == obsh) swap(a[2 * x1 + 1], a[2 * x1]);
    x = a[2 * x1 + 1] - a[2 * x1];
    a1 = a[2 * x1], a2 = a[2 * x1 + 1];
    x1 = o[obsh][1];
    b[x1] = 0;
    if (a[2 * x1 + 1] == obsh) swap(a[2 * x1 + 1], a[2 * x1]);
    y = a[2 * x1 + 1] - a[2 * x1];
    b1 = a[2 * x1], b2 = a[2 * x1 + 1];
    long long pp1 = x * y, pp2 = x ^ y;
    if (pp1 < 0 || pp2 == 0) {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 0; i <= 2; i++)
      if (b[i]) x1 = i;
    c1 = a[2 * x1], c2 = a[2 * x1 + 1];
    point p1 = c1 - a1, p2 = c1 - a2;
    int bb = 0;
    long long gov, dno;
    gov = p1 ^ p2;
    dno = p1 * p2;
    if (gov == 0 && dno < 0) bb += 1;
    if (bb == 1 && (min(p1.size(), p2.size()) * ((long long)16) <
                    max(p1.size(), p2.size()))) {
      cout << "NO" << endl;
      continue;
    }
    p1 = c2 - a1, p2 = c2 - a2;
    gov = p1 ^ p2;
    dno = p1 * p2;
    if (gov == 0 && dno < 0) bb += 2;
    if (bb == 2 && (min(p1.size(), p2.size()) * ((long long)16) <
                    max(p1.size(), p2.size()))) {
      cout << "NO" << endl;
      continue;
    }
    if (bb == 0) {
      cout << "NO" << endl;
      continue;
    }
    bb = 0;
    p1 = c2 - b1, p2 = c2 - b2;
    gov = p1 ^ p2;
    dno = p1 * p2;
    if (gov == 0 && dno < 0) bb += 1;
    if (bb == 1 && (min(p1.size(), p2.size()) * ((long long)16) <
                    max(p1.size(), p2.size()))) {
      cout << "NO" << endl;
      continue;
    }
    p1 = c1 - b1, p2 = c1 - b2;
    gov = p1 ^ p2;
    dno = p1 * p2;
    if (gov == 0 && dno) bb += 2;
    if (bb == 2 && (min(p1.size(), p2.size()) * ((long long)16) <
                    max(p1.size(), p2.size()))) {
      cout << "NO" << endl;
      continue;
    }
    if (bb == 0) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
  }
}
