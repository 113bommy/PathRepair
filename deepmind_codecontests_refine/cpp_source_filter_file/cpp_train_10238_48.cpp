#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int s[2305][2305], vis[2305][2305];
int n;
int dx[5] = {0, 0, -1, 1};
int dy[5] = {1, -1, 0, 0};
struct rec {
  int x, y;
} q[2305 * 2305];
bool cmp0(const rec &i, const rec &j) {
  return i.x == j.x ? i.y < j.y : i.x < j.x;
}
bool cmp1(const rec &i, const rec &j) {
  return i.y == j.y ? i.x < j.x : i.y < j.y;
}
double dist(rec A, rec B) {
  return sqrt(((A.x - B.x) * (A.x - B.x)) + ((A.y - B.y) * (A.y - B.y)));
}
int A, B;
void Doit(int sx, int sy) {
  int st = 0, en = 0;
  q[++en] = (rec){sx, sy};
  vis[sx][sy] = 1;
  while (st < en) {
    ++st;
    int x = q[st].x, y = q[st].y;
    for (int k = 0; k <= 3; k++) {
      int tx = x + dx[k], ty = y + dy[k];
      if (tx < 1 || tx > n) continue;
      if (ty < 1 || ty > n) continue;
      if (!vis[tx][ty] && s[tx][ty]) {
        vis[tx][ty] = 1;
        q[++en] = (rec){tx, ty};
      }
    }
  }
  if (en <= 100) return;
  int tot = en;
  double lth = 0;
  sort(q + 1, q + 1 + tot, cmp0);
  lth = dist(q[1], q[tot]);
  sort(q + 1, q + 1 + tot, cmp1);
  lth = max(lth, dist(q[1], q[tot]));
  for (int i = 1; i <= tot; i++) lth = max(lth, dist((rec){sx, sy}, q[i]));
  double Val = tot / (lth * lth);
  if (Val < 0.698)
    B++;
  else
    A++;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &s[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int cnt = 0;
      for (int k = 0; k <= 3; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (s[i][j] != s[x][y]) cnt++;
      }
      if (cnt >= 3) s[i][j] ^= 1;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (!vis[i][j] && s[i][j]) Doit(i, j);
  printf("%d %d\n", A, B);
}
