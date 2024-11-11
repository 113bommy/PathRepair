#include <bits/stdc++.h>
using namespace std;
void RI() {}
template <typename... T>
void RI(int& head, T&... tail) {
  scanf("%d", &head);
  RI(tail...);
}
struct Maxflow {
  static const int INF = 1e8;
  struct E {
    int to, cap, rev;
    E() {}
    E(int _to, int _cap, int _rev) : to(_to), cap(_cap), rev(_rev) {}
  };
  int n;
  vector<vector<E> > e;
  vector<vector<E>::iterator> cur;
  vector<int> dis;
  void init(int _n) {
    n = _n;
    e.resize(n);
    cur.resize(n);
    dis.resize(n);
    for (int i = 0; i < int(n); i++) e[i].clear();
  }
  void add(int a, int b, int c) {
    if (a == b) return;
    e[a].push_back(E(b, c, e[b].size()));
    e[b].push_back(E(a, 0, e[a].size() - 1));
  }
  bool bfs() {
    fill(dis.begin(), dis.end(), -1);
    queue<int> q;
    dis[0] = 0;
    q.push(0);
    while (!q.empty() && dis[n - 1] == -1) {
      int p = q.front();
      q.pop();
      for (auto it = (e[p]).begin(); it != (e[p]).end(); it++) {
        if (it->cap == 0 || dis[it->to] != -1) continue;
        dis[it->to] = dis[p] + 1;
        q.push(it->to);
      }
    }
    return dis[n - 1] != -1;
  }
  int go(int p, int c) {
    if (p == n - 1) return c;
    int ret = 0;
    for (auto& it = cur[p]; it != e[p].end(); it++) {
      if (it->cap == 0 || dis[it->to] != dis[p] + 1) continue;
      int now = go(it->to, min(it->cap, c - ret));
      ret += now;
      it->cap -= now;
      e[it->to][it->rev].cap += now;
      if (ret == c) break;
    }
    if (ret == 0) dis[p] = -1;
    return ret;
  }
  int maxflow() {
    int ret = 0;
    while (bfs()) {
      for (int i = 0; i < int(n); i++) cur[i] = e[i].begin();
      ret += go(0, INF);
    }
    return ret;
  }
} mf;
int n, m, k1, k2, r[514], c[514], t[514];
char s[25][25];
void input() {
  RI(n, m, k1, k2);
  for (int i = (1); i <= int(n); i++) scanf("%s", s[i] + 1);
  for (int i = 0; i < int(k1 + k2 + 1); i++) RI(r[i], c[i], t[i]);
}
void BFS(int x, int y, int d[25][25]) {
  const int dx[] = {1, 0, -1, 0};
  const int dy[] = {0, 1, 0, -1};
  static bool vis[25][25];
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  auto push = [&](int xx, int yy, int dd) {
    if (s[xx][yy] != '.') return;
    if (vis[xx][yy]) return;
    vis[xx][yy] = 1;
    q.push(xx);
    q.push(yy);
    d[xx][yy] = dd;
  };
  push(x, y, 0);
  while (!q.empty()) {
    x = q.front();
    q.pop();
    y = q.front();
    q.pop();
    for (int i = 0; i < int(4); i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      push(nx, ny, d[x][y] + 1);
    }
  }
}
int dis[25][25][25][25];
void build() {
  memset(dis, -1, sizeof(dis));
  for (int i = (1); i <= int(n); i++)
    for (int j = (1); j <= int(m); j++)
      if (s[i][j] == '.') BFS(i, j, dis[i][j]);
}
void solve() {
  const long long INF = 1e16;
  vector<int> a, b;
  if (k1 + 1 == k2)
    a.push_back(0);
  else if (k1 == k2 + 1)
    b.push_back(0);
  else
    return puts("-1"), void();
  for (int i = (1); i <= int(k1); i++) a.push_back(i);
  for (int i = (k1 + 1); i <= int(k1 + k2); i++) b.push_back(i);
  assert(((int)(a).size()) == ((int)(b).size()));
  int z = ((int)(a).size()), sink = k1 + k2 + 1 + 2 * n * m + 1;
  long long ll = 0, rr = INF;
  while (ll != rr) {
    long long mm = (ll + rr) / 2;
    mf.init(sink + 1);
    for (int i = 0; i < int(z); i++) mf.add(0, a[i] + 1, 1);
    for (int i = 0; i < int(z); i++) mf.add(b[i] + 1, sink, 1);
    for (int x = (1); x <= int(n); x++)
      for (int y = (1); y <= int(m); y++)
        if (s[x][y] == '.') {
          int id = k1 + k2 + 1 + (x - 1) * m + y;
          mf.add(id, id + n * m, 1);
        }
    for (int i = 0; i < int(z); i++)
      for (int x = (1); x <= int(n); x++)
        for (int y = (1); y <= int(m); y++)
          if (s[x][y] == '.') {
            int id = k1 + k2 + 1 + (x - 1) * m + y;
            long long da = dis[r[a[i]]][c[a[i]]][x][y];
            long long db = dis[r[b[i]]][c[b[i]]][x][y];
            if (da != -1 && 1LL * t[a[i]] * da <= mm) mf.add(a[i] + 1, id, 1);
            if (db != -1 && 1LL * t[b[i]] * db <= mm)
              mf.add(id + n * m, b[i] + 1, 1);
          }
    int flow = mf.maxflow();
    if (flow == z)
      rr = mm;
    else
      ll = mm + 1;
  }
  if (ll == INF)
    puts("-1");
  else
    cout << ll << endl;
}
int main() {
  input();
  build();
  solve();
  return 0;
}
