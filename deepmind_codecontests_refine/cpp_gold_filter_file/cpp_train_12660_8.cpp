#include <bits/stdc++.h>
using namespace std;
const int N = 260;
char mp[N][N];
bool vis[N][N];
long long f[N][N];
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int P, Q;
struct S {
  int x, y, val;
  S() {}
  S(int x, int y, int val) : x(x), y(y), val(val) {}
} q[6001000];
void BFS(int sx, int sy) {
  memset(vis, 0, sizeof vis);
  vis[sx][sy] = true;
  int h = 1, t = 2;
  int val = (mp[sx][sy] - 'A' + 1) * Q;
  f[sx][sy] += val;
  q[1] = S(sx, sy, val);
  while (h < t) {
    S u = q[h++];
    if (u.val == 0) continue;
    for (int i = 0; i < 4; i++) {
      int a = u.x + dx[i], b = u.y + dy[i];
      if (vis[a][b]) continue;
      if (mp[a][b] == '*') continue;
      if (a < 0 || b < 0 || a >= n || b >= m) continue;
      vis[a][b] = true;
      f[a][b] += u.val / 2;
      q[t++] = S(a, b, u.val / 2);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &Q, &P);
  for (int i = 0; i < n; i++) scanf("%s", mp[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mp[i][j] >= 'A' && mp[i][j] <= 'Z') BFS(i, j);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (f[i][j] > P) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
