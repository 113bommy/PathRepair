#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
const int X = 25;
const int N = X * X * 4 + 20;
const int E = N * X * X;
const int MOD = 1e9 + 7;
const long double eps = 1e-12;
int n, m, male, female, vcnt, ecnt;
int from[E], to[E], prv[E], head[N], cap[E], d[N];
long long length[E], limit;
bool mark[N];
pair<int, int> vert[N];
int dist[X][X][X][X];
int dx[4] = {+1, -1, +0, -0};
int dy[4] = {+0, -0, +1, -1};
char tab[X][X];
bool isav(int x, int y) {
  return (0 <= x) && (x < n) && (0 <= y) && (y < m) && (tab[x][y] == '.');
}
void floyd() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      dist[i][j][i][j] = 0;
      for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (isav(ni, nj)) dist[i][j][ni][nj] = 1;
      }
    }
  for (int i1 = 0; i1 < n; i1++)
    for (int j1 = 0; j1 < m; j1++)
      for (int i2 = 0; i2 < n; i2++)
        for (int j2 = 0; j2 < m; j2++)
          for (int i3 = 0; i3 < n; i3++)
            for (int j3 = 0; j3 < m; j3++)
              dist[i2][j2][i3][j3] =
                  min(dist[i2][j2][i1][j1] + dist[i1][j1][i3][j3],
                      dist[i2][j2][i3][j3]);
}
void add_edge(int u, int v, long long len) {
  from[ecnt] = u, to[ecnt] = v, cap[ecnt] = 1, length[ecnt] = len,
  prv[ecnt] = head[u], head[u] = ecnt++;
  from[ecnt] = v, to[ecnt] = u, cap[ecnt] = 0, length[ecnt] = len,
  prv[ecnt] = head[v], head[v] = ecnt++;
}
bool bfs(int u, int v) {
  memset(d, 63, sizeof(d));
  d[u] = 0;
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i != -1; i = prv[i])
      if (length[i] <= limit && cap[i] && d[to[i]] > d[x] + 1) {
        d[to[i]] = d[x] + 1;
        q.push(to[i]);
      }
  }
  return (d[v] < MOD);
}
int dfs(int u, int sink, int f) {
  if (u == sink) return f;
  if (mark[u]) return 0;
  mark[u] = 1;
  int i = head[u];
  int ans = 0;
  for (; i != -1; i = prv[i])
    if (length[i] <= limit && d[u] + 1 == d[to[i]] && (cap[i] > 0)) {
      int x = dfs(to[i], sink, min(f, cap[i]));
      cap[i] -= x;
      cap[i ^ 1] += x;
      ans += x;
      f -= x;
      if (f == 0) break;
    }
  return ans;
}
bool solve(int source, int sink) {
  int ans = 0;
  memset(mark, 0, sizeof(mark));
  while (bfs(source, sink)) {
    int x = dfs(source, sink, MOD);
    ans += x;
    memset(mark, 0, sizeof(mark));
  }
  return (ans >= male);
}
int main() {
  memset(dist, 63, sizeof(dist));
  memset(head, -1, sizeof(head));
  n = in();
  m = in();
  male = in();
  female = in();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      scanf(" %c", &c);
      tab[i][j] = c;
      if (c == '.') {
        add_edge(vcnt, vcnt + 1, 0);
        vert[vcnt++] = {i, j};
        vert[vcnt++] = {i, j};
      }
    }
  if (abs(female - male) != 1) return cout << -1, 0;
  int cnt = 0;
  floyd();
  int s = vcnt;
  int source = vcnt++;
  int sink = vcnt++;
  int r = in(), c = in(), speed = in();
  r--, c--;
  if (male < female) {
    add_edge(source, vcnt, 0);
    for (int j = 0; j < s; j += 2) {
      if (dist[r][c][vert[j].first][vert[j].second] > MOD) continue;
      long long len = dist[r][c][vert[j].first][vert[j].second];
      len *= speed;
      add_edge(vcnt, j, len);
    }
  } else {
    add_edge(vcnt, sink, 0);
    for (int j = 1; j < s; j += 2) {
      if (dist[r][c][vert[j].first][vert[j].second] > MOD) continue;
      long long len = dist[r][c][vert[j].first][vert[j].second];
      len *= speed;
      add_edge(j, vcnt, len);
    }
  }
  vcnt++;
  for (int i = 0; i < male; i++, vcnt++) {
    int r = in(), c = in(), speed = in();
    r--, c--;
    add_edge(source, vcnt, 0);
    for (int j = 0; j < s; j += 2) {
      if (dist[r][c][vert[j].first][vert[j].second] > MOD) continue;
      long long len = dist[r][c][vert[j].first][vert[j].second];
      len *= speed;
      add_edge(vcnt, j, len);
    }
  }
  for (int i = 0; i < female; i++, vcnt++) {
    int r = in(), c = in(), speed = in();
    r--, c--;
    add_edge(vcnt, sink, 0);
    for (int j = 1; j < s; j += 2) {
      if (dist[r][c][vert[j].first][vert[j].second] > MOD) continue;
      long long len = dist[r][c][vert[j].first][vert[j].second];
      len *= speed;
      add_edge(j, vcnt, len);
    }
  }
  if (female < male)
    female++;
  else
    male++;
  long long st = -1, e = 1e11;
  limit = e;
  if (!solve(source, sink)) return cout << -1, 0;
  while (e - st > 1) {
    limit = (e + st) / 2;
    for (int i = 0; i < ecnt; i += 2) cap[i] = 1;
    for (int i = 1; i < ecnt; i += 2) cap[i] = 0;
    if (solve(source, sink))
      e = limit;
    else
      st = limit;
  }
  cout << e;
  return 0;
}
