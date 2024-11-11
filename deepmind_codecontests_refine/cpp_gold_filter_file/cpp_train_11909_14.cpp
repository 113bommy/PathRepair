#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MODH = 998244353;
int No_intersection = 0;
int Sq_Area(int r) {
  int first = r + r;
  int sq_area = first * first;
  int ans = sq_area - acos(0.0) * 2.0 * r * r;
  return ans;
}
struct point {
  int x = 0.0, y = 0.0, z = 0.0;
  point() : x(0.0), y(0.0), z(0.0) {}
  point(int x1, int y1, int z1) : x(x1), y(y1), z(z1) {}
};
struct line {
  point start;
  point end;
  line(point a, point b) : start(a), end(b) {}
};
struct Circle {
  point O;
  int r;
  Circle(point x, int rad) : O(x), r(rad) {}
  Circle() : O({0, 0, 0}), r(0.0) {}
};
bool cmp(pair<point, int> a, pair<point, int> b) {
  return a.first.y > b.first.y;
}
int distance(point a, point b) {
  int ans = (((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)) +
             ((b.z - a.z) * (b.z - a.z)));
  return sqrt(ans);
}
int orientation(line a, point n) {
  int ans = (a.end.x - a.start.x) * (n.y - a.end.y) -
            (a.end.y - a.start.y) * (n.x - a.end.x);
  if (ans == 0)
    return 0;
  else if (ans < 0)
    return -1;
  else
    return 1;
}
bool valid_colinearity_intersection(point a, point b, point c) {
  if ((c.x >= a.x and c.x <= b.x) and (c.y >= a.y and c.y <= b.y)) return 1;
  return 0;
}
bool check_line_line_intersection(line a, line b) {
  int aa = orientation(a, b.start);
  int bb = orientation(a, b.end);
  int cc = orientation(b, a.start);
  int dd = orientation(b, a.end);
  if (aa != bb and cc != dd)
    return true;
  else {
    if (aa == 0 && valid_colinearity_intersection(a.start, a.end, b.start))
      return true;
    if (bb == 0 && valid_colinearity_intersection(a.start, a.end, b.end))
      return true;
    if (cc == 0 && valid_colinearity_intersection(b.start, b.end, a.start))
      return true;
    if (dd == 0 && valid_colinearity_intersection(b.start, b.end, a.end))
      return true;
  }
  return false;
}
bool check_collinearity_3_points(point a, point b, point c) {
  int res = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
  if (res == 0)
    return 1;
  else
    return 0;
}
point intersection_line_line(line a, line b) {
  int A1 = a.end.y - a.start.y;
  int A2 = b.end.y - b.start.y;
  int B1 = a.start.x - a.end.x;
  int B2 = b.start.x - b.end.x;
  int C1 = A1 * a.start.x + B1 * a.start.y;
  int C2 = A2 * b.start.x + B2 * b.start.y;
  int det = A1 * B2 - A2 * B1;
  if (det == 0) {
    No_intersection = 1;
    point ans(-1, -1, -1);
    return ans;
  }
  int x = (B2 * C1 - B1 * C2) / det;
  int y = (A1 * C2 - A2 * C1) / det;
  point ans(x, y, 0.0);
  return ans;
}
bool check_inside(point a, point l, point r) {
  if (a.x >= l.x and a.x <= r.x and a.y <= l.y and a.y >= r.y) return true;
  return false;
}
int area(int a, int b, int c) {
  if (a + b > c and a + c > b and b + c > a and a > 0 and b > 0 and c) {
    int tmp = (a + b + c) / 2.0;
    int res = sqrt(tmp * (tmp - a) * (tmp - b) * (tmp - c));
    return res;
  } else
    return 1.0 * INT_MIN;
}
int area_triangle(point a, point b, point c) {
  int ans = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
  return abs(ans);
}
point check(Circle A, Circle B) {
  double d = sqrt((B.O.x - A.O.x) * (B.O.x - A.O.x) +
                  (B.O.y - A.O.y) * (B.O.y - A.O.y));
  if (d <= A.r + B.r && d >= abs(B.r - A.r)) {
    double ex = (B.O.x - A.O.x) / d;
    double ey = (B.O.y - A.O.y) / d;
    double x = (A.r * A.r - B.r * B.r + d * d) / (2 * d);
    double y = sqrt(A.r * A.r - x * x);
    point P1, P2;
    P1.x = A.O.x + x * ex - y * ey;
    P1.y = A.O.y + x * ey + y * ex;
    P2.x = A.O.x + x * ex + y * ey;
    P2.y = A.O.y + x * ey - y * ex;
    if (P1.x > P2.x)
      return P1;
    else
      return P2;
  } else
    return {0, 0, 0};
}
long long dp[10][10];
long long solve(int i, int j) {
  if (i == 1 or j == 1)
    return dp[i][j] = abs(2 * i - 3 * j);
  else {
    long long sum = 0;
    if (dp[i][j] != -1) return dp[i][j];
    for (int l = 1; l <= i - 1; l++) {
      for (int k = 1; k <= j - 1; k++) {
        sum += (solve(l, k));
      }
    }
    return dp[i][j] = sum;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << -1;
    return 0;
  }
  vector<int> a, b, c;
  for (int i = 0; i < n; i++) {
    a.push_back(i);
    b.push_back(i);
    c.push_back((i + i) % n);
  }
  for (auto i : a) cout << i << ' ';
  cout << "\n";
  for (auto i : b) cout << i << ' ';
  cout << "\n";
  for (auto i : c) cout << i << ' ';
}
