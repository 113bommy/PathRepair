#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, t;
char s[2000][2000];
int nt[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int bz[2000][2000];
int pd(int x, int y) {
  for (int k = 0; k < 4; k++) {
    int tx = x + nt[k][0];
    int ty = y + nt[k][1];
    if (s[tx][ty] == s[x][y]) return 1;
  }
  return 0;
}
struct node {
  int x, y, s;
};
void bfs() {
  queue<node> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) bz[i][j] = -1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (pd(i, j)) {
        q.push(node{i, j, 0});
        bz[i][j] = 0;
      }
    }
  while (!q.empty()) {
    node p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int tx = p.x + nt[i][0], ty = p.y + nt[i][1];
      if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && bz[tx][ty] == -1) {
        int tp = p.s + ((s[tx][ty] == s[p.x][p.y]) ? 0 : 1);
        bz[tx][ty] = tp;
        q.push(node{tx, ty, tp});
      }
    }
  }
}
int main() {
  scanf("%d%d%lld", &n, &m, &t);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  bfs();
  while (t--) {
    int x, y;
    long long p;
    scanf("%d%d%lld", &x, &y, &p);
    long long d = s[x][y] - '0';
    long long ok = (p - bz[x][y]) & 1ll;
    if (bz[x][y] >= 0 && bz[x][y] < p && ok) {
      d ^= 1ll;
    }
    printf("%lld\n", d);
  }
}
