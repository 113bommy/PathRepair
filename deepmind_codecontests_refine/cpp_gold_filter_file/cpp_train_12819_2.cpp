#include <bits/stdc++.h>
using namespace std;
int n;
int r1, c1;
int r2, c2;
int cnt1 = 1;
int cnt2 = 1;
char a[1000][1000];
int to[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int dis[1000][1000];
int vis[1000][1000];
int flag = 0;
struct node {
  int x, y;
} s[1000], e[1000];
int check(int x, int y) {
  if (x <= 0 || y <= 0 || x > n || y > n)
    return 1;
  else if (a[x][y] == '1')
    return 1;
  else if (vis[x][y] == 1)
    return 1;
  return 0;
}
void bfs(int x, int y, int num) {
  node now, next;
  queue<node> Q;
  now.x = x;
  now.y = y;
  vis[x][y] = 1;
  Q.push(now);
  while (!Q.empty()) {
    now = Q.front();
    Q.pop();
    int i;
    for (i = 0; i < 4; i++) {
      next = now;
      next.x = now.x + to[i][0];
      next.y = now.y + to[i][1];
      if (check(next.x, next.y)) {
        continue;
      }
      if (num == 1) {
        s[cnt1].x = next.x;
        s[cnt1++].y = next.y;
      }
      if (num == -1) {
        e[cnt2].x = next.x;
        e[cnt2++].y = next.y;
      }
      vis[next.x][next.y] = 1;
      Q.push(next);
    }
  }
  return;
}
int main() {
  while (~scanf("%d", &n)) {
    scanf("%d%d", &r1, &c1);
    s[0].x = r1;
    s[0].y = c1;
    scanf("%d%d", &r2, &c2);
    e[0].x = r2;
    e[0].y = c2;
    int i;
    int j;
    for (i = 1; i <= n; i++) {
      getchar();
      for (j = 1; j <= n; j++) {
        scanf("%c", &a[i][j]);
      }
    }
    memset(vis, 0, sizeof(vis));
    bfs(r1, c1, 1);
    memset(vis, 0, sizeof(vis));
    bfs(r2, c2, -1);
    int ans = 5001;
    for (i = 0; i < cnt1; i++) {
      for (j = 0; j < cnt2; j++) {
        ans = min(ans, (s[i].x - e[j].x) * (s[i].x - e[j].x) +
                           (s[i].y - e[j].y) * (s[i].y - e[j].y));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
