#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 305;
const int MAXQ = 2e6 + 5;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, tot, num, Q;
int a[MAXN][MAXN], f[MAXQ << 1], id[MAXN][MAXN], ans[MAXQ];
struct Query {
  int x, y, org, col;
} q[MAXQ];
int find(int x) {
  if (x == f[x])
    return x;
  else
    return f[x] = find(f[x]);
}
void unionn(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx != fy) {
    f[fx] = fy;
    num--;
  }
}
bool check(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
void change(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (check(nx, ny) && a[x][y] == a[nx][ny]) unionn(id[x][y], id[nx][ny]);
  }
}
void solve1() {
  for (int i = 1; i <= Q; i++) {
    if (q[i].col == q[i].org) continue;
    int x = q[i].x;
    int y = q[i].y;
    num = 1;
    a[x][y] = q[i].col;
    id[x][y] = ++tot;
    f[tot] = tot;
    change(x, y);
    ans[i] += num;
  }
}
void solve2() {
  for (int i = Q; i >= 1; i--) {
    if (q[i].col == q[i].org) continue;
    int x = q[i].x;
    int y = q[i].y;
    num = 1;
    a[x][y] = q[i].org;
    id[x][y] = ++tot;
    f[tot] = tot;
    change(x, y);
    ans[i] -= num;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 1; i <= Q; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    q[i] = (Query){x, y, a[x][y], z};
    a[x][y] = z;
  }
  ans[0] = 1;
  memset(a, -1, sizeof(a));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) a[i][j] = 0;
  }
  solve1();
  memset(f, 0, sizeof(f));
  tot = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      id[i][j] = ++tot;
      f[tot] = tot;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) change(i, j);
  }
  solve2();
  for (int i = 1; i <= Q; i++) {
    ans[i] += ans[i - 1];
    printf("%d\n", ans[i]);
  }
  return 0;
}
