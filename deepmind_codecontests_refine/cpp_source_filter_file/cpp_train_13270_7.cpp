#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x > y ? y : x;
}
const int inf = 1e9;
template <typename T>
void read(T &x) {
  x = 0;
  bool f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = 0;
  } while (ch > '9' || ch < '0');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  x = f ? x : -x;
}
template <typename T>
void write(T x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 22 + 5;
const int K = 3000 + 5;
const int M = 1e6 + 7;
struct Node {
  int x, y, t;
} A[K], B[K], C;
struct EDGE {
  int to, nxt, cap;
} edge[M << 1];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int r, c, n, m, s, t, E, dep[K], head[K], backup[K];
long long L, R, ans, dis[N][N][N][N];
char ch[N][N];
inline void addedge(int u, int v, int cap) {
  edge[++E].to = v;
  edge[E].nxt = head[u];
  edge[E].cap = cap;
  head[u] = E;
  backup[u] = head[u];
}
inline void Add(int u, int v, int w) {
  addedge(u, v, w);
  addedge(v, u, 0);
}
inline int HASHA(int a) { return a - 1; }
inline int HASHB(int a, int b) { return n + (a - 1) * c + b - 1; }
inline int HASHC(int a, int b) { return n + r * c + (a - 1) * c + b - 1; }
inline int HASHD(int a) { return n + 2 * r * c + a - 1; }
inline int dfs(int u, int t, int limit) {
  if (!limit || u == t) return limit;
  int flow = 0;
  for (int &i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to, f = edge[i].cap;
    if (dep[v] == dep[u] + 1 && (f = dfs(v, t, min(limit, f))) > 0) {
      limit -= f;
      flow += f;
      edge[i ^ 1].cap += f;
      edge[i].cap -= f;
      if (!limit) break;
    }
  }
  return flow;
}
inline bool BFS(int s, int t, int n) {
  for (int i = 0; i <= n; i++) dep[i] = inf, head[i] = backup[i];
  queue<int> q;
  q.push(s);
  dep[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = edge[i].nxt) {
      int v = edge[i].to, w = edge[i].cap;
      if (dep[v] != inf || !w) continue;
      dep[v] = dep[u] + 1;
      q.push(v);
    }
  }
  return dep[t] != inf;
}
inline int Dinic(int s, int t, int n) {
  int maxflow = 0;
  while (BFS(s, t, n)) maxflow += dfs(s, t, inf);
  return maxflow;
}
inline void build(long long NOW) {
  E = 1;
  memset(head, 0, sizeof(head));
  s = HASHD(m) + 1, t = s + 1;
  for (int i = 1; i <= n; i++) {
    Add(s, HASHA(i), 1);
    for (int x = 1; x <= r; x++) {
      for (int y = 1; y <= c; y++) {
        if (dis[A[i].x][A[i].y][x][y] < inf &&
            1ll * dis[A[i].x][A[i].y][x][y] * A[i].t <= NOW) {
          Add(HASHA(i), HASHB(x, y), 1);
        }
      }
    }
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (ch[i][j] == '.') Add(HASHB(i, j), HASHC(i, j), 1);
    }
  }
  for (int i = 1; i <= m; i++) {
    Add(HASHD(i), t, 1);
    for (int x = 1; x <= r; x++) {
      for (int y = 1; y <= c; y++) {
        if (dis[B[i].x][B[i].y][x][y] < inf &&
            1ll * dis[B[i].x][B[i].y][x][y] * B[i].t <= NOW) {
          Add(HASHC(x, y), HASHD(i), 1);
        }
      }
    }
  }
}
inline bool check(int x) {
  build(x);
  return Dinic(s, t, t) == m;
}
inline void pre() {
  for (int A = 1; A <= r; A++)
    for (int B = 1; B <= c; B++)
      for (int C = 1; C <= r; C++)
        for (int D = 1; D <= c; D++) dis[A][B][C][D] = inf;
  for (int x = 1; x <= r; x++) {
    for (int y = 1; y <= c; y++) {
      if (ch[x][y] == '#') continue;
      dis[x][y][x][y] = 0;
      for (int a = 0; a < 4; a++) {
        int sx = x + dx[a], sy = y + dy[a];
        if (sx < 1 || sx > r || sy < 1 || sy > c || ch[sx][sy] == '#') continue;
        dis[x][y][sx][sy] = 1;
      }
    }
  }
  for (int kx = 1; kx <= r; kx++) {
    for (int ky = 1; ky <= c; ky++) {
      if (ch[kx][ky] == '#') continue;
      for (int ix = 1; ix <= r; ix++) {
        for (int iy = 1; iy <= c; iy++) {
          if (ch[ix][iy] == '#' || dis[ix][iy][kx][ky] == inf) continue;
          for (int jx = 1; jx <= r; jx++) {
            for (int jy = 1; jy <= c; jy++) {
              if (ch[jx][jy] == '#' || dis[kx][ky][jx][jy] == inf) continue;
              dis[ix][iy][jx][jy] =
                  min(dis[ix][iy][jx][jy],
                      dis[ix][iy][kx][ky] + dis[kx][ky][jx][jy]);
            }
          }
        }
      }
    }
  }
}
inline void solve() {
  if (n != m) return (void)puts("-1");
  L = 0;
  R = 1e12;
  ans = 1e12;
  while (L <= R) {
    long long mid = (L + R) >> 1;
    if (check(mid))
      R = mid - 1, ans = mid;
    else
      L = mid + 1;
  }
  printf("%lld\n", ans == 1e12 ? -1 : ans);
}
signed main() {
  read(r);
  read(c);
  read(n);
  read(m);
  for (int i = 1; i <= r; i++) scanf("%s", ch[i] + 1);
  read(C.x);
  read(C.y);
  read(C.t);
  for (int i = 1; i <= n; i++) read(A[i].x), read(A[i].y), read(A[i].t);
  for (int i = 1; i <= m; i++) read(B[i].x), read(B[i].y), read(B[i].t);
  if (n > m)
    B[++m] = C;
  else
    A[++n] = C;
  pre();
  solve();
  return 0;
}
