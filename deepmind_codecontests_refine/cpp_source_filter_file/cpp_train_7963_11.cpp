#include <bits/stdc++.h>
using namespace std;
struct Node {
  int x, y;
} dq, nxt;
queue<Node> q;
int dist[5][1005][1005];
const int INF = 19950920;
char s[1005][1005];
int n, m, ans, ans12, ans23, ans13;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void work(int id) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) dist[id][i][j] = INF;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] != '0' + id) continue;
      dist[id][i][j] = 0;
      dq.x = i;
      dq.y = j;
      q.push(dq);
    }
  while (!q.empty()) {
    dq = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      nxt.x = dq.x + dx[i];
      nxt.y = dq.y + dy[i];
      if (nxt.x < 1 || nxt.x > n) continue;
      if (nxt.y < 1 || nxt.y > m) continue;
      if (s[nxt.x][nxt.y] == '#') continue;
      if (dist[id][nxt.x][nxt.y] != INF) continue;
      q.push(nxt);
      dist[id][nxt.x][nxt.y] = dist[id][dq.x][dq.y] + 1;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  for (int i = 1; i <= 3; ++i) work(i);
  ans = ans12 = ans23 = ans13 = INF;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      ans12 = min(ans12, dist[1][i][j] + dist[2][i][j] - 1);
      ans23 = min(ans23, dist[2][i][j] + dist[3][i][j] - 1);
      ans13 = min(ans13, dist[1][i][j] + dist[3][i][j] - 1);
    }
  ans = min(ans, ans12 + ans23);
  ans = min(ans, ans13 + ans23);
  ans = min(ans, ans12 + ans13);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      ans = min(ans, dist[1][i][j] + dist[2][i][j] + dist[3][i][j] - 2);
  if (ans == INF) ans = -1;
  printf("%d\n", ans);
  return 0;
}
