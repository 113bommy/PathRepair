#include <bits/stdc++.h>
using namespace std;
const int inf = 1e15;
const int maxn = 1e5 + 5;
int N, M, u, v, w;
struct edge {
  int v, nxt, w;
} e[4 * maxn];
int head[maxn], tot = 1;
void addEdge(int &u, int &v, int &w) {
  e[tot].v = v;
  e[tot].w = w;
  e[tot].nxt = head[u];
  head[u] = tot;
  tot++;
}
long long dis[maxn], path[maxn];
bool vis[maxn];
priority_queue<pair<long long, long long> > q;
void dij() {
  for (int i = 1; i <= N; i++) {
    dis[i] = inf;
    vis[i] = 0;
  }
  dis[1] = 0;
  q.push(make_pair(0, 1));
  while (q.size()) {
    int now = q.top().second;
    q.pop();
    if (vis[now] == 1) continue;
    vis[now] = 1;
    for (int i = head[now]; i; i = e[i].nxt) {
      int nxt = e[i].v, w = e[i].w;
      if (dis[nxt] > dis[now] + w) {
        dis[nxt] = dis[now] + w;
        q.push(make_pair(-dis[nxt], nxt));
        path[nxt] = now;
      }
    }
  }
}
int cnt = 0, flag = 0;
long long ans[maxn];
void printPath() {
  for (int i = N; i; i = path[i]) {
    ans[++cnt] = i;
    if (i == 1) {
      flag = 1;
    }
  }
  if (flag == 1) {
    for (int i = cnt; i >= 1; i--) printf("%d ", ans[i]);
  } else
    printf("-1");
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d %d %d", &u, &v, &w);
    addEdge(u, v, w);
    addEdge(v, u, w);
  }
  dij();
  printPath();
  return 0;
}
