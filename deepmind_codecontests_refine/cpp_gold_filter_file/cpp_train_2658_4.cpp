#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
struct node {
  long long x, y;
  bool operator<(const node &a) const {
    return x < a.x || (x == a.x && y < a.y);
  }
} Point[maxn];
map<node, int> M;
bool cmp(node a, node b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> Point[i].x >> Point[i].y;
    ++M[Point[i]];
  }
  Point[n].x = Point[n].y = 0x3f3f3f3f;
  sort(Point, Point + n);
  long long ans = 0;
  long long tmp = 1;
  for (int i = 1; i <= n; i++) {
    if (Point[i].x == Point[i - 1].x)
      ++tmp;
    else {
      ans += tmp * (tmp - 1) / 2;
      tmp = 1;
    }
  }
  sort(Point, Point + n, cmp);
  tmp = 1;
  for (int i = 1; i <= n; i++) {
    if (Point[i].y == Point[i - 1].y)
      ++tmp;
    else {
      ans += tmp * (tmp - 1) / 2;
      tmp = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    long long t = M[Point[i - 1]];
    if (t > 1 && (Point[i - 1].x != Point[i].x || Point[i - 1].y != Point[i].y))
      ans -= t * (t - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
