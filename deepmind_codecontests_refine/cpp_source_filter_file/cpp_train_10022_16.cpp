#include <bits/stdc++.h>
using namespace std;
int n, m, tot = 1;
char s[205][205];
int to[200005], nex[200005], val[200005], head[205 * 205 * 3];
void add(int u, int v, int w) {
  to[++tot] = v;
  val[tot] = w;
  nex[tot] = head[u];
  head[u] = tot;
}
int level[205 * 205 * 3], iter[205 * 205 * 3];
void bfs(int now) {
  for (int i = 1; i <= n * m * 2 + 6; i++) level[i] = -1;
  queue<int> q;
  level[now] = 0;
  q.push(now);
  while (!q.empty()) {
    now = q.front();
    q.pop();
    for (int i = head[now]; i; i = nex[i])
      if (val[i] > 0 && level[to[i]] == -1)
        level[to[i]] = level[now] + 1, q.push(to[i]);
  }
}
int dfs(int u, int v, int flow) {
  if (u == v) return flow;
  for (int &i = iter[u]; i; i = nex[i]) {
    if (val[i] > 0 && level[u] < level[to[i]]) {
      long long res = dfs(to[i], v, min(flow, val[i]));
      if (res > 0) {
        val[i] -= res;
        val[i ^ 1] += res;
        return res;
      }
    }
  }
  return 0;
}
int dinic(int u, int v) {
  int flow = 0;
  while (1) {
    bfs(u);
    if (level[v] == -1) return flow;
    for (int i = 1; i <= n * m * 2 + 6; i++) iter[i] = head[i];
    int f;
    while ((f = dfs(u, v, 123456789)) > 0) flow += f;
  }
}
int getid1(int x, int y) { return (x - 1) * m + y; }
int getid2(int x, int y) { return m * n + (y - 1) * n + x; }
int main() {
  int ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '#') ans++;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++)
      if (s[i][j] == '#') {
        if ((s[i][j + 1] == '#') && (s[i + 1][j] == '#')) {
          int x = getid1(i, j);
          int y = getid2(i, j);
          add(x, y, 1);
          add(y, x, 0);
        }
      }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < m; j++)
      if (s[i][j] == '#') {
        if ((s[i][j + 1] == '#') && (s[i - 1][j] == '#')) {
          int x = getid1(i - 1, j);
          int y = getid2(i, j);
          add(x, y, 1);
          add(y, x, 0);
        }
      }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 2; j <= m; j++)
      if (s[i][j] == '#') {
        if ((s[i][j - 1] == '#') && (s[i + 1][j] == '#')) {
          int x = getid1(i, j);
          int y = getid2(i, j - 1);
          add(x, y, 1);
          add(y, x, 0);
        }
      }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++)
      if (s[i][j] == '#') {
        if ((s[i][j - 1] == '#') && (s[i - 1][j] == '#')) {
          int x = getid1(i - 1, j);
          int y = getid2(i, j - 1);
          add(x, y, 1);
          add(y, x, 0);
        }
      }
  }
  int st = n * m * 2 + 5;
  int ed = st + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++)
      if (s[i][j] == '#') {
        if (s[i][j + 1] == '#') {
          ans--;
          int y = getid2(i, j);
          add(y, ed, 1);
          add(ed, y, 0);
        }
      }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '#') {
        if (s[i + 1][j] == '#') {
          ans--;
          int x = getid1(i, j);
          add(st, x, 1);
          add(x, st, 0);
        }
      }
  }
  printf("%d\n", ans + dinic(st, ed));
}
