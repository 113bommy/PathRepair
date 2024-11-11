#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 2e2 + 10, M = 2e6 + 10, dx[] = {-1, 1, 0, 0, 0},
          dy[] = {0, 0, -1, 1, 0};
int n, m, k, t, w, W[N], f[M], sx, sy;
char mat[N][N];
bool vis[25][N][N][N];
vector<int> vec[N][N];
struct Node {
  int x, y, last, k;
};
map<char, int> mp = {{'N', 0}, {'S', 1}, {'W', 2}, {'E', 3}, {'C', 4}};
inline bool check(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= m) return false;
  if (mat[x][y] == 'L') return false;
  return true;
}
inline void ha(Node x) { printf("ha:%d %d %d %d\n", x.x, x.y, x.last, x.k); }
inline int bfs() {
  queue<Node> q;
  q.push((Node){sx, sy, 0, k});
  while (!q.empty()) {
    Node u = q.front();
    q.pop();
    int x = u.x, y = u.y, last = u.last, cur = u.k, t = f[last] + k - cur;
    if (mat[x][y] == 'P') return t;
    if (mat[x][y] == 'L') continue;
    if (vis[last][x][y][cur]) continue;
    vis[last][x][y][cur] = true;
    for (int i = 0; i < vec[x][y].size(); ++i)
      if (t == f[vec[x][y][i]]) {
        cur = k;
        last = vec[x][y][i];
      }
    if (cur == 0) continue;
    u = (Node){u.x + dx[W[t]], u.y + dy[W[t]], last, cur - 1};
    if (check(u.x, u.y)) q.push(u);
    for (int i = 0; i < 4; ++i) {
      int tx = x + dx[i] + dx[W[t]], ty = y + dy[i] + dy[W[t]];
      if ((check(x + dx[i], y + dy[i]) && check(tx, ty)) ||
          (check(x + dx[W[t]], y + dy[W[t]]) && check(tx, ty))) {
        u = (Node){tx, ty, last, cur - 1};
        if (!vis[last][tx][ty][cur - 1]) q.push(u);
      }
    }
  }
  return -1;
}
int main() {
  n = read();
  m = read();
  k = read();
  t = read();
  w = read();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
      if (mat[i][j] == 'M') {
        sx = i;
        sy = j;
      }
    }
  for (int i = 0; i < w; ++i) {
    char ch;
    cin >> ch;
    W[i] = mp[ch];
  }
  for (int i = 1; i <= t; ++i) {
    int x = read(), y = read();
    vec[x][y].push_back(i);
    f[i] = read();
  }
  printf("%d\n", bfs());
  return 0;
}
