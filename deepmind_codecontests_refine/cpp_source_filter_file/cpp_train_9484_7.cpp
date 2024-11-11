#include <bits/stdc++.h>
const int N = 2005;
const long long MOD = 1e9 + 7;
using namespace std;
char c[N][N];
string ans;
int ex[3] = {0, 0, 1}, ey[3] = {0, 1, 0};
int n, K, r, vis[N][N], f[N][N];
struct nn {
  int x, y;
};
nn Q[N * N], q[N * N];
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; i++) {
    scanf("\n");
    for (int j = 1; j <= n; j++) {
      scanf("%c", &c[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      if (c[i][j] == 'a') f[i][j]++;
      if (f[i][j] + K >= i + j - 1) {
        int len = i + j - 1;
        if (r > 0) {
          if (len < q[r].x + q[r].y - 1) continue;
          if (len > q[r].x + q[r].y - 1) r = 0;
        }
        r++;
        q[r].x = i;
        q[r].y = j;
      }
    }
  }
  int R, las;
  if (r > 0) {
    R = r;
    for (int i = 1; i <= R; i++) Q[i] = q[i];
    las = q[1].x + q[1].y - 1;
    for (int i = 1; i <= las; i++) ans += 'a';
  } else
    R = 1, Q[1].x = 1, Q[1].y = 1, las = 0, ans = c[1][1];
  for (int yh = las + 1; yh <= 2 * n - 1; yh++) {
    r = 0;
    for (int i = 1; i <= R; i++) {
      int x = Q[i].x, y = Q[i].y;
      for (int j = 1; j <= 2; j++) {
        int nx = x + ex[j], ny = y + ey[j];
        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if (vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        char now = c[nx][ny];
        if (r > 0) {
          if (now > c[q[r].x][q[r].y]) continue;
          if (now < c[q[r].x][q[r].y]) r = 0;
        }
        r++;
        q[r].x = nx;
        q[r].y = ny;
      }
    }
    ans += c[q[r].x][q[r].y];
    R = r;
    for (int i = 1; i <= r; i++) Q[i] = q[i];
  }
  cout << ans;
  return 0;
}
