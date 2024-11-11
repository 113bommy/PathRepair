#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0;
  char c;
  bool flag = true;
  c = getchar();
  while (!isdigit(c)) {
    if (c == '-') flag = false;
    c = getchar();
  }
  while (isdigit(c)) {
    res = res * 10 + (c ^ 48);
    c = getchar();
  }
  return flag ? res : -res;
}
const int Max_n = 55;
char c[Max_n][Max_n];
int n, m, tmp, ans = 0x3f3f3f3f, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0},
               dis[Max_n][Max_n];
int con[Max_n][Max_n][Max_n][Max_n];
struct node {
  int x, y;
  node(int a, int b) { x = a, y = b; }
  node() {}
};
vector<node> v[Max_n][Max_n];
bool vis[Max_n][Max_n];
int main() {
  n = read(), m = read();
  for (int i = 0; i < n; ++i) scanf("%s", c[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int k = 0; k < 4; ++k) {
        int nexi = i + dx[k], nexj = j + dy[k];
        if (nexi < 0 || nexi >= n || nexj < 0 || nexj >= n) continue;
        v[i][j].push_back((node){nexi, nexj});
      }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      memset(dis, 0x3f3f3f3f, sizeof(dis));
      memset(vis, false, sizeof(vis));
      tmp = 0;
      dis[i][j] = 1;
      deque<node> q;
      q.push_front(node(i, j));
      while (!q.empty()) {
        node now = q.front();
        q.pop_front();
        if (vis[now.x][now.y]) continue;
        vis[now.x][now.y] = true;
        if (c[now.x][now.y] == 'B') tmp = max(tmp, dis[now.x][now.y]);
        int sz = v[now.x][now.y].size();
        for (int i = 0; i < sz; ++i) {
          node nex = v[now.x][now.y][i];
          if (vis[nex.x][nex.y]) continue;
          dis[nex.x][nex.y] =
              min(dis[nex.x][nex.y],
                  dis[now.x][now.y] + (c[now.x][now.y] != c[nex.x][nex.y]));
          c[now.x][now.y] != c[nex.x][nex.y] ? q.push_back(nex)
                                             : q.push_front(nex);
        }
      }
      ans = min(ans, tmp);
    }
  printf("%d", ans);
  return 0;
}
