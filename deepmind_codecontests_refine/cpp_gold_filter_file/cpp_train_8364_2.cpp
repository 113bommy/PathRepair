#include <bits/stdc++.h>
using namespace std;
bool visited[16][16][(1 << 16)];
char graph[16][16];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int len, n, m, tx, ty;
struct item {
  int x, y, state, step, ox, oy;
} z;
queue<item> q;
bool valid(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m)
    return false;
  else
    return true;
}
void preprocess() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (graph[i][j] == '@') {
        tx = i;
        ty = j;
      }
      if (graph[i][j] >= '1' && graph[i][j] <= '9') {
        if (graph[i][j] - '0' > len) {
          len = graph[i][j] - '0';
          z.ox = i;
          z.oy = j;
        }
      }
      if (graph[i][j] == '1') {
        z.x = i;
        z.y = j;
      }
      if (i < n - 1) {
        if (graph[i][j] - graph[i + 1][j] == 1) {
          z.state |= 3 << (2 * (graph[i + 1][j] - '1'));
        } else if (graph[i][j] - graph[i + 1][j] == -1) {
          z.state |= 2 << (2 * (graph[i][j] - '1'));
        }
      }
      if (j < m - 1) {
        if (graph[i][j] - graph[i][j + 1] == 1) {
          z.state |= 1 << (2 * (graph[i][j + 1] - '1'));
        }
      }
    }
  }
  z.step = 0;
}
bool collision(int nox, int noy, int nx, int ny, int ns) {
  int currx = nox, curry = noy;
  if (currx == nx && curry == ny) return true;
  for (int i = (len - 2); i >= 1; i--) {
    int t = ns >> 2 * i;
    t &= 3;
    if (t == 3) {
      currx++;
    } else if (t == 2) {
      currx--;
    } else if (t == 1) {
      curry++;
    } else {
      curry--;
    }
    if (currx == nx && curry == ny) return true;
  }
  return false;
}
int bfs() {
  q.push(z);
  visited[z.x][z.y][z.state] = true;
  while (!q.empty()) {
    item s = q.front();
    q.pop();
    if (s.x == tx && s.y == ty) {
      return s.step;
    }
    for (int i = 0; i < 4; i++) {
      int nx = s.x + dx[i];
      int ny = s.y + dy[i];
      int p = 0, nox, noy;
      p |= dx[i] == 1 ? 3 : 0;
      p |= dx[i] == -1 ? 2 : 0;
      p |= dy[i] == 1 ? 1 : 0;
      int ns = ((s.state << 2) & ((1 << 2 * (len - 1)) - 1)) | p;
      int t = s.state >> 2 * (len - 2);
      if (t == 3) {
        noy = s.oy;
        nox = s.ox + 1;
      } else if (t == 2) {
        noy = s.oy;
        nox = s.ox - 1;
      } else if (t == 1) {
        noy = s.oy + 1;
        nox = s.ox;
      } else {
        noy = s.oy - 1;
        nox = s.ox;
      }
      if (valid(nx, ny) && !visited[nx][ny][ns] && graph[nx][ny] != '#') {
        if (!collision(nox, noy, nx, ny, ns)) {
          visited[nx][ny][ns] = true;
          q.push(item{nx, ny, ns, s.step + 1, nox, noy});
        }
      }
    }
  }
  return -1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> graph[i];
  }
  preprocess();
  cout << bfs() << endl;
}
