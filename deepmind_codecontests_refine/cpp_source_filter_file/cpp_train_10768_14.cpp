#include <bits/stdc++.h>
using namespace std;
namespace Dinic {
const int MAXN = 15000;
const int inf = 1e9;
vector<pair<int, int> > E[MAXN];
vector<int> cap[MAXN];
int dist[MAXN];
int bio[MAXN];
int sh[MAXN];
int cookie, s, t;
queue<int> Q;
int bfs() {
  cookie++;
  while (!Q.empty()) Q.pop();
  bio[s] = cookie;
  dist[s] = 0;
  Q.push(s);
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (int i = 0; i < (int)E[x].size(); ++i) {
      int y = E[x][i].first;
      if ((bio[y] != cookie || y == t) && cap[x][i] != 0) {
        dist[y] = dist[x] + 1;
        bio[y] = cookie;
        if (y != t) Q.push(y);
      }
    }
  }
  return bio[t] == cookie;
}
int augment(int x, int c) {
  if (x == t) return c;
  for (int i = sh[x]; i < (int)E[x].size(); ++i, ++sh[x]) {
    int y = E[x][i].first;
    if (cap[x][i] > 0 && bio[y] == cookie &&
        (y == t || dist[y] == dist[x] + 1)) {
      int v = augment(y, c = min(c, cap[x][i]));
      if (v > 0) {
        cap[x][i] -= v, cap[y][E[x][i].second] += v;
        return v;
      }
    }
  }
  return 0;
}
void addEdge(int a, int first, int cab, int cba) {
  E[a].push_back(pair<int, int>(first, E[first].size()));
  E[first].push_back(pair<int, int>(a, E[a].size() - 1));
  cap[a].push_back(cab);
  cap[first].push_back(cba);
}
int maxflow(int S, int T) {
  s = S, t = T;
  int ans = 0;
  while (bfs()) {
    int f;
    memset(sh, 0, (T + 1) * 4);
    while ((f = augment(s, inf))) ans += f;
  }
  return ans;
}
};  // namespace Dinic
const int MAXV = 1e6;
const int MAXN = 110;
int a[MAXN], first[MAXN], c[MAXN];
int l[MAXN], r[MAXN];
int v[MAXN][220];
int x[MAXN], y[MAXN], second[MAXN];
int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < (n); ++i) scanf("%d %d %d", a + i, first + i, c + i);
  int cnt = 0;
  for (int i = 0; i < (n); ++i) {
    scanf("%d %d", l + i, r + i);
    l[i] += 101, r[i] += 101;
    for (int j = l[i] - 1; j <= r[i]; ++j) v[i][j] = cnt++;
  }
  int s = cnt++, t = cnt++;
  for (int i = 0; i < (m); ++i) {
    scanf("%d %d %d", x + i, y + i, second + i);
    --x[i], --y[i];
  }
  for (int i = 0; i < (m); ++i)
    for (int j = l[x[i]] - 1; j < r[x[i]]; ++j)
      if (j - second[i] > l[y[i]] && j - second[i] <= r[y[i]])
        Dinic::addEdge(v[x[i]][j], v[y[i]][j - second[i]], Dinic::inf, 0);
  for (int i = 0; i < (n); ++i) {
    for (int j = l[i]; j <= r[i]; ++j) {
      int f = j - 101;
      Dinic::addEdge(v[i][j - 1], v[i][j],
                     MAXV - (a[i] * f * f + first[i] * f + c[i]), 0);
    }
    Dinic::addEdge(s, v[i][l[i] - 1], Dinic::inf, 0);
    Dinic::addEdge(v[i][r[i]], t, Dinic::inf, 0);
  }
  int ans = n * MAXV - Dinic::maxflow(s, t);
  printf("%d\n", ans);
  return 0;
}
