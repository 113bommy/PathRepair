#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long x;
  long long y;
  bool operator==(const Point& otherP) {
    return x == otherP.x && y == otherP.y;
  }
  Point operator-(const Point& other) {
    return Point{x - other.x, y - other.y};
  }
  Point operator+(const Point& other) {
    return Point{x + other.x, y + other.y};
  }
};
long long cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
long long cross(long long x1, long long y1, long long x2, long long y2) {
  return x1 * y2 - x2 * y1;
}
long long cross3(int i, int j, int k, Point* mountains) {
  return cross(mountains[j].x - mountains[i].x, mountains[j].y - mountains[i].y,
               mountains[k].x - mountains[i].x,
               mountains[k].y - mountains[i].y);
}
int main() {
  int n;
  cin >> n;
  auto* mountains = new Point[n];
  for (int i = 0; i < n; i++) cin >> mountains[i].x >> mountains[i].y;
  unsigned int maxDepth = 0;
  while (1u << (maxDepth + 1) <= n - 1) maxDepth++;
  int* depth = new int[n];
  for (unsigned int j = 0u; j < n; j++) depth[j] = 0;
  int** tree = new int*[maxDepth + 1];
  for (unsigned int i = 0u; i < maxDepth + 1; i++) {
    tree[i] = new int[n];
    for (unsigned int j = 0u; j < n; j++) tree[i][j] = 0;
  }
  int* indices = new int[n];
  indices[0] = n - 1;
  int cnt = 1;
  for (int i = n - 2; i >= 0; i--) {
    while (cnt >= 2 &&
           cross3(indices[cnt - 2], indices[cnt - 1], i, mountains) < 0)
      cnt--;
    depth[i] = depth[indices[cnt - 1] + 1];
    tree[0][i] = indices[cnt - 1];
    for (unsigned int j = 1; j <= maxDepth; j++)
      tree[j][i] = tree[j - 1][tree[j - 1][i]];
    indices[cnt] = i;
    cnt++;
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (depth[x] < depth[y]) swap(x, y);
    for (int j = maxDepth; j >= 0; j--)
      if ((1u << j) <= depth[x] - depth[y]) x = tree[j][x];
    int a = x;
    if (x != y) {
      for (int j = maxDepth; j >= 0; j--) {
        if ((1u << j) <= depth[x] && tree[j][x] != tree[j][y]) {
          x = tree[j][x];
          y = tree[j][y];
        }
      }
      a = tree[0][x];
    }
    cout << a + 1 << " ";
  }
  cout << endl;
}
