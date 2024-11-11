#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
typedef struct p {
  long long int x, y, cost;
  p(long long int _x, long long int _y, long long int _cost)
      : x(_x), y(_y), cost(_cost) {}
  p() : x(0), y(0), cost(0) {}
} Obj;
long long int n, m, dp[21][21][257], startx, starty, cTre = 0, cObj = 0;
Obj object[10];
char table[22][22];
long long int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
long long int bfs() {
  queue<Obj> nodes;
  long long int x, y, mask, k, xx, yy, i, m2, ans = 0;
  nodes.push(Obj(startx, starty, 0));
  memset(dp, -1, sizeof dp);
  dp[startx][starty][0] = 0;
  while (!nodes.empty()) {
    x = nodes.front().x;
    y = nodes.front().y;
    mask = nodes.front().cost;
    nodes.pop();
    for (k = 0; k < 4; k++) {
      xx = x + dx[k];
      yy = y + dy[k];
      m2 = mask;
      if (!(xx >= 1 && xx <= n && yy >= 1 && yy <= m &&
            (table[xx][yy] == '.' || table[xx][yy] == 'S')))
        continue;
      for (i = 0; i < cObj; i++)
        if (object[i].x < xx && object[i].y >= min(yy, y) &&
            object[i].y < max(y, yy))
          m2 ^= (1 << i);
      if (dp[xx][yy][m2] == -1) {
        dp[xx][yy][m2] = dp[x][y][mask] + 1;
        nodes.push(Obj(xx, yy, m2));
      }
    }
  }
  long long int limit = 1 << cObj;
  for (i = 0; i < limit; i++) {
    m2 = -dp[startx][starty][i];
    if (1) {
      for (k = 0; k < cObj; k++) m2 += object[k].cost * ((i >> k) & 1);
      ans = max(ans, m2);
    }
  }
  return ans;
}
int main() {
  long long int i, j;
  scanf("%lld %lld", &n, &m);
  for (i = 1; i <= n; i++) scanf("%s", table[i] + 1);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (table[i][j] == 'S') startx = i, starty = j;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      if ('1' <= table[i][j] && table[i][j] <= '9')
        object[table[i][j] - '1'] = Obj(i, j, 0), cTre++;
    }
  cObj = cTre;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      if (table[i][j] == 'B') object[cObj++] = Obj(i, j, -INT_MIN);
    }
  for (i = 0; i < cTre; i++) scanf("%lld", &object[i].cost);
  printf("%lld\n", bfs());
}
