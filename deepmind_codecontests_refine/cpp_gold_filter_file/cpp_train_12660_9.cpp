#include <bits/stdc++.h>
using namespace std;
const int N = 255;
char mat[N][N];
long long ans[N][N];
int vis[N][N];
struct ver {
  int x, y, c;
};
void bfs(int x, int y, int c, int n, int m, int cur) {
  vis[x][y] = cur;
  queue<ver> q;
  q.push({x, y, c});
  while (q.size()) {
    ver v = q.front();
    q.pop();
    if (v.c == 0) continue;
    ans[v.x][v.y] += v.c;
    if (v.x > 0 && mat[v.x - 1][v.y] != '*' && vis[v.x - 1][v.y] != cur) {
      q.push({v.x - 1, v.y, v.c / 2});
      vis[v.x - 1][v.y] = cur;
    }
    if (v.y > 0 && mat[v.x][v.y - 1] != '*' && vis[v.x][v.y - 1] != cur) {
      q.push({v.x, v.y - 1, v.c / 2});
      vis[v.x][v.y - 1] = cur;
    }
    if (v.x < n - 1 && mat[v.x + 1][v.y] != '*' && vis[v.x + 1][v.y] != cur) {
      q.push({v.x + 1, v.y, v.c / 2});
      vis[v.x + 1][v.y] = cur;
    }
    if (v.y < m - 1 && mat[v.x][v.y + 1] != '*' && vis[v.x][v.y + 1] != cur) {
      q.push({v.x, v.y + 1, v.c / 2});
      vis[v.x][v.y + 1] = cur;
    }
  }
}
int main() {
  int n, m, q, p;
  scanf("%d%d%d%d", &n, &m, &q, &p);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c ", &mat[i][j]);
    }
  }
  int cur = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] != '.' && mat[i][j] != '*') {
        bfs(i, j, q * (mat[i][j] - 'A' + 1), n, m, cur++);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ans[i][j] > p) res++;
    }
  }
  printf("%d", res);
}
