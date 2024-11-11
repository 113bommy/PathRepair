#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int t, f, next;
  Edge() {}
  Edge(int a, int b, int c) : t(a), f(b), next(c) {}
};
Edge e[2000000];
int head[2005], vs, vt, tot = -1;
void addEdge(int x, int y, int z) {
  e[++tot] = Edge(y, z, head[x]);
  head[x] = tot;
  e[++tot] = Edge(x, 0, head[y]);
  head[y] = tot;
}
namespace Flow {
int d[2005], cur[2005];
queue<int> q;
bool bfs() {
  while (!q.empty()) q.pop();
  memset(d, 255, sizeof(d));
  d[vs] = 0;
  cur[vs] = head[vs];
  q.push(vs);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i != -1; i = e[i].next)
      if (e[i].f && d[e[i].t] == -1) {
        int u = e[i].t;
        d[u] = d[x] + 1;
        cur[u] = head[u];
        if (u == vt) return 1;
        q.push(u);
      }
  }
  return 0;
}
int dfs(int x, int a) {
  if (x == vt || !a) return a;
  int ans = 0;
  for (int &i = cur[x]; i != -1; i = e[i].next)
    if (e[i].f && d[e[i].t] == d[x] + 1) {
      int u = e[i].t;
      int f = dfs(u, min(a, e[i].f));
      if (f) {
        e[i].f -= f;
        e[i ^ 1].f += f;
        ans += f;
        a -= f;
        if (!a) break;
      }
    }
  return ans;
}
int maxflow() {
  int ans = 0;
  while (bfs()) ans += dfs(vs, 0x3f3f3f3f);
  bfs();
  return ans;
}
}  // namespace Flow
struct Point {
  int x, y;
  bool v;
  Point() {}
  Point(int a, int b, bool c) : x(a), y(b), v(c) {}
};
struct Line {
  Point l, r;
  Line() {}
  Line(Point a, Point b) : l(a), r(b) {}
};
int num[2005];
Point p[1005];
vector<Point> row[2005], col[2005];
Line rl[2005], cl[2005];
bool cmp1(Point x, Point y) { return x.y < y.y; }
bool cmp2(Point x, Point y) { return x.x < y.x; }
int main() {
  memset(head, 255, sizeof(head));
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = Point(x, y, 0);
    num[++cnt] = x;
    num[++cnt] = y;
  }
  sort(num + 1, num + cnt + 1);
  cnt = unique(num + 1, num + cnt + 1) - num - 1;
  for (int i = 1; i <= n; i++) {
    p[i].x = lower_bound(num + 1, num + cnt + 1, p[i].x) - num;
    p[i].y = lower_bound(num + 1, num + cnt + 1, p[i].y) - num;
    row[p[i].x].push_back(p[i]);
    col[p[i].y].push_back(p[i]);
  }
  for (int i = 1; i <= cnt; i++) sort(row[i].begin(), row[i].end(), cmp1);
  for (int i = 1; i <= cnt; i++) sort(col[i].begin(), col[i].end(), cmp2);
  int s1 = 0, s2 = 0;
  for (int i = 1; i <= cnt; i++)
    if (row[i].size() > 1) {
      for (int j = 0; j < row[i].size() - 1; j++)
        rl[++s1] = Line(row[i][j], row[i][j + 1]);
    }
  for (int i = 1; i <= cnt; i++)
    if (col[i].size() > 1) {
      for (int j = 0; j < col[i].size() - 1; j++)
        cl[++s2] = Line(col[i][j], col[i][j + 1]);
    }
  vs = 0;
  vt = s1 + s2 + 1;
  for (int i = 1; i <= s1; i++) addEdge(vs, i, 1);
  for (int i = 1; i <= s2; i++) addEdge(s1 + i, vt, 1);
  for (int i = 1; i <= s1; i++)
    for (int j = 1; j <= s2; j++)
      if (rl[i].l.y < cl[j].l.y && rl[i].r.y > cl[j].l.y &&
          cl[j].l.x < rl[i].l.x && cl[j].r.x > rl[i].l.x)
        addEdge(i, s1 + j, 1);
  Flow::maxflow();
  int sz1 = n, sz2 = n;
  for (int i = 1; i <= s1; i++)
    if (Flow::d[i] != -1) {
      int x = rl[i].l.x;
      for (int j = 0; j < row[x].size(); j++)
        if (row[x][j].y == rl[i].l.y) row[x][j].v = 1;
      sz1--;
    }
  for (int i = 1; i <= s2; i++)
    if (Flow::d[s1 + i] == -1) {
      int x = cl[i].l.y;
      for (int j = 0; j < col[x].size(); j++)
        if (col[x][j].x == cl[i].l.x) col[x][j].v = 1;
      sz2--;
    }
  printf("%d\n", sz2);
  for (int i = 1; i <= cnt; i++)
    if (col[i].size()) {
      int last2 = -1;
      for (int j = 0; j < col[i].size(); j++)
        if (!col[i][j].v) {
          printf("%d %d %d %d\n", num[col[i][last2 + 1].x],
                 num[col[i][last2 + 1].y], num[col[i][j].x], num[col[i][j].y]);
          last2 = j;
        }
    }
  printf("%d\n", sz1);
  for (int i = 1; i <= cnt; i++)
    if (row[i].size()) {
      int last2 = -1;
      for (int j = 0; j < row[i].size(); j++)
        if (!row[i][j].v) {
          printf("%d %d %d %d\n", num[row[i][last2 + 1].x],
                 num[row[i][last2 + 1].y], num[row[i][j].x], num[row[i][j].y]);
          last2 = j;
        }
    }
  return 0;
}
