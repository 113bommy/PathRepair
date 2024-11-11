#include <bits/stdc++.h>
const int N = 300;
const int M = 3e6;
const int inf = 1e9;
using namespace std;
int n, m, p, a[N + 5][N + 5], dis[N + 5][N + 5], id[N + 5][N + 5], idc,
    q[N * N + 5], dd[N + 5][N + 5], c[N * N + 5], cnt, X[N * N + 5],
    Y[N * N + 5];
int dx[5] = {0, 1, -1, 0, 0}, dy[5] = {0, 0, 0, 1, -1};
vector<pair<int, int> > d[N * N + 5];
vector<pair<int, int> >::iterator it1, it2;
int myabs(int x) { return x < 0 ? -x : x; }
int dist(int u, int v, int x, int y) { return myabs(v - y) + myabs(x - u); }
bool cmp(int x, int y) { return dis[X[x]][Y[x]] < dis[X[y]][Y[y]]; }
void bfs(int x) {
  int l = 1, r = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) dd[i][j] = inf;
  cnt = 0;
  for (it1 = d[x].begin(); it1 != d[x].end(); it1++)
    c[++cnt] = id[(*it1).first][(*it1).second];
  sort(c + 1, c + cnt + 1, cmp);
  int pos = 1;
  dd[X[c[pos]]][Y[c[pos]]] = dis[X[c[pos]]][Y[c[pos]]];
  q[++r] = c[pos++];
  while (l <= r) {
    int u = q[l++];
    while (pos <= cnt && dis[X[c[pos]]][Y[c[pos]]] == dd[X[u]][Y[u]]) {
      if (dd[X[c[pos]]][Y[c[pos]]] == inf)
        dd[X[c[pos]]][Y[c[pos]]] = dis[X[c[pos]]][Y[c[pos]]], q[++r] = c[pos++];
      else
        pos++;
    }
    for (int i = 1; i <= 4; i++) {
      int xx = X[u] + dx[i], yy = Y[u] + dy[i];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && dd[xx][yy] == inf) {
        dd[xx][yy] = dd[X[u]][Y[u]] + 1;
        if (a[xx][yy] == x + 1) dis[xx][yy] = dd[xx][yy];
        q[++r] = id[xx][yy];
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      d[a[i][j]].push_back(make_pair(i, j));
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      id[i][j] = ++idc;
      X[idc] = i;
      Y[idc] = j;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 1)
        dis[i][j] = i + j - 2;
      else
        dis[i][j] = inf;
  for (int i = 1; i < p; i++) {
    if (d[i].size() * d[i + 1].size() <= n * m) {
      for (it1 = d[i].begin(); it1 != d[i].end(); it1++) {
        int u = (*it1).first, v = (*it1).second;
        for (it2 = d[i + 1].begin(); it2 != d[i + 1].end(); it2++) {
          int x = (*it2).first, y = (*it2).second;
          dis[x][y] = min(dis[x][y], dis[u][v] + dist(u, v, x, y));
        }
      }
    } else
      bfs(i);
  }
  cout << dis[d[p][0].first][d[p][0].second] << endl;
  return 0;
}
