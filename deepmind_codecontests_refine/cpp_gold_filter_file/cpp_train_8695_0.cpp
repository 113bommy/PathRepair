#include <bits/stdc++.h>
using namespace std;
long long n, m, num, val;
long long k;
long long a[1005][1005];
struct node {
  long long val;
  int x, y;
} b[1005 * 1005];
bool cmp(node aa, node bb) { return aa.val < bb.val; }
bool vis[1005][1005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool used[1005][1005];
void bfs(int x, int y) {
  queue<pair<int, int> > que;
  que.push(pair<int, int>(x, y));
  vis[x][y] = 1;
  num--;
  if (num == 0) return;
  int xx, yy;
  while (!que.empty()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    for (int i = 0; i < 4; i++) {
      xx = x + dx[i];
      yy = y + dy[i];
      if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
      if (a[xx][yy] < val || vis[xx][yy]) continue;
      que.push(pair<int, int>(xx, yy));
      if (a[xx][yy] == val) used[xx][yy] = 1;
      vis[xx][yy] = 1;
      num--;
      if (num == 0) return;
    }
  }
}
long long has[1005 * 1005];
int main() {
  cin >> n >> m >> k;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%I64d", &a[i][j]);
      b[cnt++] = (node){a[i][j], i, j};
    }
  }
  sort(b, b + cnt, cmp);
  int id, idd;
  for (int i = 0; i < cnt; i++) {
    if (k % b[i].val != 0) continue;
    num = k / b[i].val;
    val = b[i].val;
    if (num > n * m) continue;
    if (used[b[i].x][b[i].y]) continue;
    memset(vis, 0, sizeof(vis));
    bfs(b[i].x, b[i].y);
    if (num == 0) {
      printf("YES\n");
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= m; k++) {
          if (vis[j][k])
            printf("%d ", b[i].val);
          else
            printf("0 ");
        }
        printf("\n");
      }
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
