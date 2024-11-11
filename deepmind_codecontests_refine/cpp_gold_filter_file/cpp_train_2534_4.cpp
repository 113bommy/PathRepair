#include <bits/stdc++.h>
const int N = 2010;
const int inf = 0x3f3f3f3f;
using namespace std;
struct node {
  int to, next;
} edge[N * 10];
int box[N], ecnt;
void _make_edge(int from, int to) {
  edge[ecnt].to = to;
  edge[ecnt].next = box[from];
  box[from] = ecnt++;
  return;
}
void make_edge(int from, int to) {
  _make_edge(from, to);
  _make_edge(to, from);
  return;
}
int dis[N];
void dfs(int u, int p) {
  dis[u] = 1;
  for (int i = box[u]; i + 1; i = edge[i].next) {
    int v = edge[i].to;
    if (p == v) continue;
    dfs(v, u);
    dis[u] += dis[v];
  }
  return;
}
struct point {
  int id;
  double x, y;
  point() {}
  point(double _x, double _y) : x(_x), y(_y) {}
  point operator-(const point &c) const { return point(x - c.x, y - c.y); }
  bool operator*(const point &c) const { return x * c.y >= y * c.x; }
} a[N], p0;
bool cmp(const point &a, const point &b) { return (a - p0) * (b - p0); }
bool cmpy(const point &a, const point &b) {
  if (a.y != b.y) return a.y < b.y;
  return a.x < b.x;
}
int ans[N];
void DFS(int u, int p, int n, point a[]) {
  sort(a, a + n, cmpy);
  ans[a[0].id] = u;
  p0 = a[0];
  sort(a + 1, a + n, cmp);
  int cnt = 1;
  for (int i = box[u]; i + 1; i = edge[i].next) {
    int v = edge[i].to;
    if (v == p) continue;
    DFS(v, u, dis[v], &a[cnt]);
    cnt += dis[v];
  }
  return;
}
int main() {
  int n;
  cin >> n;
  memset(box, -1, sizeof(box));
  ecnt = 0;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    make_edge(a, b);
  }
  for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y, a[i].id = i + 1;
  dfs(1, 1);
  DFS(1, 1, n, a);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
