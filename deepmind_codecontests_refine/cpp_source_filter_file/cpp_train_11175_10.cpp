#include <bits/stdc++.h>
using namespace std;
const long long N = 1555;
bool mp[N][N], vis[N][N];
long long sx, sy, fx[N][N], fy[N][N], n, m;
long long dx[4] = {0, 0, -1, 1};
long long dy[4] = {-1, 1, 0, 0};
long long pos(long long x, long long d) {
  return x < 0 ? (d - ((x * -1) % d)) : x % d;
}
void dfs(long long x1, long long y1) {
  long long x = pos(x1, n);
  long long y = pos(y1, m);
  vis[x][y] = true;
  fx[x][y] = x1;
  fy[x][y] = y1;
  for (long long i = 0; i < 4; i++) {
    long long nx = x1 + dx[i], ny = y1 + dy[i];
    long long nx1 = pos(nx, n), ny1 = pos(ny, m);
    if (mp[nx1][ny1]) continue;
    if (vis[nx1][ny1]) {
      if (fx[nx1][ny1] != nx || fy[nx1][ny1] != ny) {
        cout << "Yes" << endl;
        exit(0);
      }
      continue;
    }
    dfs(nx, ny);
  }
}
int main() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (long long j = 0; j < m; j++) {
      if (s[j] == 'S') sx = i, sy = j;
      if (s[j] == '#')
        mp[i][j] = true;
      else
        mp[i][j] = false;
    }
  }
  dfs(sx, sy);
  cout << "No" << endl;
}
