#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
const int maxm = 210;
const int INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 123456701;
int n, m;
struct Edge {
  int u;
  int v;
  int cost;
  int next;
} edge[maxn * 2];
int head[maxn];
int num;
void addedge(int u, int v, int cost) {
  edge[num].u = u;
  edge[num].v = v;
  edge[num].cost = cost;
  edge[num].next = head[u];
  head[u] = num++;
}
vector<int> tst[maxn];
long long dis[maxn];
int vis[maxn];
void spfa(int s) {
  int i, j;
  for (i = 1; i <= n; i++) {
    dis[i] = 1e16;
  }
  memset(vis, 0, sizeof(vis));
  dis[s] = 0;
  vis[s] = 1;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    vis[u] = 0;
    long long t = dis[u];
    int x = lower_bound(tst[u].begin(), tst[u].end(), t) - tst[u].begin();
    while (x < tst[u].size() && tst[u][x] == t) {
      t++;
      x++;
    }
    for (i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].v;
      long long c = edge[i].cost;
      c = c + t;
      if (c < dis[v]) {
        dis[v] = c;
        if (!vis[v]) {
          que.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  return;
}
int main() {
  int i, j;
  int t;
  while (scanf("%d%d", &n, &m) != EOF) {
    num = 0;
    memset(head, -1, sizeof(head));
    for (i = 1; i <= m; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      addedge(x, y, z);
      addedge(y, x, z);
    }
    for (i = 1; i <= n; i++) {
      int k;
      scanf("%d", &k);
      for (j = 1; j <= k; j++) {
        int x;
        scanf("%d", &x);
        tst[i].push_back(x);
      }
    }
    spfa(1);
    for (i = 1; i <= n; i++) {
    }
    if (dis[n] == INF) {
      printf("-1\n");
    } else {
      cout << dis[n] << endl;
    }
  }
  return 0;
}
