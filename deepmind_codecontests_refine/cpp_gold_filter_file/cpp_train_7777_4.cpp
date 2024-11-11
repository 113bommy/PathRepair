#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int dp[N][10][10][10][10];
int a[N], b[N];
int n;
bool update(int &x, int y) {
  if (y == -1) return false;
  if (x == -1 || x > y) {
    x = y;
    return true;
  }
  return false;
}
struct point {
  int p, x, y, z, f, dis;
  point() {}
  point(int p, int x, int y, int z, int f, int dis)
      : p(p), x(x), y(y), z(z), f(f), dis(dis) {}
  friend bool operator<(const point &a, const point &b) {
    return a.dis > b.dis;
  }
};
priority_queue<point> q;
int solve() {
  memset(dp, -1, sizeof(dp));
  dp[0][0][0][0][1] = 0;
  q.push(point(0, 0, 0, 0, 1, 0));
  while (!q.empty()) {
    point u = q.top();
    q.pop();
    if (u.dis != dp[u.p][u.x][u.y][u.z][u.f]) continue;
    if (u.x) {
      if (update(dp[u.p][0][u.y][u.z][u.x], u.dis + abs(u.f - u.x))) {
        q.push(point(u.p, 0, u.y, u.z, u.x, dp[u.p][0][u.y][u.z][u.x]));
      }
    }
    if (u.y) {
      if (update(dp[u.p][0][u.x][u.z][u.y], u.dis + abs(u.f - u.y))) {
        q.push(point(u.p, 0, u.x, u.z, u.y, u.dis + abs(u.f - u.y)));
      }
    }
    if (u.z) {
      if (update(dp[u.p][0][u.x][u.y][u.z], u.dis + abs(u.f - u.z))) {
        q.push(point(u.p, 0, u.x, u.y, u.z, u.dis + abs(u.f - u.z)));
      }
    }
    if (u.p == n) continue;
    if (!u.x) {
      int x = b[u.p + 1], y = u.y, z = u.z;
      if (x > y) swap(x, y);
      if (x > z) swap(x, z);
      if (y > z) swap(y, z);
      if (update(dp[u.p + 1][x][y][z][a[u.p + 1]],
                 u.dis + abs(u.f - a[u.p + 1]))) {
        q.push(
            point(u.p + 1, x, y, z, a[u.p + 1], u.dis + abs(u.f - a[u.p + 1])));
      }
      continue;
    }
    int x, y, z, r;
    if (b[u.p + 1] <= u.x)
      x = b[u.p + 1], y = u.x, z = u.y, r = u.z;
    else if (b[u.p + 1] <= u.y)
      x = u.x, y = b[u.p + 1], z = u.y, r = u.z;
    else if (b[u.p + 1] <= u.z)
      x = u.x, y = u.y, z = b[u.p + 1], r = u.z;
    else
      x = u.x, y = u.y, z = u.z, r = b[u.p + 1];
    if (update(dp[u.p + 1][y][z][r][x],
               u.dis + abs(u.f - a[u.p + 1]) + abs(a[u.p + 1] - x))) {
      q.push(point(u.p + 1, y, z, r, x,
                   u.dis + abs(u.f - a[u.p + 1]) + abs(a[u.p + 1] - x)));
    }
    if (update(dp[u.p + 1][x][z][r][y],
               u.dis + abs(u.f - a[u.p + 1]) + abs(a[u.p + 1] - y))) {
      q.push(point(u.p + 1, x, z, r, y,
                   u.dis + abs(u.f - a[u.p + 1]) + abs(a[u.p + 1] - y)));
    }
    if (update(dp[u.p + 1][x][y][r][z],
               u.dis + abs(u.f - a[u.p + 1]) + abs(a[u.p + 1] - z))) {
      q.push(point(u.p + 1, x, y, r, z,
                   u.dis + abs(u.f - a[u.p + 1]) + abs(a[u.p + 1] - z)));
    }
    if (update(dp[u.p + 1][x][y][z][r],
               u.dis + abs(u.f - a[u.p + 1]) + abs(a[u.p + 1] - r))) {
      q.push(point(u.p + 1, x, y, z, r,
                   u.dis + abs(u.f - a[u.p + 1]) + abs(a[u.p + 1] - r)));
    }
  }
  int ans = -1;
  for (int i = 1; i <= 9; i++) update(ans, dp[n][0][0][0][i]);
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
  int ans = 2 * n + solve();
  printf("%d\n", ans);
  return 0;
}
