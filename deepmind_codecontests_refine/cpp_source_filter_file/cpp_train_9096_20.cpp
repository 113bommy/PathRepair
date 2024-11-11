#include <bits/stdc++.h>
using namespace std;
const int N = 20010, INF = 0x3f3f3f3f;
struct edge {
  int pos, nx, cap;
} e[N * 40];
int num, s, t, n, m, g;
int sum, head[N], cur[N], d[N];
bool mark[N], sex[N];
vector<int> graph[N];
void add(int u, int v, int c) {
  e[++num].pos = v;
  e[num].cap = c;
  e[num].nx = head[u];
  head[u] = num;
  e[++num].pos = u;
  e[num].cap = 0;
  e[num].nx = head[v];
  head[v] = num;
}
bool BFS() {
  queue<int> q;
  memcpy(cur, head, sizeof(cur));
  memset(d, 0, sizeof(d));
  q.push(s);
  d[s] = 1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = head[now]; i; i = e[i].nx) {
      if (e[i].cap && !d[e[i].pos]) {
        d[e[i].pos] = d[now] + 1;
        if (e[i].pos == t) return true;
        q.push(e[i].pos);
      }
    }
  }
  return false;
}
int finds(int now, int minx) {
  if (now == t) return minx;
  int ret;
  for (int &i = cur[now]; i; i = e[i].nx) {
    if (e[i].cap && d[e[i].pos] == d[now] + 1 &&
        (ret = finds(e[i].pos, min(minx, e[i].cap)))) {
      e[i].cap -= ret;
      e[i ^ 1].cap += ret;
      return ret;
    }
  }
  return 0;
}
int mincut() {
  int ans = 0, temp;
  while (BFS()) {
    while (temp = finds(s, INF)) {
      ans += temp;
    }
  }
  return ans;
}
int main() {
  int x, y, k, w, g;
  scanf("%d%d%d", &n, &m, &g);
  s = n + m + 1, t = n + m + 2, num = 1;
  for (int i = 1; i <= n; i++) scanf("%d", &sex[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (sex[i])
      add(i, t, x);
    else
      add(s, i, x);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &mark[i], &w, &k);
    for (int j = 1; j <= k; j++) {
      scanf("%d", &x);
      if (sex[x] ^ mark[i]) {
        if (mark[i])
          add(x, i + n, INF);
        else
          add(i + n, x, INF);
      }
      graph[x].push_back(i);
    }
    sum += w;
    scanf("%d", &x);
    if (x) w += g;
    if (mark[i])
      add(i + n, t, w);
    else
      add(s, i + n, w);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < graph[i].size(); j++)
      for (int l = j + 1; l < graph[i].size(); l++)
        if (mark[graph[i][l]] ^ mark[graph[i][j]])
          if (graph[i][l])
            add(graph[i][j] + n, graph[i][l] + n, INF);
          else
            add(graph[i][l] + n, graph[i][j] + n, INF);
  printf("%d\n", sum - mincut());
  return 0;
}
