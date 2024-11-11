#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &x) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), x = 0; c >= '0' && c <= '9';
       c = getchar())
    x = (x << 1) + (x << 3) + c - '0';
  if (sg) x = -x;
}
template <class T, class T1>
inline void gn(T &x, T1 &y) {
  gn(x);
  gn(y);
}
template <class T, class T1, class T2>
inline void gn(T &x, T1 &y, T2 &z) {
  gn(x);
  gn(y);
  gn(z);
}
template <class T>
inline void print(T x) {
  if (x < 0) {
    putchar('-');
    return print(-x);
  }
  if (x < 10) {
    putchar('0' + x);
    return;
  }
  print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void printsp(T x) {
  print(x);
  putchar(' ');
}
template <class T>
inline void println(T x) {
  print(x);
  putchar('\n');
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int dist[11111], head[11111], work[11111];
int cap[2222222], nxt[2222222], to[2222222], q[2222222];
int src, tar, V, E, qf, qb;
char grid[11111][11111];
int dis[22][22][22][22];
int fx[11111], fy[11111], mx[11111], my[11111], tf[11111], tmm[11111];
int init(int n) {
  memset(head, -1, sizeof(head));
  E = 0, V = n;
}
int add(int u, int v, int c) {
  to[E] = v, nxt[E] = head[u], head[u] = E, cap[E++] = c;
  to[E] = u, nxt[E] = head[v], head[v] = E, cap[E++] = 0;
}
bool bfs() {
  memset(dist, -1, sizeof(dist));
  qf = qb = 0, dist[src] = 0;
  q[qb++] = src;
  while (qf < qb && dist[tar] == -1) {
    int u = q[qf++];
    for (int e = head[u]; e >= 0; e = nxt[e]) {
      int v = to[e];
      if (dist[v] == -1 && cap[e] > 0) dist[v] = dist[u] + 1, q[qb++] = v;
    }
  }
  return dist[tar] >= 0;
}
int dfs(int u, int &bot) {
  int bot1, delta;
  if (u == tar) return bot;
  for (int &e = work[u]; e >= 0; e = nxt[e]) {
    int v = to[e];
    if (dist[v] == dist[u] + 1 && cap[e] > 0) {
      bot1 = min(bot, cap[e]);
      if (delta = dfs(v, bot1)) {
        cap[e] -= delta;
        cap[e ^ 1] += delta;
        bot = bot1;
        return delta;
      }
    }
  }
  return 0;
}
int dinic() {
  int ans = 0, delta, bot;
  while (bfs()) {
    memcpy(work, head, sizeof(int) * (V + 10));
    while (delta = dfs(src, bot = 1000000000)) ans += delta;
  }
  return ans;
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
  int N, M, r, c, t, n1, n2;
  cin >> N >> M >> n1 >> n2;
  for (int i = 0; i < N; i++) scanf("%s", grid[i]);
  memset(dis, -1, sizeof(dis));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == '#') continue;
      dis[i][j][i][j] = 0;
      qf = qb = 0;
      q[qb++] = i, q[qb++] = j;
      while (qf < qb) {
        int ux = q[qf++];
        int uy = q[qf++];
        for (int k = 0; k < 4; k++) {
          int vx = ux + dx[k];
          int vy = uy + dy[k];
          if ((vx < 0 || vy < 0 || vx >= N || vy >= M)) continue;
          if (grid[vx][vy] == '#') continue;
          if (dis[i][j][vx][vy] >= 0) continue;
          dis[i][j][vx][vy] = dis[i][j][ux][uy] + 1;
          q[qb++] = vx, q[qb++] = vy;
        }
      }
    }
  cin >> r >> c >> t;
  if (n1 != n2 + 1 && n2 != n1 + 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n1; i++) scanf("%d%d%d", mx + i, my + i, tmm + i);
  for (int i = 1; i <= n2; i++) scanf("%d%d%d", fx + i, fy + i, tf + i);
  if (n1 > n2)
    fx[++n2] = r, fy[n2] = c, tf[n2] = t;
  else
    mx[++n1] = r, my[n1] = c, tmm[n1] = t;
  long long st = -1, ed = 100000000000000LL;
  bool ok = 0;
  while (ed - st > 1) {
    long long md = st + ed >> 1;
    src = 0;
    tar = n1 + n2 + 1;
    init(tar + 2 * N * M);
    for (int i = 1; i <= n1; i++) {
      add(src, i, 1);
      int ux = mx[i] - 1;
      int uy = my[i] - 1;
      for (int j = 0; j < N; j++)
        for (int k = 0; k < M; k++) {
          int id = j * M + k + 1 + tar;
          if (dis[ux][uy][j][k] < 0) continue;
          if (1LL * tmm[i] * dis[ux][uy][j][k] > md) continue;
          add(i, id, 1);
        }
    }
    for (int i = 1; i <= n2; i++) {
      add(n1 + i, tar, 1);
      int ux = fx[i] - 1;
      int uy = fy[i] - 1;
      for (int j = 0; j < N; j++)
        for (int k = 0; k < M; k++) {
          int id = j * M + k + 1 + tar;
          if (grid[j][k] == '#') continue;
          if (dis[ux][uy][j][k] < 0) continue;
          if (1LL * tf[i] * dis[ux][uy][j][k] > md) continue;
          add(id + N * M, n1 + i, 1);
        }
    }
    for (int i = 1; i <= N * M; i++) add(tar + i, tar + i + N * M, 1);
    if (dinic() >= n1)
      ed = md, ok = 1;
    else
      st = md;
  }
  if (!ok) ed = -1;
  printf("%I64d\n", ed);
  return 0;
}
