#include <bits/stdc++.h>
using namespace std;
const int N = 2222;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char buff[300];
int a[N][N];
int n, m;
queue<pair<int, int>> q;
bool isValid(int x, int y) {
  if (x < 0 || x >= n) return false;
  if (y < 0 || y >= m) return false;
  return true;
}
int freeNeighbors(int x, int y) {
  int res = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (isValid(nx, ny) && a[nx][ny] == 0) res++;
  }
  return res;
}
void tryNeighbors(int x, int y) {
  if (a[x][y] == 0 && freeNeighbors(x, y) == 1) q.push({x, y});
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (isValid(nx, ny) && a[nx][ny] == 0 && freeNeighbors(nx, ny) == 1) {
      q.push({nx, ny});
    }
  }
}
bool tile(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (isValid(nx, ny)) {
      if (a[nx][ny] == 0) {
        if (i == 0) {
          a[nx][ny] = '>';
          a[x][y] = '<';
        } else if (i == 1) {
          a[nx][ny] = '<';
          a[x][y] = '>';
        } else if (i == 2) {
          a[nx][ny] = '^';
          a[x][y] = 'v';
        } else if (i == 3) {
          a[nx][ny] = 'v';
          a[x][y] = '^';
        }
        tryNeighbors(x, y);
        tryNeighbors(nx, ny);
        return true;
      }
    }
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  gets(buff);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      scanf("%c", &c);
      a[i][j] = (c == '*') ? -1 : 0;
    }
    gets(buff);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0 && freeNeighbors(i, j) == 1) q.push(make_pair(i, j));
    }
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (a[cur.first][cur.second] != 0) continue;
    if (!tile(cur.first, cur.second)) {
      printf("Not unique");
      return 0;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == 0) {
        printf("Not unique");
        return 0;
      }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == -1) {
        printf("*");
      } else {
        printf("%c", char(a[i][j]));
      }
    }
    printf("\n");
  }
  return 0;
}
