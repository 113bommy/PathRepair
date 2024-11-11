#include <bits/stdc++.h>
using namespace std;
const int N = 22, M = 256 + 10;
inline long long rd() {
  long long x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
int fx[4] = {1, -1, 0, 0}, fy[4] = {0, 0, 1, -1};
int n, m, sx, sy, kk, a[N][2], b[N][2], tb, nn, sm[M], di[N][N][M];
char mp[N][N];
struct node {
  int x, y, z, d;
  bool operator<(const node &bb) const { return d > bb.d; }
};
priority_queue<node> q;
int main() {
  n = rd(), m = rd();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", mp[i] + 1);
    for (int j = 1; j <= m; ++j) {
      if (mp[i][j] > '0' && mp[i][j] <= '9') {
        int x = mp[i][j] - '0';
        kk = max(kk, x), a[x][0] = i, a[x][1] = j;
      } else if (mp[i][j] == 'S')
        sx = i, sy = j;
      else if (mp[i][j] == 'B')
        b[++tb][0] = i, b[tb][1] = j;
    }
  }
  for (int i = 0; i < kk; ++i) sm[1 << i] = rd();
  for (int i = 1; i <= tb; ++i)
    sm[1 << (kk + i - 1)] = -1 << 20, a[kk + i][0] = b[i][0],
                      a[kk + i][1] = b[i][1];
  kk += tb;
  nn = (1 << kk);
  for (int i = 1; i < nn; ++i) sm[i] = sm[i & (-i)] + sm[i ^ (i & (-i))];
  int ans = -(1 << 30);
  memset(di, 0x3f3f3f, sizeof(di));
  di[sx][sy][0] = 0, q.push((node){sx, sy, 0, 0});
  while (!q.empty()) {
    int x = q.top().x, y = q.top().y, z = q.top().z, d = q.top().d;
    q.pop();
    if (d > di[x][y][z]) continue;
    for (int k = 0; k < 4; ++k) {
      int xx = x + fx[k], yy = y + fy[k];
      if (mp[xx][yy] != '.' && mp[xx][yy] != 'S') continue;
      int zz = z;
      if (k < 2) {
        for (int l = 1; l <= kk; ++l)
          if (yy > a[l][1] && ((x == a[l][0] && xx > a[l][0]) ||
                               (x > a[l][0] && xx == a[l][0])))
            zz ^= 1 << (l - 1);
      }
      if (di[xx][yy][zz] > di[x][y][z] + 1)
        q.push((node){xx, yy, zz, di[xx][yy][zz] = di[x][y][z] + 1});
    }
  }
  for (int k = 0; k < nn; ++k) ans = max(ans, sm[k] - di[sx][sy][k]);
  printf("%d\n", ans);
  return 0;
}
