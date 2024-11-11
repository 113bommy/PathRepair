#include <bits/stdc++.h>
using namespace std;
int n, m, K, S, tot, x, y, k[100100], h[101][100100], dis[100100][101],
    ans[100100], head[100100], vis[100100];
struct Node {
  int y, nxt;
} side[200100];
void add(int x, int y) {
  tot++;
  side[tot].y = y;
  side[tot].nxt = head[x];
  head[x] = tot;
}
void BFS(int t) {
  queue<int> q;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= h[t][0]; i++)
    q.push(h[t][i]), dis[h[t][i]][t] = 0, vis[h[t][i]] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    vis[x] = 0;
    for (int i = head[x]; i; i = side[i].nxt) {
      int y = side[i].y;
      if (dis[y][t] > dis[x][t] + 1) {
        dis[y][t] = dis[x][t] + 1;
        if (!vis[y]) q.push(y), vis[y] = 1;
      }
    }
  }
}
int main() {
  cin >> n >> m >> K >> S;
  for (int i = 1; i <= n; i++) cin >> k[i], h[k[i]][++h[k[i]][0]] = i;
  for (int i = 1; i <= m; i++) cin >> x >> y, add(x, y), add(y, x);
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= K; i++) BFS(i);
  for (int i = 1; i <= n; i++) {
    sort(dis[i] + 1, dis[i] + 1 + K);
    for (int j = 1; j <= S; j++) ans[i] += dis[i][j];
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
