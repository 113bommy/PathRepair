#include <bits/stdc++.h>
using namespace std;
template <int N, int Ne>
struct flow {
  using F = int;
  F inf = 1e9;
  int n, s, t;
  int ehd[N], cur[N], ev[Ne << 1], enx[Ne << 1], eid = 1;
  void clear() { eid = 1, memset(ehd, 0, sizeof(ehd)); }
  F ew[Ne << 1], dis[N];
  void Eadd(int u, int v, F w) {
    ++eid, enx[eid] = ehd[u], ew[eid] = w, ev[eid] = v, ehd[u] = eid;
  }
  void add(int u, int v, F w) { Eadd(u, v, w), Eadd(v, u, 0); }
  bool bfs() {
    queue<int> q;
    for (int i = (1); i <= (n); i++) dis[i] = inf, cur[i] = ehd[i];
    q.push(s), dis[s] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = ehd[u]; i; i = enx[i])
        if (ew[i] && dis[ev[i]] == inf) {
          dis[ev[i]] = dis[u] + 1, q.push(ev[i]);
        }
    }
    return dis[t] < inf;
  }
  F dfs(int x, F now) {
    if (!now || x == t) return now;
    F res = 0, f;
    for (int i = cur[x]; i; i = enx[i]) {
      cur[x] = i;
      if (ew[i] && dis[ev[i]] == dis[x] + 1) {
        f = dfs(ev[i], min(now, ew[i])), ew[i] -= f, now -= f, ew[i ^ 1] += f,
        res += f;
        if (!now) break;
      }
    }
    return res;
  }
  F max_flow() {
    F res = 0;
    while (bfs()) res += dfs(s, inf);
    return res;
  }
};
const int N = 24, S = N * N;
int n, m, A, B;
int det[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char s[N][N];
struct node {
  int x, y, w;
  int d[N][N];
  void bfs() {
    queue<pair<int, int> > q;
    memset(d, 0x3f, sizeof(d));
    q.push(make_pair(x, y)), d[x][y] = 0;
    while (!q.empty()) {
      int sx = q.front().first, sy = q.front().second;
      q.pop();
      for (int i = (0); i <= (3); i++) {
        int px = sx + det[i][0], py = sy + det[i][1];
        if (s[px][py] == '.' && d[px][py] > n * m)
          d[px][py] = d[sx][sy] + 1, q.push(make_pair(px, py));
      }
    }
  }
} pa[S], pb[S];
flow<S * 5, S * S * 5> a;
bool check(long long X) {
  a.clear(), a.n = ((1) * n * m + ((n)-1) * m + (m) + A + B) + 2,
             a.s = ((1) * n * m + ((n)-1) * m + (m) + A + B) + 1,
             a.t = ((1) * n * m + ((n)-1) * m + (m) + A + B) + 2;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++)
      a.add(((0) * n * m + ((i)-1) * m + (j) + A + B),
            ((1) * n * m + ((i)-1) * m + (j) + A + B), 1);
  for (int x = (1); x <= (A); x++) {
    a.add(a.s, x, 1);
    for (int i = (1); i <= (n); i++)
      for (int j = (1); j <= (m); j++)
        if (pa[x].d[i][j] <= n * m && (long long)pa[x].d[i][j] * pa[x].w <= X)
          a.add(x, ((0) * n * m + ((i)-1) * m + (j) + A + B), 1);
  }
  for (int x = (1); x <= (B); x++) {
    a.add(x + A, a.t, 1);
    for (int i = (1); i <= (n); i++)
      for (int j = (1); j <= (m); j++)
        if (pb[x].d[i][j] <= n * m && (long long)pb[x].d[i][j] * pb[x].w <= X)
          a.add(((1) * n * m + ((i)-1) * m + (j) + A + B), x + A, 1);
  }
  return a.max_flow() == A;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> A >> B;
  for (int i = (1); i <= (n); i++) cin >> (s[i] + 1);
  if (abs(A - B) != 1) return cout << "-1\n", 0;
  if (A < B) {
    ++A;
    for (int i = (1); i <= (A); i++) cin >> pa[i].x >> pa[i].y >> pa[i].w;
    for (int i = (1); i <= (B); i++) cin >> pb[i].x >> pb[i].y >> pb[i].w;
  } else {
    ++B;
    cin >> pb[B].x >> pb[B].y >> pb[B].w;
    for (int i = (1); i <= (A); i++) cin >> pa[i].x >> pa[i].y >> pa[i].w;
    for (int i = (1); i <= (B - 1); i++) cin >> pb[i].x >> pb[i].y >> pb[i].w;
  }
  for (int i = (1); i <= (A); i++) pa[i].bfs();
  for (int i = (1); i <= (B); i++) pb[i].bfs();
  long long l = 0, r = 1e13, ns = -1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      ns = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ns << "\n";
  return 0;
}
