#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1500 + 100;
vector<int> edges[MAXN];
int d[MAXN];
bool mark[MAXN];
int Ox, Oy;
int VP(int x1, int y1, int x2, int y2) {
  return (long long)x1 * (long long)y2 - (long long)x2 * (long long)y1 > 0LL
             ? 1
             : -1;
}
struct Point {
 public:
  int x, y, id;
  Point() {}
  Point(int id, int x, int y) {
    this->id = id;
    this->x = x;
    this->y = y;
  }
  bool operator<(const Point &P) const {
    return VP(this->x - Ox, this->y - Oy, P.x - Ox, P.y - Oy) < 0;
  }
};
vector<Point> points;
int ans[MAXN];
void join(int u, Point p) { ans[p.id] = u; }
void solve(int u, vector<Point> points, Point P, bool b = false) {
  for (int i = 0; i < points.size(); i++) {
    if (points[i].y < points[0].y ||
        (points[i].y == points[0].y && points[i].x < points[0].x)) {
      swap(points[i], points[0]);
    }
  }
  mark[u] = true;
  int it = 0;
  join(u, points[it]);
  Point T = points[it];
  points.erase(points.begin() + it);
  if (points.size() == 0) return;
  Ox = T.x;
  Oy = T.y;
  sort(points.begin(), points.end());
  int tot = 0;
  for (int i = 0; i < edges[u].size(); i++) {
    int v = edges[u][i];
    if (mark[v]) continue;
    vector<Point> tmp;
    int t = 0;
    for (int j = tot; j < points.size(); j++) {
      tmp.push_back(points[j]);
      t++;
      if (t == d[v]) break;
    }
    tot += t;
    solve(v, tmp, T, true);
  }
}
void dfs(int u) {
  mark[u] = true;
  d[u] = 1;
  for (int i = 0; i < edges[u].size(); i++) {
    int v = edges[u][i];
    if (!mark[v]) {
      dfs(v);
      d[u] += d[v];
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  memset(d, 0, sizeof(d));
  memset(mark, false, sizeof(mark));
  dfs(0);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    points.push_back(Point(i, x, y));
  }
  memset(mark, false, sizeof(mark));
  solve(0, points, Point());
  for (int i = 0; i < n; i++) printf("%d ", ans[i] + 1);
  printf("\n");
  return 0;
}
