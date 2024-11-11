#include <bits/stdc++.h>
using namespace std;
class Point {
 public:
  int x;
  int y;
  Point(int x, int y) : x(x), y(y) {}
};
class Ops {
 public:
  int t;
  int i;
  int j;
  Ops(int t, int i, int j) : t(t), i(i), j(j) {}
};
void gao(vector<Point> &v, vector<Ops> &ops, int n) {
  while (!v.empty()) {
    vector<bool> flag(n + 1, false);
    bool rflag = true;
    for (int i = 0; i < v.size(); i++) {
      flag[v[i].y] = true;
      if (v[i].x == n) {
        rflag = false;
      }
    }
    if (flag[n]) {
      int index = 1;
      while (flag[index]) {
        index++;
      }
      ops.push_back(Ops(2, index, n));
      for (int i = 0; i < v.size(); i++) {
        if (v[i].y == n) {
          v[i].y = index;
        }
      }
    }
    int x;
    if (rflag) {
      int x = v[0].x;
      ops.push_back(Ops(1, x, n));
    } else {
      x = n;
    }
    vector<Point>::iterator iter = v.begin();
    while (iter != v.end()) {
      if ((*iter).x == x) {
        iter = v.erase(iter);
      } else {
        iter++;
      }
    }
    n--;
  }
  return;
}
int main() {
  int n;
  cin >> n;
  vector<Point> v;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back(Point(x, y));
  }
  vector<Ops> ops;
  gao(v, ops, n);
  cout << ops.size() << endl;
  for (int i = 0; i < ops.size(); i++) {
    cout << ops[i].t << ' ' << ops[i].i << ' ' << ops[i].j << endl;
  }
  return 0;
}
