#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
const int inf = 1e7;
int dist[N][N];
vector<int> graph[N];
void init(int n) {
  for (int i = 0; i <= n; i++) graph[i].clear();
}
void bfs(int cur, int n) {
  memset(dist[cur], 0, sizeof(dist[cur]));
  queue<int> que;
  que.push(cur);
  while (!que.empty()) {
    int tmp = que.front();
    que.pop();
    int size = graph[tmp].size();
    for (int i = 0; i < size; i++) {
      int now = graph[tmp][i];
      if (!dist[cur][now]) {
        dist[cur][now] = dist[cur][tmp] + 1;
        que.push(now);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!dist[cur][i]) dist[cur][i] = inf;
  }
  dist[cur][cur] = 0;
  return;
}
int main() {
  int n, m;
  int u, v;
  int s1, t1, l1;
  int s2, t2, l2;
  while (scanf("%d%d", &n, &m) != EOF) {
    init(n);
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &u, &v);
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) bfs(i, n);
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
      puts("-1");
      continue;
    }
    int res = dist[s1][t1] + dist[s2][t2];
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        int w1 = min(dist[s1][i] + dist[i][j] + dist[j][t1],
                     dist[s1][j] + dist[j][i] + dist[i][t1]);
        int w2 = min(dist[s2][i] + dist[i][j] + dist[j][t2],
                     dist[s2][j] + dist[j][i] + dist[i][t2]);
        if (w1 > l1 || w2 > l2) continue;
        res = min(res, w1 + w2 - dist[i][j]);
      }
    }
    printf("%d\n", m - res);
  }
  return 0;
}
