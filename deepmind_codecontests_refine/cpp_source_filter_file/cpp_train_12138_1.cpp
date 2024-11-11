#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1000 + 10;
int n, m;
char mp[maxn][maxn];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int cnt = 0x3f3f3f3f;
int vis[maxn][maxn][4][3];
int f = 0;
bool check(int x, int y, int id, int ans) {
  if (x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != '*' &&
      vis[x][y][id][ans] == 0) {
    return true;
  }
  return false;
}
struct node {
  int x, y, id, step;
  node(int t1, int t2, int t3, int t4) {
    x = t1;
    y = t2;
    id = t3;
    step = t4;
  }
};
queue<node> q;
int main() {
  std::ios::sync_with_stdio(false);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", mp[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[i][j] == 'S') {
        for (int i = 0; i < 4; i++) {
          q.push(node(i, j, i, 0));
          vis[i][j][i][0] = 1;
        }
      }
    }
  }
  while (!q.empty()) {
    node t = q.front();
    q.pop();
    int x = t.x;
    int y = t.y;
    int id = t.id;
    int ans = t.step;
    if (mp[x][y] == 'T') {
      f = 1;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1, i, ans)) {
        int res;
        if (id != i) {
          res = ans + 1;
        } else {
          res = ans;
        }
        if (res <= 2) {
          vis[x1][y1][i][res] = 1;
          q.push(node(x1, y1, i, res));
        }
      }
    }
  }
  if (f == 1) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
