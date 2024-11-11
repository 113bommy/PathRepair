#include <bits/stdc++.h>
using namespace std;
const int maxn = 550;
char Map[maxn][maxn];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
int n, m;
bool in(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= m; }
void gst(int &x, int &y) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (Map[i][j] == '.') {
        x = i, y = j;
        return;
      }
    }
  }
  x = y = 0;
}
queue<pair<int, int> > Q;
stack<pair<int, int> > S;
bool vis[maxn][maxn];
void bfs(int k) {
  int x, y;
  gst(x, y);
  memset(vis, 0, sizeof(vis));
  while (Q.empty() == false) Q.pop();
  while (S.empty() == false) S.pop();
  Q.push(make_pair(x, y));
  vis[x][y] = true;
  while (Q.empty() == false) {
    S.push(Q.front());
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    for (int d = 0; d < 4; d++) {
      int i = dx[d] + x;
      int j = dy[d] + y;
      if (in(i, j) && vis[i][j] == false && Map[i][j] == '.') {
        vis[i][j] = true;
        Q.push(make_pair(i, j));
      }
    }
  }
  while (k-- && !S.empty()) {
    Map[S.top().first][S.top().second] = 'X';
    S.pop();
  }
}
int main() {
  int k;
  while (~scanf("%d %d %d", &n, &m, &k)) {
    for (int i = 1; i <= n; i++) {
      scanf("%s", Map[i] + 1);
    }
    bfs(k);
    for (int i = 1; i <= n; i++) {
      printf("%s\n", Map[i] + 1);
    }
  }
  return 0;
}
