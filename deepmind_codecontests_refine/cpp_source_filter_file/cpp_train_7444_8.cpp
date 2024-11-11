#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
int n, p, q;
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) { x = _x, y = _y; }
};
Point arr[100011];
Point PreTopStack(stack<Point> &t) {
  Point p = t.top();
  t.pop();
  Point res = t.top();
  t.push(p);
  return res;
}
long long orientation(Point a, Point b, Point c) {
  long long res = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
  return res;
}
long long dis(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool cmp(Point a, Point b) {
  if (a.x == b.x && b.y == a.y) return 0;
  long long res = orientation(arr[0], a, b);
  if (res == 0) {
    if (dis(a, arr[0]) <= dis(b, arr[0])) return 1;
    return 0;
  }
  return res < 0 ? 1 : 0;
}
vector<Point> ans;
void Convex_Hull() {
  long long my = arr[0].y, min = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i].y < my || (arr[i].y == my && arr[i].x < arr[min].x)) {
      min = i;
      my = arr[i].y;
    }
  }
  swap(arr[0], arr[min]);
  sort(arr + 1, arr + n, cmp);
  stack<Point> st;
  st.push(arr[0]);
  for (int i = 1; i < n; i++) {
    while ((int)st.size() >= 2 &&
           orientation(PreTopStack(st), st.top(), arr[i]) >= 0) {
      st.pop();
    }
    st.push(arr[i]);
  }
  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  if (ans.size() == 0) return;
}
int intersect_line(Point a, Point b, Point c, Point d, Point *p) {
  Point t;
  double r, s, denom, num1, num2;
  num1 = (a.y - c.y) * (d.x - c.x) - (a.x - c.x) * (d.y - c.y);
  num2 = (a.y - c.y) * (b.x - a.x) - (a.x - c.x) * (b.y - a.y);
  denom = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
  if (fabs(denom) >= 1e-8) {
    r = num1 / denom;
    s = num2 / denom;
    if (0 - 1e-8 <= r && r <= 1 + 1e-8 && 0 - 1e-8 <= s && s <= 1 + 1e-8) {
      p->x = a.x + r * (b.x - a.x);
      p->y = a.y + r * (b.y - a.y);
      return 1;
    }
    return 0;
  }
  if (fabs(num1) >= 1e-8) return 0;
  if (a.x > b.x || (a.x == b.x && a.y > b.y)) {
    t = a;
    a = b;
    b = t;
  }
  if (c.x > d.x || (c.x == d.x && c.y > d.y)) {
    t = c;
    c = d;
    d = t;
  }
  if (a.x == b.x) {
    if (b.y == c.y) {
      *p = b;
      return 1;
    } else if (a.y == d.y) {
      *p = a;
      return 1;
    } else if (b.y < c.y || d.y < a.y)
      return 0;
  } else {
    if (b.x == c.x) {
      *p = b;
      return 1;
    } else if (a.x == d.x) {
      *p = a;
      return 1;
    } else if (b.x < c.x || d.x < a.x)
      return 0;
  }
  return -1;
}
vector<Point> Inter;
int main() {
  cin >> n >> p >> q;
  double maxiX = 0, maxiY = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].x >> arr[i].y;
    maxiX = max(maxiX, arr[i].y);
    maxiY = max(maxiY, arr[i].y);
  }
  arr[n++] = Point(maxiX, 0);
  arr[n++] = Point(0, maxiY);
  Convex_Hull();
  double m = double(q) / double(p);
  double A = 10000000, B = A * m;
  for (int i = 0; i < ans.size(); i++) {
    Point a = ans[i], b = ans[(i + 1) % ans.size()], c = Point(0, 0),
          d = Point(A, B), e;
    int res = intersect_line(a, b, c, d, &e);
    if (res <= 0) continue;
    Inter.push_back(e);
  }
  double ansx = 1.;
  if (Inter.size() > 1) {
    if (Inter[0].x > Inter[1].x ||
        (Inter[0].x == Inter[1].x && Inter[0].y > Inter[1].y))
      swap(Inter[0], Inter[1]);
    ansx = max(p / Inter[1].x, q / Inter[1].y);
  }
  printf("%.20lf\n", ansx);
  return 0;
}
