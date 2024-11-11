#include <bits/stdc++.h>
using namespace std;
int n, m, k, s;
int kind[100010];
struct Edge {
  int to, w, next;
} edge[400010];
int head[100110];
int dis[100110];
bool inq[100110];
int cnt = 1;
int ans[100010][110];
int now[100010];
void add(int u, int v, int w) {
  edge[cnt].to = v;
  edge[cnt].w = w;
  edge[cnt].next = head[u];
  head[u] = cnt++;
}
queue<int> q;
void spfa(int s) {
  memset(dis, 0x3f, sizeof(dis));
  memset(inq, 0, sizeof(inq));
  dis[s] = 0;
  q.push(s);
  inq[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = 0;
    for (register int i = head[u]; i; i = edge[i].next) {
      if (edge[i].to != s && edge[i].to > n) {
        continue;
      }
      int v = edge[i].to, w = edge[i].w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (!inq[v]) {
          q.push(v);
          inq[v] = 1;
        }
      }
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &kind[i]);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v, 1);
    add(v, u, 1);
  }
  for (int i = 1; i <= n; i++) {
    add(n + kind[i], i, 0);
    add(i, n + kind[i], 0);
  }
  for (int i = n + 1; i <= n + k; i++) {
    spfa(i);
    for (int j = 1; j <= n; j++) {
      ans[j][i - n] = dis[j];
    }
  }
  for (int i = 1; i <= n; i++) {
    int res = 0;
    for (int j = 1; j <= k; j++) {
      now[j] = ans[i][j];
    }
    sort(now + 1, now + k + 1);
    for (int j = 1; j <= s; j++) {
      res += now[j];
    }
    printf("%d ", res);
  }
  return 0;
}
