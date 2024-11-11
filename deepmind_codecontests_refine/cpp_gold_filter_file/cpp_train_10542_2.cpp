#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 510;
int n, m;
int num[MAX_N][MAX_N];
long long area[MAX_N][MAX_N];
struct Point {
  int x, y;
  Point() {}
  Point(int _x, int _y) : x(_x), y(_y) {}
  void input() { scanf("%d%d", &x, &y); }
  bool operator<(const Point& rhs) const {
    if (y != rhs.y) return y < rhs.y;
    return x < rhs.x;
  }
  Point operator-(const Point& rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  long long operator*(const Point& rhs) const {
    long long ret = 1ll * x * rhs.y - 1ll * y * rhs.x;
    return ret;
  }
  long long cross(const Point& rhs) const {
    long long ret = 1ll * x * rhs.y - 1ll * y * rhs.x;
    if (ret < 0) ret = -ret;
    return ret;
  }
} P[MAX_N], Q[MAX_N];
inline long long Cross(Point a, Point b) {
  long long ret = 1ll * a.x * b.y - 1ll * a.y * b.x;
  if (ret < 0) ret = -ret;
  return ret;
}
inline int In(int i, int j, Point d) {
  Point a = P[0], b = P[i], c = P[j];
  long long ret = (a - d) * (b - d) + (a - d) * (c - d) + (b - d) * (c - d);
  return area[i][j] == ret;
}
void solve() {
  Point ori = Point((long long)(1e9) + 1, (long long)(1e9) + 1);
  memset(num, 0, sizeof(num));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((P[i] - ori) * (P[j] - ori) <= 0) continue;
      for (int k = 0; k < m; ++k) {
        if ((P[i] - ori) * (Q[k] - ori) >= 0 &&
            (ori - P[j]) * (Q[k] - P[j]) > 0 &&
            (P[j] - P[i]) * (Q[k] - P[i]) > 0)
          num[i][j]++;
      }
      num[j][i] = -num[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (num[i][j] + num[j][k] + num[k][i] == 0) ans++;
      }
    }
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) P[i].input();
  for (int i = 0; i < m; ++i) Q[i].input();
  solve();
  return 0;
}
