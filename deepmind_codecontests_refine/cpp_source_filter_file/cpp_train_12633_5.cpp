#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator+(point a) { return point(x + a.x, y + a.y); }
  point operator-(point a) { return point(x - a.x, y - a.y); }
  point operator*(double a) { return point(x * a, y * a); }
  point operator&(point a) {
    return point(x * a.x - y * a.y, x * a.y + y * a.x);
  }
  double nor() { return sqrtl(*this * *this); }
  double operator*(point a) { return x * a.x + y * a.y; }
};
int main() {
  int n;
  cin >> n;
  point p[5];
  double pi = acosl(-1.0);
  double al = pi * 36 / 180;
  p[0] = point(-cosl(al) * 20, 0);
  for (int i = 1; i < 5; i++)
    p[i] = (p[i - 1] & point(cosl(pi - al), sinl(pi - al)));
  vector<point> po;
  po.push_back(0);
  int cur = 0;
  vector<vector<int> > pentagon(n);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) po.push_back(po.back() + p[j + 1]);
    pentagon[i].push_back(cur);
    pentagon[i].push_back(cur + 3);
    pentagon[i].push_back(cur + 1);
    pentagon[i].push_back(cur + 4);
    pentagon[i].push_back(cur + 2);
    cur += 4;
  }
  for (int i = 0; i <= cur; i++) ans.push_back(i);
  while (ans.back()) ans.push_back(ans.back() - 4);
  cout << fixed << setprecision(20);
  cout << cur << endl;
  for (point a : po) cout << a.x << ' ' << a.y << endl;
  for (vector<int> a : pentagon) {
    for (int id : a) cout << id + 1 << ' ';
    cout << endl;
  }
  for (int r : ans) cout << r + 1 << ' ';
  cout << endl;
  return 0;
}
