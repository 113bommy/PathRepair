#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0;
  bool zf = 0;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    zf = 1;
  else
    res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + c - '0';
  if (zf) return -res;
  return res;
}
const int maxn = 1205, maxm = 370005;
namespace Network {
int n;
int nxt[maxm << 1], head[maxn], to[maxm << 1], val[maxm << 1], cnt = -1;
int cur[maxn];
int maxflow;
inline void add(int x, int y, int v) {
  nxt[++cnt] = head[x], head[x] = cnt, to[cnt] = y, val[cnt] = v;
  nxt[++cnt] = head[y], head[y] = cnt, to[cnt] = x, val[cnt] = 0;
  return;
}
inline void reset(int x = 0) {
  n = x;
  cnt = -1;
  memset(head, -1, sizeof(head));
  maxflow = 0;
  return;
}
int dis[maxn];
inline bool bfs() {
  memset(dis, 0x3f, sizeof(dis));
  dis[0] = 0;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (register int i = head[x]; ~i; i = nxt[i]) {
      if (!val[i]) {
        continue;
      }
      int v = to[i];
      if (dis[v] <= 1e9) {
        continue;
      }
      dis[v] = dis[x] + 1;
      Q.push(v);
    }
  }
  if (dis[n] > 1e9) return 0;
  memcpy(cur, head, sizeof(head));
  return 1;
}
void dfs(int x, int flow) {
  if (x == n) {
    maxflow += flow;
    return;
  }
  for (register int i = cur[x]; ~i; i = nxt[i]) {
    cur[x] = nxt[i];
    if (!val[i]) {
      continue;
    }
    int v = to[i];
    if (dis[v] != dis[x] + 1) {
      continue;
    }
    int delta = -maxflow;
    dfs(v, min(flow, val[i]));
    delta += maxflow;
    flow -= delta;
    val[i] -= delta;
    val[i ^ 1] += delta;
    if (!flow) {
      return;
    }
  }
  return;
}
inline int solve() {
  while (bfs()) {
    dfs(0, INT_MAX);
  }
  return maxflow;
}
};  // namespace Network
const int maxnn = 505;
int s[maxnn], p[maxnn];
int f[maxnn][maxnn];
signed main() {
  int n = read(), m = read(), a = read(), b = read(), tot = 0;
  for (register int i = 1; i <= a; ++i) {
    ++s[read()];
  }
  memset(f, 0x3f, sizeof(f));
  for (register int i = 1; i <= n; ++i) {
    f[i][i] = 0;
  }
  while (m--) {
    int x = read(), y = read(), v = read();
    f[x][y] = min(f[x][y], v), f[y][x] = min(f[y][x], v);
  }
  for (register int k = 1; k <= n; ++k) {
    for (register int i = 1; i <= n; ++i) {
      for (register int j = 1; j <= n; ++j) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }
  int l = 0, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    Network::reset(n << 1 | 1);
    for (register int i = 1; i <= n; ++i) {
      Network::add(0, i, s[i]);
    }
    for (register int i = 1; i <= n; ++i) {
      Network::add(i + n, n << 1 | 1, 1);
    }
    for (register int i = 1; i <= n; ++i) {
      for (register int j = 1; j <= n; ++j) {
        if (f[i][j] <= mid) {
          Network::add(i, j + n, 1e18);
        }
      }
    }
    if (Network::solve() >= b) {
      ans = mid, r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
