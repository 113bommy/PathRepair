#include <bits/stdc++.h>
using namespace std;
const int mx[] = {1, 0, -1, 0};
const int my[] = {0, 1, 0, -1};
const int SIZE = 30;
const int GOLD = 8;
struct point {
  int x, y;
  point() {}
  point(int ix, int iy) : x(ix), y(iy) {}
};
struct node {
  point p;
  int status;
  node() {}
  node(int ix, int iy, int istatus) : p(ix, iy), status(istatus){};
};
int n, m;
int gold, bomb;
char maze[SIZE][SIZE];
int status[SIZE][SIZE];
char visit[SIZE][SIZE][1 << GOLD];
int step[SIZE][SIZE][1 << GOLD];
int sum[1 << GOLD];
int v[SIZE];
point st;
void bfs() {
  queue<node> q;
  visit[st.y][st.x][0] = 1;
  q.push(node(st.x, st.y, 0));
  while (!q.empty()) {
    node now = q.front();
    q.pop();
    int x = now.p.x, y = now.p.y, nowst = now.status;
    for (int i = 0; i < 4; i++) {
      int nx = x + mx[i], ny = y + my[i];
      if (nx < 0 || nx == n || ny < 0 || ny == m || maze[ny][nx] != '.')
        continue;
      int nst = nowst;
      if (my[i] == 1)
        nst ^= status[ny][nx];
      else if (my[i] == -1)
        nst ^= status[y][x];
      if (visit[ny][nx][nst]) {
        continue;
      }
      visit[ny][nx][nst] = 1;
      q.push(node(nx, ny, nst));
      step[ny][nx][nst] = step[y][x][nowst] + 1;
    }
  }
}
int main() {
  cin >> n >> m;
  gold = bomb = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", maze[i]);
    for (int j = 0; j < m; j++) {
      if (maze[i][j] == 'S') {
        st = point(j, i);
        maze[i][j] = '.';
      } else if (isdigit(maze[i][j])) {
        gold++;
        int nr = maze[i][j] - '1';
        for (int k = j + 1; k < m; k++) status[i][k] |= 1 << nr;
      }
    }
  }
  for (int i = 0; i < gold; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < (1 << gold); i++) {
    for (int j = 0; j < gold; j++) {
      if (i & (1 << j)) sum[i] += v[j];
    }
  }
  bomb = gold;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maze[i][j] == 'B') {
        for (int k = j + 1; k < m; k++) {
          status[i][k] |= 1 << bomb;
        }
        bomb++;
      }
    }
  }
  bfs();
  int ans = 0;
  for (int i = 0; i < (1 << gold); i++) {
    if (visit[st.y][st.x][i]) {
      ans = max(ans, sum[i] - step[st.y][st.x][i]);
    }
  }
  cout << ans << endl;
  return 0;
}
