#include <bits/stdc++.h>
using namespace std;
const int N = 25;
const int V = N * N * 4 + 7;
const int E = V * N * N;
const int INF = 1e9 + 7;
int from[E], to[E], cap[E], prv[E];
int head[V], ptr[V], ecnt;
int d[V], q[V];
string s[N];
int r[V], c[V], t[V];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int dis[N][N][N][N];
int n, m, M, F;
void add_edge(int u, int v, int uv, int vu = 0) {
  from[ecnt] = u, to[ecnt] = v, cap[ecnt] = uv, prv[ecnt] = head[u],
  head[u] = ecnt++;
  from[ecnt] = v, to[ecnt] = u, cap[ecnt] = vu, prv[ecnt] = head[v],
  head[v] = ecnt++;
}
bool bfs(int source, int sink) {
  memset(d, 63, sizeof d);
  d[source] = 0;
  int h = 0, t = 0;
  q[t++] = source;
  while (h < t) {
    int v = q[h++];
    for (int i = head[v]; i != -1; i = prv[i])
      if (cap[i] && d[to[i]] > d[v] + 1) {
        d[to[i]] = d[v] + 1;
        q[t++] = to[i];
      }
  }
  return d[sink] <= 1e9;
}
int dfs(int v, int sink, int f = INF) {
  if (v == sink) return f;
  int out = 0;
  for (; ptr[v] != -1; ptr[v] = prv[ptr[v]])
    if (d[to[ptr[v]]] == d[v] + 1) {
      int x = dfs(to[ptr[v]], sink, min(f, cap[ptr[v]]));
      cap[ptr[v]] -= x;
      cap[ptr[v] ^ 1] += x;
      out += x;
      f -= x;
      if (f == 0) break;
    }
  return out;
}
int maxflow(int source, int sink) {
  int out = 0;
  while (bfs(source, sink)) {
    memcpy(ptr, head, sizeof head);
    out += dfs(source, sink);
  }
  return out;
}
bool valid(int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m && s[r][c] == '.';
}
void floyd() {
  memset(dis, 63, sizeof dis);
  for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++)
      if (valid(r, c)) {
        dis[r][c][r][c] = 0;
        for (int i = 0; i < 4; i++) {
          int R = r + dr[i];
          int C = c + dc[i];
          if (valid(R, C)) dis[r][c][R][C] = 1;
        }
      }
  for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++)
      if (valid(r, c))
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++)
            if (valid(i, j))
              for (int x = 0; x < n; x++)
                for (int y = 0; y < m; y++)
                  if (valid(x, y))
                    dis[i][j][x][y] =
                        min(dis[i][j][x][y], dis[i][j][r][c] + dis[r][c][x][y]);
}
bool isaac(long long k) {
  int source = V - 1, sink = V - 2;
  memset(head, -1, sizeof head);
  ecnt = 0;
  for (int i = 0; i < F + M; i++) {
    for (int x = 0; x < n; x++)
      for (int y = 0; y < m; y++)
        if (valid(x, y) && dis[r[i]][c[i]][x][y] <= 1e9 &&
            1LL * dis[r[i]][c[i]][x][y] * t[i] <= k) {
          if (i < M)
            add_edge(i, F + M + 2 * (x * m + y), 1);
          else
            add_edge(F + M + ((2 * (x * m + y)) ^ 1), i, 1);
        }
    if (i < M)
      add_edge(source, i, 1);
    else
      add_edge(i, sink, 1);
  }
  for (int x = 0; x < n; x++)
    for (int y = 0; y < m; y++)
      add_edge(F + M + 2 * (x * m + y), F + M + ((2 * (x * m + y)) ^ 1), 1);
  return maxflow(source, sink) == M;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> M >> F;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < M + F + 1; i++) {
    cin >> r[i] >> c[i] >> t[i];
    r[i]--, c[i]--;
  }
  if (M == F + 1) {
    swap(r[0], r[M]);
    swap(c[0], c[M]);
    swap(t[0], t[M]);
    F++;
  } else if (F == M + 1)
    M++;
  else {
    cout << "-1\n";
    return 0;
  }
  floyd();
  long long lb = -1, ub = 1e12;
  while (ub - lb > 1) {
    long long mid = (lb + ub) / 2;
    if (isaac(mid))
      ub = mid;
    else
      lb = mid;
  }
  cout << (ub <= 1e12 ? ub : -1) << "\n";
  return 0;
}
