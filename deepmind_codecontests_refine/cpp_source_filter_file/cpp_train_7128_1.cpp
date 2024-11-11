#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
int degree[MAXN][MAXN];
bool mark[MAXN][MAXN];
char v[MAXN][MAXN];
char ans[MAXN][MAXN];
queue<int> q;
bool check(int x, int y) {
  if (x > n || y > m) return false;
  if (x <= 0 || y <= 0) return false;
  return !mark[x][y];
}
void recalculateDegree(int x, int y) {
  if (mark[x][y]) return;
  degree[x][y] = 0;
  for (int d = 0; d < 4; d++) {
    int newX = x + dx[d];
    int newY = y + dy[d];
    if (check(newX, newY)) degree[x][y]++;
  }
  if (degree[x][y] == 1) {
    q.push(x);
    q.push(y);
  }
}
void putPiece(int x1, int y1, int x2, int y2) {
  mark[x1][y1] = true;
  mark[x2][y2] = true;
  for (int d = 0; d < 4; d++) {
    int newX = x2 + dx[d];
    int newY = y2 + dy[d];
    if (check(newX, newY)) recalculateDegree(newX, newY);
  }
  if (x1 == x2) {
    if (y1 > y2) swap(y1, y2);
    ans[x1][y1] = '<';
    ans[x2][y2] = '>';
  } else {
    if (x1 > x2) swap(x1, x2);
    ans[x1][y1] = '^';
    ans[x2][y2] = 'V';
  }
}
void topologicalSorting() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (v[i][j] == '*') {
        mark[i][j] = true;
        ans[i][j] = '*';
      }
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!mark[i][j]) recalculateDegree(i, j);
  while (!q.empty()) {
    int curX = q.front();
    q.pop();
    int curY = q.front();
    q.pop();
    recalculateDegree(curX, curY);
    if (mark[curX][curY]) continue;
    if (degree[curX][curY] == 0) continue;
    int pX, pY;
    for (int d = 0; d < 4; d++) {
      int newX = curX + dx[d];
      int newY = curY + dy[d];
      if (check(newX, newY)) {
        pX = newX;
        pY = newY;
      }
    }
    putPiece(curX, curY, pX, pY);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf(" %c", &v[i][j]);
  topologicalSorting();
  bool hasNoMarked = false;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) hasNoMarked = hasNoMarked || !mark[i][j];
  if (hasNoMarked)
    printf("Not unique\n");
  else {
    for (int i = 1; i <= n; i++, printf("\n"))
      for (int j = 1; j <= m; j++) printf("%c", ans[i][j]);
  }
}
