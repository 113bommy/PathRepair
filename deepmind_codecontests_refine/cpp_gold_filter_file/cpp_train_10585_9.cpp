#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto x : v) os << x << ' ';
  os << '\n';
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  os << '\n';
  return os;
}
const char *fin = "";
const char *fon = "";
const int OO = (int)(1e9 + 7);
const int MAXN = (int)(0);
struct Point {
  int x, y;
  Point() {}
  Point(int _x, int _y) : x(_x), y(_y) {}
};
struct Square {
  Point p[5];
  int S;
  Square() {}
  void init() {
    S = 0;
    for (int i = 1; i <= 4; ++i) cin >> p[i].x >> p[i].y;
    p[0] = p[4];
    for (int i = 0; i < 4; ++i)
      S += (p[i].x - p[i + 1].x) * (p[i].y + p[i + 1].y);
    S = abs(S);
  }
  bool inside(Point a) {
    int SS = 0;
    for (int i = 0; i < 4; ++i) {
      int S1 = 0;
      S1 += (p[i].x - a.x) * (p[i].y + a.y);
      S1 += (a.x - p[i + 1].x) * (a.y + p[i + 1].y);
      S1 += (p[i + 1].x - p[i].x) * (p[i + 1].y + p[i].y);
      SS += abs(S1);
    }
    return SS == S;
  }
};
Square A, B;
void Sol() {
  for (int i = -100; i <= 100; ++i)
    for (int j = -100; j <= 100; ++j)
      if (A.inside(Point(i, j)) && B.inside(Point(i, j))) {
        cout << "YES";
        return;
      }
  cout << "NO";
}
void Inp() {
  A.init();
  B.init();
  Sol();
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Inp();
  return 0;
}
