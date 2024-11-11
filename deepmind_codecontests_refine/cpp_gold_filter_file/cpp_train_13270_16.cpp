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
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T, class U>
inline void print(T first, U second) {
  printsp(first);
  println(second);
}
template <class T, class U, class V>
inline void print(T first, U second, V z) {
  printsp(first);
  printsp(second);
  println(z);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int V, E, src, tar;
int head[60000], work[60000], dis[60000];
int to[2010000], cap[2010000], nxt[2010000];
int q[60000], qf, qb;
int n, m, males, females;
void init(int n, int s, int t) {
  V = n;
  E = 0;
  src = s;
  tar = t;
  memset(head, -1, sizeof(int) * V);
}
void add_edge(int u, int v, int c) {
  to[E] = v;
  cap[E] = c;
  nxt[E] = head[u];
  head[u] = E++;
  to[E] = u;
  cap[E] = 0;
  nxt[E] = head[v];
  head[v] = E++;
}
bool bfs() {
  memset(dis, -1, sizeof(int) * V);
  qf = qb = 0;
  q[qb++] = src;
  dis[src] = 0;
  while (qf < qb && dis[tar] == -1) {
    int u = q[qf++];
    for (int i = head[u]; i >= 0; i = nxt[i]) {
      int v = to[i];
      if (dis[v] == -1 && cap[i] > 0) {
        dis[v] = dis[u] + 1;
        q[qb++] = v;
      }
    }
  }
  return dis[tar] >= 0;
}
int dfs(int u, int &bot) {
  int v, bot1, delta;
  if (u == tar) return bot;
  for (int &i = work[u]; i >= 0; i = nxt[i]) {
    int v = to[i];
    if (dis[v] != dis[u] + 1 || cap[i] == 0) continue;
    bot1 = min(bot, cap[i]);
    if (delta = dfs(v, bot1)) {
      cap[i] -= delta;
      cap[i ^ 1] += delta;
      bot = bot1;
      return delta;
    }
  }
  return 0;
}
int dinic() {
  int ans = 0, delta, bot;
  while (bfs()) {
    memcpy(work, head, sizeof(int) * V);
    delta = 0x3f3f3f3f;
    while (delta = dfs(src, bot = 0x3f3f3f3f)) ans += delta;
  }
  return ans;
}
void NoSolution() {
  puts("-1");
  exit(0);
}
char grid[33][33];
int dst[33][33][33][33];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int mx[33 * 33], my[33 * 33], mt[33 * 33];
int fx[33 * 33], fy[33 * 33], ft[33 * 33];
int can(long long mid) {
  init(males + females + n * m * 2 + 10, 0, males + females + n * m * 2 + 1);
  for (int i = 0; i < males; i++) {
    add_edge(src, i + 1, 1);
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++) {
        if (dst[mx[i]][my[i]][j][k] == 0x3f3f3f3f) continue;
        if ((long long)dst[mx[i]][my[i]][j][k] * mt[i] > mid) continue;
        add_edge(i + 1, males + (j - 1) * m + k, 1);
      }
  }
  for (int i = 0; i < females; i++) {
    add_edge(males + n * m * 2 + i + 1, tar, 1);
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++) {
        if (dst[fx[i]][fy[i]][j][k] == 0x3f3f3f3f) continue;
        if ((long long)dst[fx[i]][fy[i]][j][k] * ft[i] > mid) continue;
        add_edge(males + (j - 1) * m + k + n * m, males + n * m * 2 + i + 1, 1);
      }
  }
  for (int j = 1; j <= n; j++)
    for (int k = 1; k <= m; k++)
      add_edge(males + (j - 1) * m + k, males + (j - 1) * m + k + n * m, 1);
  return dinic() == males;
}
int main() {
  gn(n, m);
  gn(males, females);
  if (abs(males - females) != 1) NoSolution();
  for (int i = 1; i <= n; i++) scanf("%s", grid[i] + 1);
  int r, c, t;
  gn(r, c, t);
  memset(dst, 0x3f, sizeof dst);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (grid[i][j] == '.') {
        dst[i][j][i][j] = 0;
        qf = qb = 0;
        q[qb++] = i;
        q[qb++] = j;
        while (qf < qb) {
          int u = q[qf++], v = q[qf++];
          for (int k = 0; k < 4; k++) {
            int uu = u + dx[k], vv = v + dy[k];
            if ((uu < 1 || vv < 1 || uu > n || vv > m) || grid[uu][vv] == '#')
              continue;
            if (dst[i][j][uu][vv] > dst[i][j][u][v] + 1) {
              dst[i][j][uu][vv] = dst[i][j][u][v] + 1;
              q[qb++] = uu;
              q[qb++] = vv;
            }
          }
        }
      }
  }
  for (int i = 0; i < males; i++) gn(mx[i], my[i], mt[i]);
  for (int i = 0; i < females; i++) gn(fx[i], fy[i], ft[i]);
  if (males == females + 1) {
    fx[females] = r;
    fy[females] = c;
    ft[females] = t;
    females++;
  } else if (males + 1 == females) {
    mx[males] = r;
    my[males] = c;
    mt[males] = t;
    males++;
  }
  assert(males == females);
  long long st = -1, ed = (long long)1e16;
  while (ed - st > 1) {
    long long mid = st + ed >> 1;
    if (can(mid))
      ed = mid;
    else
      st = mid;
  }
  if (ed == (long long)1e16) NoSolution();
  println(ed);
  return 0;
}
