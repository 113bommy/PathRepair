#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 * 1000;
const long long INF = 1LL << 60;
struct Point {
  long long x, y;
};
bool TestBit(long long use, int p) { return (use >> p) & 1; }
long long C[300 * 1000 + 10];
long long Abs(long long x) { return x > 0 ? x : -x; }
long long CalcPerimeter(vector<Point> &p) {
  long long res = 0;
  int np = p.size();
  long long x1 = p[0].x, x2 = p[0].x;
  long long y1 = p[0].y, y2 = p[0].y;
  for (int i = 0; i < np; ++i) {
    int j = (i + 1) % np;
    x1 = min(x1, p[i].x);
    x2 = max(x2, p[i].x);
    y1 = min(y1, p[i].y);
    y2 = max(y2, p[i].y);
  }
  return (x2 - x1) * 2 + (y2 - y1) * 2;
}
long long Opt = 0;
void Check(Point p1, Point p2, vector<Point> &v) {
  vector<Point> u(3);
  u[0] = p1;
  u[1] = p2;
  int nv = v.size();
  for (int i = 0; i < nv; ++i) {
    u[2] = v[i];
    long long cur = CalcPerimeter(u);
    Opt = max(cur, Opt);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  vector<Point> v(n);
  long long x1, y1, x2, y2;
  x1 = y1 = 1LL << 60;
  x2 = y2 = -(1LL << 60);
  for (int i = 0; i < n; ++i) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    x1 = min(x, x1);
    x2 = max(x, x2);
    y1 = min(y, y1);
    y2 = max(y, y2);
    Point p;
    p.x = x;
    p.y = y;
    v[i] = p;
  }
  long long ans = (x2 - x1) * 2 + (y2 - y1) * 2;
  for (int i = 0; i < n; ++i) {
    bool edgeX = (v[i].x == x1 || v[i].x == x2);
    bool edgeY = (v[i].y == y1 || v[i].y == y2);
    if (edgeX && edgeY) {
      Opt = ans;
      break;
    }
  }
  if (!Opt) {
    Point p1, p2;
    p1.x = x1;
    p1.y = -INF;
    p2.x = x2;
    p2.y = INF;
    for (int i = 0; i < n; ++i) {
      if (v[i].x == x1) p1.y = max(p1.y, v[i].y);
      if (v[i].x == x2) p2.y = min(p2.y, v[i].y);
    }
    Point q1, q2;
    q1.y = y1;
    q1.x = -INF;
    q2.y = y2;
    q2.x = INF;
    for (int i = 0; i < n; ++i) {
      if (v[i].y == y1) q1.x = max(q1.x, v[i].x);
      if (v[i].y == y2) q2.x = min(q2.x, v[i].x);
    }
    Check(p1, q1, v);
    Check(p1, q2, v);
    Check(p2, q1, v);
    Check(p2, q2, v);
  }
  cout << Opt;
  for (int i = 4; i <= n; ++i) {
    cout << " " << ans;
  }
  cout << endl;
  return 0;
}
