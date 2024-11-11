#include <bits/stdc++.h>
using namespace std;
const int maxn = 405;
const double eps = 1e-6;
const int inf = 1e9;
const long long int INF = 1e15;
int cnt;
int n, m;
int vis[maxn][maxn];
int pre1[maxn * maxn / 2][5], pre2[maxn * maxn / 2][5];
struct node {
  int to, w, next;
} s[maxn * maxn / 2];
int head[maxn];
void add(int u, int v) {
  s[cnt].to = v;
  s[cnt].w = 1;
  s[cnt].next = head[u];
  head[u] = cnt++;
}
int dis[maxn], vv[maxn];
void spfa() {
  queue<int> q;
  for (int i = 1; i <= n; i++) dis[i] = inf;
  dis[1] = 0;
  vv[1] = 1;
  q.push(1);
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    vv[k] = 0;
    for (int i = head[k]; i != -1; i = s[i].next) {
      int p = s[i].to;
      if (dis[p] > dis[k] + s[i].w) {
        dis[p] = dis[k] + s[i].w;
        if (!vv[p]) {
          vv[p] = 1;
          q.push(m);
        }
      }
    }
  }
  if (dis[n] == inf)
    printf("-1\n");
  else
    printf("%d\n", max(dis[n], 1));
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    pre1[i][0] = u;
    pre1[i][1] = v;
    vis[u][v] = vis[v][u] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!vis[i][j]) {
        pre2[ans][0] = i;
        pre2[ans][1] = j;
        ans++;
      }
    }
  }
  cnt = 0;
  memset(head, -1, sizeof(head));
  if (!vis[1][n]) {
    for (int i = 0; i < m; i++) {
      add(pre1[i][0], pre1[i][1]);
      add(pre1[i][1], pre1[i][0]);
    }
  } else {
    for (int i = 0; i < ans; i++) {
      add(pre2[i][0], pre2[i][1]);
      add(pre2[i][1], pre2[i][0]);
    }
  }
  spfa();
}
