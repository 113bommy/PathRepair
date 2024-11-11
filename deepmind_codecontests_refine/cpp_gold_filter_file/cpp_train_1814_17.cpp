#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[22][22];
int val[10], N;
int mask[22][22];
int dis[22][22][1 << 8][4][4];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int q[10000055], s, e;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) scanf("%s", mat[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (isdigit(mat[i][j])) {
        mat[i][j]--, N++;
      }
  for (int i = 0; i < N; ++i) cin >> val[i];
  int sx, sy;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 'B') mat[i][j] = N + '0', val[N++] = -1000000;
      if (mat[i][j] == 'S') sx = i, sy = j, mat[i][j] = '.';
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k <= i; ++k)
        if (isdigit(mat[k][j])) mask[i][j] |= (1 << (mat[k][j] - '0'));
    }
  memset(dis, -1, sizeof(dis));
  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    int x = sx + dx[i];
    int y = sy + dy[i];
    if (x < 0 || x >= n || y < 0 || y >= m) continue;
    if (mat[x][y] != '.') continue;
    if (sy != y) {
      dis[x][y][mask[x][y] ^ mask[sx][sy]][i][i] = 1, q[e++] = x, q[e++] = y,
                             q[e++] = mask[x][y] ^ mask[sx][sy], q[e++] = i,
                             q[e++] = i;
    } else {
      dis[x][y][0][i][i] = 1, q[e++] = x, q[e++] = y, q[e++] = 0, q[e++] = i,
      q[e++] = i;
    }
  }
  while (s < e) {
    int x = q[s++], y = q[s++], mk = q[s++], dir = q[s++], ori = q[s++];
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (mat[nx][ny] != '.') continue;
      if (y == ny) {
        if (dis[nx][ny][mk][dir][ori] == -1) {
          dis[nx][ny][mk][dir][ori] = dis[x][y][mk][dir][ori] + 1;
          q[e++] = nx, q[e++] = ny, q[e++] = mk, q[e++] = dir, q[e++] = ori;
        }
      } else {
        int nmk;
        if (ori == 2 || ori == 3) {
          nmk = mk ^ mask[nx][ny] ^ mask[x][y];
          if (dis[nx][ny][nmk][i][i] == -1) {
            dis[nx][ny][nmk][i][i] = dis[x][y][mk][dir][ori] + 1;
            q[e++] = nx, q[e++] = ny, q[e++] = nmk, q[e++] = i, q[e++] = i;
          }
        } else {
          if (dir == i) {
            nmk = mk ^ mask[nx][ny];
            if (dis[nx][ny][nmk][i][ori] == -1) {
              dis[nx][ny][nmk][i][ori] = dis[x][y][mk][dir][ori] + 1;
              q[e++] = nx, q[e++] = ny, q[e++] = nmk, q[e++] = i, q[e++] = ori;
            }
          } else {
            nmk = mk ^ mask[nx][ny] ^ mask[x][y];
            if (dis[nx][ny][nmk][i][ori] == -1) {
              dis[nx][ny][nmk][i][ori] = dis[x][y][mk][dir][ori] + 1;
              q[e++] = nx, q[e++] = ny, q[e++] = nmk, q[e++] = i, q[e++] = ori;
            }
          }
        }
      }
    }
  }
  for (int mk = 0; mk < (1 << N); ++mk)
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        if (dis[sx][sy][mk][i][j] != -1) {
          int tmp = 0;
          for (int k = 0; k < N; ++k) {
            if (i == j) {
              if ((mk ^ mask[sx][sy]) >> k & 1) tmp += val[k];
            } else {
              if (mk >> k & 1) tmp += val[k];
            }
          }
          ans = max(ans, tmp - dis[sx][sy][mk][i][j]);
        }
  cout << ans;
}
