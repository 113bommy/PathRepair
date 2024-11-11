#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int u, v, next;
  long long s;
} edge[1000010];
int head[100010];
int pos;
void insert(int x, int y, long long s) {
  edge[pos].u = x;
  edge[pos].v = y;
  edge[pos].s = s;
  edge[pos].next = head[x];
  head[x] = pos++;
}
struct fff {
  long long s;
  int x, y;
  bool friend operator<(fff a, fff b) { return a.s > b.s; }
} o;
priority_queue<fff> Q;
int parent[100010];
int find(int x) {
  if (x != parent[x]) parent[x] = find(parent[x]);
  return parent[x];
}
long long dis[100010];
int belong[100010];
fff pp[100010];
int qq;
bool cmp(fff a, fff b) { return a.s < b.s; }
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  pos = 1;
  memset(head, 0, sizeof(head));
  for (int i = 0; i < m; i++) {
    int x, y;
    long long s;
    scanf("%d %d %I64d", &x, &y, &s);
    x--;
    y--;
    insert(x, y, s);
    insert(y, x, s);
  }
  while (!Q.empty()) Q.pop();
  int K;
  scanf("%d", &K);
  for (int i = 0; i < n; i++) dis[i] = (1LL) << 50;
  for (int i = 0; i < K; i++) {
    int x;
    scanf("%d", &x);
    x--;
    o.s = 0;
    o.x = x;
    dis[x] = 0;
    belong[x] = x;
    Q.push(o);
  }
  while (!Q.empty()) {
    int x = Q.top().x;
    Q.pop();
    for (int i = head[x]; i; i = edge[i].next) {
      int v = edge[i].v;
      if (dis[x] + edge[i].s < dis[v]) {
        dis[v] = dis[x] + edge[i].s;
        belong[v] = belong[x];
        o.s = dis[v];
        o.x = belong[v];
        Q.push(o);
      }
    }
  }
  qq = 0;
  for (int i = 1; i < pos; i += 2) {
    int x = edge[i].u;
    int y = edge[i].v;
    long long s = dis[x] + dis[y] + edge[i].s;
    x = belong[x];
    y = belong[y];
    pp[qq].x = x;
    pp[qq].y = y;
    pp[qq].s = s;
    qq++;
  }
  sort(pp, pp + qq, cmp);
  long long ans = dis[0];
  for (int i = 0; i < n; i++) parent[i] = i;
  for (int i = 0; i < qq; i++) {
    int x = pp[i].x;
    int y = pp[i].y;
    long long s = pp[i].s;
    int px = find(x);
    int py = find(y);
    if (px == py) continue;
    ans += s;
    if (rand() & 1)
      parent[px] = py;
    else
      parent[py] = px;
  }
  printf("%I64d\n", ans);
  return 0;
}
