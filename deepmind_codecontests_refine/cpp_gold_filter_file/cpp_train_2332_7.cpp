#include <bits/stdc++.h>
using namespace std;
struct point {
  char c;
  int x, y;
  point() {}
  point(char c, int x, int y) : c(c), x(x), y(y) {}
};
vector<point> ans;
char s[510][510];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int n, m;
bool sure(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
struct node {
  int x, y;
  node() {}
  node(int x, int y) : x(x), y(y) {}
} q[1000010];
void bfs(int x, int y) {
  int top = 0, tail = 1;
  q[0] = node(x, y);
  s[x][y] = '#';
  while (top < tail) {
    node u = q[top++];
    for (int i = 0; i < 4; i++) {
      int x = u.x + dir[i][0];
      int y = u.y + dir[i][1];
      if (!sure(x, y)) continue;
      if (s[x][y] == '#') continue;
      s[x][y] = '#';
      q[tail++] = node(x, y);
    }
  }
  for (int i = tail - 1; i >= 0; i--) ans.push_back(point('B', q[i].x, q[i].y));
  for (int i = tail - 1; i > 0; i--) {
    ans.push_back(point('D', q[i].x, q[i].y));
    ans.push_back(point('R', q[i].x, q[i].y));
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '.') bfs(i, j);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%c %d %d\n", ans[i].c, ans[i].x, ans[i].y);
  return 0;
}
