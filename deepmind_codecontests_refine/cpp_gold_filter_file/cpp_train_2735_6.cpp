#include <bits/stdc++.h>
using namespace std;
int n, m, d[200005], v[200005];
int sx, sy, ex, ey;
struct node {
  int x, y, op;
} a[200005];
bool cmp1(node x, node y) { return x.x < y.x; }
bool cmp2(node x, node y) { return x.y < y.y; }
int h[200005], tot;
struct edge {
  int to, nxt, val;
} e[200005 << 2];
void add(int x, int y, int z) {
  e[++tot].nxt = h[x];
  h[x] = tot;
  e[tot].to = y;
  e[tot].val = z;
}
priority_queue<pair<int, int> > q;
void dij() {
  memset(d, 0x7f, sizeof(d));
  d[0] = 0;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    int x = q.top().second;
    q.pop();
    v[x] = 1;
    for (int i = h[x]; i; i = e[i].nxt) {
      if (d[e[i].to] > d[x] + e[i].val) {
        d[e[i].to] = d[x] + e[i].val;
        q.push(make_pair(-d[e[i].to], e[i].to));
      }
    }
    while (!q.empty() && v[q.top().second]) q.pop();
  }
  printf("%d\n", d[m + 1]);
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
  for (int i = 1; i <= m; i++) scanf("%d%d", &a[i].x, &a[i].y), a[i].op = i;
  for (int i = 1; i <= m; i++)
    add(0, i, min(abs(sx - a[i].x), abs(sy - a[i].y))),
        add(i, m + 1, abs(ex - a[i].x) + abs(ey - a[i].y));
  add(0, m + 1, abs(sx - ex) + abs(sy - ey));
  sort(a + 1, a + m + 1, cmp1);
  for (int i = 1; i <= m - 1; i++)
    add(a[i].op, a[i + 1].op, a[i + 1].x - a[i].x),
        add(a[i + 1].op, a[i].op, a[i + 1].x - a[i].x);
  sort(a + 1, a + m + 1, cmp2);
  for (int i = 1; i <= m - 1; i++)
    add(a[i].op, a[i + 1].op, a[i + 1].y - a[i].y),
        add(a[i + 1].op, a[i].op, a[i + 1].y - a[i].y);
  return dij(), 0;
}
