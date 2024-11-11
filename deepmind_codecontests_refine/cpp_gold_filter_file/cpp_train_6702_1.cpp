#include <bits/stdc++.h>
using namespace std;
struct node {
  double x, y;
} p[405];
int head[805], nxt[400005], v[400005], tot = 1, st, ed;
double cost[400005], w[400005], d[805];
int id[805], pre[805];
bool vis[805];
double maxf = 0, cst = 0;
inline bool cmp(node a, node b) { return a.y > b.y; }
inline double dis(int a, int b) {
  return sqrt((p[a].x - p[b].x) * (p[a].x - p[b].x) +
              (p[a].y - p[b].y) * (p[a].y - p[b].y));
}
inline void add(int a, int b, double capa, double cos) {
  tot++;
  nxt[tot] = head[a];
  head[a] = tot;
  v[tot] = b;
  w[tot] = capa;
  cost[tot] = cos;
}
inline bool spfa() {
  int i;
  for (i = 1; i <= ed; i++) {
    d[i] = 1e18;
    vis[i] = 0;
  }
  d[st] = 0;
  queue<int> q;
  q.push(st);
  vis[st] = 1;
  while (!q.empty()) {
    int t = q.front();
    vis[t] = 0;
    q.pop();
    for (i = head[t]; i; i = nxt[i]) {
      if (w[i] > 1e-12 && d[v[i]] > d[t] + cost[i]) {
        d[v[i]] = d[t] + cost[i];
        pre[v[i]] = t;
        id[v[i]] = i;
        if (!vis[v[i]]) {
          vis[v[i]] = 1;
          q.push(v[i]);
        }
      }
    }
  }
  if (d[ed] < 100000000) {
    return true;
  }
  return false;
}
inline void adjust() {
  int i;
  double minf = 1000000000.00;
  for (i = ed; i != st; i = pre[i]) {
    if (w[id[i]] < minf) {
      minf = w[id[i]];
    }
  }
  maxf += minf;
  for (i = ed; i != st; i = pre[i]) {
    w[id[i]] -= minf;
    w[id[i] ^ 1] += minf;
    cst += minf * cost[id[i]];
  }
}
int main() {
  int i, j, n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
  }
  sort(p + 1, p + n + 1, cmp);
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      if (p[i].y > p[j].y + 1e-12) {
        add(i, j + n, 1, dis(i, j));
        add(j + n, i, 0, -dis(i, j));
      }
    }
  }
  st = 2 * n + 1;
  ed = 2 * n + 2;
  for (i = 1; i <= n; i++) {
    add(st, i, 2, 0);
    add(i, st, 0, 0);
    add(i + n, ed, 1, 0);
    add(ed, i + n, 0, 0);
  }
  while (spfa()) {
    adjust();
  }
  if (fabs(maxf - n + 1) > 1e-12) {
    printf("-1\n");
  } else {
    printf("%.10lf\n", cst);
  }
  return 0;
}
