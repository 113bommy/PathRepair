#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
char a[1005][1005];
int n, m;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int b[1005][1005];
int vis[105][1005];
struct node {
  int x, y;
};
int vis4[1000010];
vector<node> ans;
int count1, count2;
char c[1005][1005];
int d[1005][1005];
bool inside(int x, int y) {
  if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
  return 0;
}
int sum;
node tmp;
void dfs(int x, int y) {
  int xx, yy;
  tmp.x = x;
  tmp.y = y;
  sum = (sum + 1) % 10;
  ans.push_back(tmp);
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    xx = x + dir[i][0];
    yy = y + dir[i][1];
    if (vis[xx][yy]) continue;
    if (inside(xx, yy) == 0 || a[xx][yy] == '*') continue;
    dfs(xx, yy);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
  }
  int count = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j] && a[i][j] == '.') {
        ans.clear();
        sum = 0;
        dfs(i, j);
        for (int k = 0; k < ans.size(); k++) {
          b[ans[k].x][ans[k].y] = sum % 10;
          d[ans[k].x][ans[k].y] = count;
        }
        count++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.') {
        c[i][j] = '.';
      } else {
        c[i][j] = 1;
        ans.clear();
        for (int k = 0; k < 4; k++) {
          int xx = i + dir[k][0];
          int yy = j + dir[k][1];
          if (!inside(xx, yy)) continue;
          if (!vis4[d[xx][yy]]) {
            tmp.x = xx;
            tmp.y = yy;
            ans.push_back(tmp);
            vis4[d[xx][yy]] = 1;
            c[i][j] = (c[i][j] + b[xx][yy]) % 10;
          }
        }
        for (int kk = 0; kk < ans.size(); kk++) {
          vis4[d[ans[kk].x][ans[kk].y]] = 0;
        }
        c[i][j] += '0';
      }
    }
    c[i][m + 1] = '\0';
  }
  for (int i = 1; i <= n; i++) {
    printf("%s\n", c[i] + 1);
  }
}
