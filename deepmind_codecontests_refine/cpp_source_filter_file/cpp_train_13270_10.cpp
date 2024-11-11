#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const long long INFTIME = 9000ll * 1000 * 1000 * 10;
const int MAXN = 25;
const int MAXV = MAXN * MAXN * 5;
const int MAXE = MAXV * MAXV * 2;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
struct per {
  int x, y;
  long long t;
  int v;
  per(int _x, int _y, int _t, int _v) { x = _x, y = _y, t = _t, v = _v; }
};
int n, m;
pair<int, int> q[MAXN * MAXN];
int q2[MAXV];
int dist[MAXN][MAXN][MAXN][MAXN];
int dis[MAXV], ptr[MAXV];
vector<per> v[2];
int to[MAXE], nex[MAXE], cap[MAXE], head[MAXV];
char t[MAXN][MAXN];
int ecnt = 0, vers = 0;
inline void addEdge(int x, int y, int c) {
  to[ecnt] = y;
  nex[ecnt] = head[x];
  head[x] = ecnt;
  cap[ecnt] = c;
  ecnt++;
  to[ecnt] = x;
  nex[ecnt] = head[y];
  head[y] = ecnt;
  cap[ecnt] = 0;
  ecnt++;
}
inline bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && t[x][y] != '#';
}
inline void bfs(int x, int y) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) dist[x][y][i][j] = INF;
  dist[x][y][x][y] = 0;
  int l = 0, r = 0;
  q[r++] = pair<int, int>(x, y);
  while (l < r) {
    int curx = q[l].first;
    int cury = q[l].second;
    l++;
    for (int dir = 0; dir < 4; dir++) {
      int nx = curx + dx[dir];
      int ny = cury + dy[dir];
      if (valid(nx, ny) && dist[x][y][nx][ny] > dist[x][y][curx][cury] + 1) {
        dist[x][y][nx][ny] = dist[x][y][curx][cury] + 1;
        q[r++] = pair<int, int>(nx, ny);
      }
    }
  }
}
inline bool bfs2(int s, int t) {
  for (int i = 0; i < vers; i++) dis[i] = INF;
  dis[s] = 0;
  int l = 0, r = 0;
  q2[r++] = s;
  while (l < r) {
    int v = q2[l];
    l++;
    for (int i = head[v]; i != -1; i = nex[i])
      if (cap[i ^ 1] > 0) {
        int u = to[i];
        if (dis[u] > dis[v] + 1) {
          dis[u] = dis[v] + 1;
          q2[r++] = u;
        }
      }
  }
  return dis[t] != INF;
}
inline int dinic(int v, int t, int c) {
  if (v == t) return c;
  int ans = 0;
  for (; ptr[v] != -1; ptr[v] = nex[ptr[v]]) {
    if (cap[ptr[v]] > 0) {
      int u = to[ptr[v]];
      if (dis[u] + 1 == dis[v]) {
        int x = dinic(u, t, min(c, cap[ptr[v]]));
        cap[ptr[v]] -= x;
        cap[ptr[v] ^ 1] += x;
        ans += x;
        c -= x;
        if (c == 0) break;
      }
    }
  }
  return ans;
}
inline int maxFlow(int source, int sink) {
  int x;
  int ans = 0;
  while (bfs2(sink, source)) {
    for (int i = 0; i < vers; i++) ptr[i] = head[i];
    ans += dinic(source, sink, INF);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> n >> m >> a >> b;
  if (a - b != 1 && a - b != -1) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> t[i][j];
  int x0, y0, t0;
  cin >> x0 >> y0 >> t0;
  x0--, y0--;
  int source = vers++, sink = vers++;
  if (a < b) {
    v[0].push_back(per(x0, y0, t0, vers));
    vers++;
  } else {
    v[1].push_back(per(x0, y0, t0, vers));
    vers++;
  }
  for (int i = 0; i < a; i++) {
    cin >> x0 >> y0 >> t0;
    x0--, y0--;
    v[0].push_back(per(x0, y0, t0, vers));
    vers++;
  }
  for (int i = 0; i < b; i++) {
    cin >> x0 >> y0 >> t0;
    x0--, y0--;
    v[1].push_back(per(x0, y0, t0, vers));
    vers++;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) bfs(i, j);
  long long lo = -1, hi = INFTIME;
  while (hi - lo > 1) {
    long long mid = (lo + hi) / 2;
    int rvers = vers;
    memset(head, -1, sizeof head);
    ecnt = 0;
    for (int i = 0; i < v[0].size(); i++) addEdge(source, v[0][i].v, 1);
    for (int i = 0; i < v[1].size(); i++) addEdge(v[1][i].v, sink, 1);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (t[i][j] != '#') {
          for (int p = 0; p < v[0].size(); p++)
            if (dist[i][j][v[0][p].x][v[0][p].y] != INF &&
                dist[i][j][v[0][p].x][v[0][p].y] * v[0][p].t <= mid)
              addEdge(v[0][p].v, vers, 1);
          addEdge(vers, vers + 1, 1);
          vers++;
          for (int p = 0; p < v[1].size(); p++)
            if (dist[i][j][v[1][p].x][v[1][p].y] != INF &&
                dist[i][j][v[1][p].x][v[1][p].y] * v[1][p].t <= mid)
              addEdge(vers, v[1][p].v, 1);
          vers++;
        }
    if (maxFlow(source, sink) == v[0].size())
      hi = mid;
    else
      lo = mid;
    vers = rvers;
  }
  if (hi != INFTIME)
    cout << hi << endl;
  else
    cout << -1 << endl;
}
