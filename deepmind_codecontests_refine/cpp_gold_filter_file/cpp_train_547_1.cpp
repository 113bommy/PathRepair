#include <bits/stdc++.h>
using namespace std;
int n, m, dep, top, cnt, bel[20010], low[20010], dfn[20010], vis[20010],
    sta[20010], du[20010], pos[20010], p[20010], a[110][110];
vector<int> vec[20010], fv[20010];
int id(int x, int y) { return (x - 1) * m + y; }
void calc(int x, int y, int x1, int y1) {
  if (a[x][y] == a[x1][y1]) vec[id(x, y)].push_back(id(x1, y1) + n * m);
  if (a[x][y] == a[x1][y1] + 1) vec[id(x, y)].push_back(id(x1, y1));
  if (a[x][y] + 1 == a[x1][y1])
    vec[id(x, y) + n * m].push_back(id(x1, y1) + n * m);
  if (a[x][y] + 1 == a[x1][y1] + 1) vec[id(x, y) + n * m].push_back(id(x1, y1));
}
void tarjan(int x) {
  dfn[x] = low[x] = ++dep;
  sta[++top] = x;
  vis[x] = 1;
  for (int i = 0; i < vec[x].size(); i++) {
    int to = vec[x][i];
    if (!dfn[to]) {
      tarjan(to);
      low[x] = min(low[x], low[to]);
    } else if (vis[to])
      low[x] = min(low[x], dfn[to]);
  }
  if (dfn[x] == low[x]) {
    int j;
    cnt++;
    do {
      j = sta[top--];
      vis[j] = 0;
      bel[j] = cnt;
    } while (j != x);
  }
}
void sol() {
  memset(dfn, 0, sizeof(dfn));
  memset(bel, 0, sizeof(bel));
  memset(low, 0, sizeof(low));
  memset(vis, 0, sizeof(vis));
  memset(pos, 0, sizeof(pos));
  memset(du, 0, sizeof(du));
  cnt = top = dep = 0;
  for (int i = 1; i <= n * m * 2; i++) {
    if (!dfn[i]) tarjan(i);
  }
  for (int i = 1; i <= n * m; i++) {
    pos[bel[i]] = bel[i + n * m];
    pos[bel[i + n * m]] = bel[i];
  }
  for (int i = 1; i <= n * m * 2; i++)
    for (int j = 0; j < vec[i].size(); j++) {
      int to = vec[i][j];
      if (bel[i] != bel[to]) fv[bel[to]].push_back(bel[i]), du[bel[i]]++;
    }
  for (int i = 1; i <= cnt; i++) p[i] = 0;
  queue<int> q;
  for (int i = 1; i <= cnt; i++)
    if (!du[i]) q.push(i);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (!p[x]) {
      p[x] = 1;
      p[pos[x]] = 2;
    }
    for (int i = 0; i < fv[x].size(); i++) {
      int to = fv[x][i];
      if (--du[to] == 0) q.push(to);
    }
  }
  int x, y;
  for (int i = 1; i <= n * m; i++) {
    if (p[bel[i]] == 2) {
      x = i / m + 1;
      y = i % m;
      if (y == 0) y = m, x--;
      a[x][y]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << a[i][j] << " ";
    cout << endl;
  }
}
int main() {
  int qt;
  cin >> qt;
  while (qt--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m * 2; i++) {
      vec[i].clear();
      fv[i].clear();
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (j + 1 <= m) calc(i, j, i, j + 1);
        if (j - 1 > 0) calc(i, j, i, j - 1);
        if (i + 1 <= n) calc(i, j, i + 1, j);
        if (i - 1 > 0) calc(i, j, i - 1, j);
      }
    sol();
  }
}
