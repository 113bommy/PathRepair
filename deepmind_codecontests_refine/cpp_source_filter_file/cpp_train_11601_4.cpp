#include <bits/stdc++.h>
using namespace std;
int n, m, k, dx[2] = {1, 0}, dy[2] = {0, 1}, cnt, ans;
bool visit[55][55];
struct Node {
  int x, y;
  Node(){};
  Node(int _x, int _y) {
    x = _x;
    y = _y;
  }
} st[1111], q[1111];
int l = 1, r = 1;
inline void bfs() {
  q[++r] = Node(1, 1);
  while (l <= r) {
    Node p = q[++l];
    for (int i = 0; i < 2; i++) {
      int tx = p.x + dx[i], ty = p.y + dy[i];
      if (tx > n || ty > m) continue;
      if (!visit[tx][ty]) {
        visit[tx][ty] = 1;
        q[++r] = Node(tx, ty);
      }
    }
    if (r > k) break;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  bfs();
  while (r > k + 1) r--;
  for (int i = r; i >= 2; i--) {
    int a = q[i].x, b = q[i].y;
    int j = 1, k = 1;
    memset(visit, 0, sizeof(visit));
    for (; j <= a; j++) {
      if (!visit[j][k]) ans++;
      visit[j][k] = 1;
    }
    j--;
    for (; k <= b; k++) {
      if (!visit[j][k]) ans++;
      visit[j][k] = 1;
    }
  }
  printf("%d\n", ans);
  for (int i = r; i >= 2; i--) {
    int a = q[i].x, b = q[i].y;
    int j = 1, k = 1;
    memset(visit, 0, sizeof(visit));
    for (; j <= a; j++) {
      if (!visit[j][k]) printf("(%d,%d) ", j, k);
      visit[j][k] = 1;
    }
    j--;
    for (; k <= b; k++) {
      if (!visit[j][k]) printf("(%d,%d) ", j, k);
      visit[j][k] = 1;
    }
    printf("\n");
  }
  return 0;
}
