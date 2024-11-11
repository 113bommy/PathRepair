#include <bits/stdc++.h>
using namespace std;
char grid[1001][1001];
bool vis[1001][1001];
int n, m, nos;
struct point {
  int x, y, how;
  point() { x = 0, y = 0, how = 0; }
};
vector<point> result;
bool vaild(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf(" %c", &grid[i][j]);
      nos += (grid[i][j] == '*');
    }
  int have = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '*') {
        if (!vaild(i + 1, j) || !vaild(i - 1, j) || !vaild(i, j + 1) ||
            !vaild(i, j - 1))
          continue;
        if ((grid[i + 1][j] != '*') || (grid[i - 1][j] != '*') ||
            (grid[i][j + 1] != '*') || (grid[i][j - 1] != '*'))
          continue;
        point p;
        int des = !vis[i][j];
        vis[i][j] = 1;
        int can = 0;
        int lU = i, rU = j;
        int lD = i, rD = j;
        int lL = i, rL = j;
        int lR = i, rR = j;
        while (true) {
          lU--, lD++, rL--, rR++;
          if (!vaild(lU, rU) || !vaild(lD, rD) || !vaild(lL, rL) ||
              !vaild(lR, rR))
            break;
          if (grid[lU][rU] != '*' || grid[lD][rD] != '*' ||
              grid[lL][rL] != '*' || grid[lR][rR] != '*')
            break;
          can++;
          des += ((!vis[lU][rU]) + (!vis[lD][rD]) + (!vis[lL][rL]) +
                  (!vis[lR][rR]));
          vis[lU][rU] = 1, vis[lD][rD] = 1, vis[lL][rL] = 1, vis[lR][rR] = 1;
        }
        p.x = i + 1, p.y = j + 1, p.how = can;
        result.push_back(p);
        have += des;
      }
    }
  if (have == nos) {
    printf("%d\n", result.size());
    for (int i = 0; i < result.size(); i++)
      printf("%d %d %d\n", result[i].x, result[i].y, result[i].how);
    return 0;
  }
  puts("-1");
  return 0;
}
