#include <bits/stdc++.h>
using namespace std;
char cells[1005][1005];
int visited[1005][1005];
int res[1005 * 1005];
int n, m;
int cnt;
struct P {
  int x, y;
  P(int xx = 0, int yy = 0) : x(xx), y(yy){};
};
int moves[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void DFS(P start) {
  visited[start.x][start.y] = cnt;
  res[cnt]++;
  for (int i = 0; i < 4; ++i) {
    P tmp = start;
    tmp.x += moves[i][0];
    tmp.y += moves[i][1];
    if (!visited[tmp.x][tmp.y] && cells[tmp.x][tmp.y] == '.' && tmp.x > 0 &&
        tmp.x <= n && tmp.y > 0 && tmp.y <= m) {
      DFS(tmp);
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  memset(cells, 0, sizeof(cells));
  memset(visited, 0, sizeof(visited));
  memset(res, 0, sizeof(res));
  for (int i = 1; i <= n; ++i) {
    scanf("%s", cells[i] + 1);
  }
  cnt = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (visited[i][j] == 0 && cells[i][j] == '.') {
        cnt++;
        DFS(P(i, j));
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (cells[i][j] == '.') {
        printf(".");
      } else {
        int ans = 1;
        set<int> s;
        for (int k = 0; k < 4; ++k) {
          s.insert(visited[i + moves[k][0]][j + moves[k][1]]);
        }
        for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
          ans += res[*it];
          ans %= 10;
        }
        printf("%d", ans);
      }
    }
    printf("\n");
  }
  return 0;
}
