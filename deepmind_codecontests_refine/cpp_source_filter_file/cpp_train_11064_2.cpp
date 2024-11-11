#include <bits/stdc++.h>
using std::max;
using std::min;
const int inf = 0x3f3f3f3f, Inf = 0x7fffffff;
const long long INF = 0x3f3f3f3f3f3f3f3f;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>
_Tp gcd(const _Tp &a, const _Tp &b) {
  return !b ? a : gcd(b, a % b);
}
template <typename _Tp>
inline _Tp abs(const _Tp &a) {
  return a >= 0 ? a : -a;
}
template <typename _Tp>
inline void chmax(_Tp &a, const _Tp &b) {
  a = a < b ? b : a;
}
template <typename _Tp>
inline void chmin(_Tp &a, const _Tp &b) {
  a = a < b ? a : b;
}
template <typename _Tp>
inline void read(_Tp &x) {
  char ch(getchar());
  bool f(false);
  while (!isdigit(ch)) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (isdigit(ch)) x = (((x << 2) + x) << 1) + (ch & 15), ch = getchar();
  f && (x = -x);
}
template <typename _Tp, typename... Args>
void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
inline int read_str(char *s) {
  char ch(getchar());
  while (ch == ' ' || ch == '\r' || ch == '\n') ch = getchar();
  char *tar = s;
  *tar++ = ch, ch = getchar();
  while (ch != ' ' && ch != '\r' && ch != '\n' && ch != EOF)
    *tar++ = ch, ch = getchar();
  return *tar = 0, tar - s;
}
const int N = 205;
const int NC = N * N;
struct edge {
  int v, nxt, w;
} c[NC * 8];
int front[NC], edge_cnt;
int dis[NC], cur[NC], _q[NC], _l, _r, node_cnt, S, T;
inline void addedge(int u, int v, int w1, int w2) {
  c[++edge_cnt] = (edge){v, front[u], w1}, front[u] = edge_cnt;
  c[++edge_cnt] = (edge){u, front[v], w2}, front[v] = edge_cnt;
}
bool bfs() {
  memset(dis, 255, (node_cnt + 3) << 2),
      memcpy(cur, front, (node_cnt + 3) << 2);
  _q[_l = _r = 1] = S, dis[S] = 0;
  while (_l != _r + 1) {
    int x = _q[_l++];
    for (int i = front[x]; ~i; i = c[i].nxt)
      if (c[i].w) {
        int v = c[i].v;
        if (dis[v] == -1) {
          dis[v] = dis[x] + 1, _q[++_r] = v;
          if (v == T) return true;
        }
      }
  }
  return dis[T] != -1;
}
int dfs(int x, int flow) {
  if (x == T || !flow) return flow;
  int f = 0, rf;
  for (int &i = cur[x]; ~i; i = c[i].nxt) {
    int v = c[i].v;
    if (dis[v] == dis[x] + 1 && (rf = dfs(v, min(flow, c[i].w)))) {
      flow -= rf, f += rf;
      c[i].w -= rf, c[i ^ 1].w += rf;
      if (!flow) return f;
    }
  }
  return f;
}
int dinic(int s, int t) {
  ::S = s, ::T = t;
  int ans = 0;
  while (bfs()) ans += dfs(S, inf);
  return ans;
}
int t[N << 2], pos, n, m, a[N][N], ed[N][N];
inline int getid(int x, int y) { return (x - 1) * m + y; }
int main() {
  read(n, m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      read(a[i][j]);
      if (a[i][j] > 0) t[++pos] = a[i][j];
    }
  std::sort(t + 1, t + pos + 1), pos = std::unique(t + 1, t + pos + 1) - t - 1;
  int S = n * m + 1, T = S + 1;
  node_cnt = T;
  memset(front, 255, sizeof(front)), edge_cnt = -1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == -1) continue;
      if (a[i][j] > 0) addedge(getid(i, j), T, inf, 0), ed[i][j] = edge_cnt;
      if (i < n && a[i + 1][j] != -1)
        addedge(getid(i, j), getid(i + 1, j), 1, 1);
      if (j < m && a[i][j + 1] != -1)
        addedge(getid(i, j), getid(i, j + 1), 1, 1);
    }
  }
  long long ans = 0;
  int F = 0;
  for (int _ = pos - 1; _ >= 1; --_) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (a[i][j] == t[_ + 1]) {
          int id = ed[i][j];
          F -= c[id].w, c[id ^ 1].w = c[id].w = 0,
                               addedge(S, getid(i, j), inf, 0);
        }
    F += dinic(S, T);
    ans += 1LL * F * (t[_ + 1] - t[_]);
  }
  printf("%lld\n", ans);
  return 0;
}
