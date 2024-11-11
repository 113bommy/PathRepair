#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * asin(1.0);
const int INF = 1000000000;
const double EPS = 1e-10;
inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
struct point {
  double x, y;
  point(double _x = 0.0, double _y = 0.0) {
    x = _x;
    y = _y;
  }
};
bool operator<(const point lhs, const point rhs) {
  if (cmp(lhs.x - rhs.x) != 0) return lhs.x < rhs.x;
  return lhs.y < rhs.y;
}
double dot(point a, point b, point c) {
  return ((b.x - a.x) * (c.x - b.x) + (b.y - a.y) * (c.y - b.y));
}
double cross(point a, point b, point c) {
  return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}
bool collinear(point a, point b, point c) { return cmp(cross(a, b, c)) == 0; }
bool left(point a, point b, point c) { return cmp(cross(a, b, c)) > 0; }
const int MAXN = 30004;
int pd[MAXN][600];
char gems[MAXN];
int d, n;
int solve(int x, int y) {
  if (d + y <= 0) return 0;
  if (x >= MAXN) return 0;
  if (pd[x][300 + y] == -1) {
    int res = max(solve(x + d + y + 1, y + 1),
                  max(solve(x + d + y, y), solve(x + d + y - 1, y - 1)));
    res += gems[x];
    pd[x][300 + y] = res;
  }
  return pd[x][300 + y];
}
int main() {
  while (cin >> n >> d) {
    memset(gems, 0, sizeof gems);
    memset(pd, -1, sizeof pd);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      gems[x]++;
    }
    int res = solve(d, 0);
    cout << res << endl;
  }
}
