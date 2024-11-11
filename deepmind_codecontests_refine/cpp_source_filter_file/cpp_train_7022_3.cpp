#include <bits/stdc++.h>
using namespace std;
int g[31][31], a[31][31], vis[31][31];
int n, m;
int cnt[901];
void print(int a[31][31], const char *msg = "") {}
inline int sgn(int x) { return x < 0 ? -1 : (x > 0); }
vector<pair<int, int> > ans;
int x, y;
inline void mv(int _x, int _y) {
  ans.push_back(pair<int, int>(_x + 1, _y + 1));
  swap(a[x][y], a[_x][_y]);
  x = _x, y = _y;
}
void fi(int c, int &u, int &v) {
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(m); ++j)
      if (!vis[i][j] && a[i][j] == c) {
        if (i == x && j == y) continue;
        u = i, v = j;
        return;
      }
  assert(0);
}
bitset<32> in_queue[31];
int px[999], py[999], pre[999], L, R;
vector<pair<int, int> > go(int x, int y, int u, int v) {
  vector<pair<int, int> > path;
  if (x == u && y == v) return path;
  if (vis[u][v]) assert(NULL);
  for (int i = 0; i < int(31); ++i) in_queue[i].reset();
  px[0] = x, py[0] = y, pre[0] = -1;
  in_queue[x][y] = 1;
  L = 0, R = 1;
  while (L < R) {
    int x = px[L], y = py[L];
    for (int a = x - 1; a <= int(x + 1); ++a)
      for (int b = y - 1; b <= int(y + 1); ++b) {
        if (a == x && b == y) continue;
        if (a < 0 || b < 0 || a >= n || b >= m) continue;
        if (in_queue[a][b] || vis[a][b]) continue;
        px[R] = a, py[R] = b, pre[R++] = L;
        if (a == u && b == v) {
          --R;
          for (; ~pre[R]; R = pre[R])
            path.push_back(pair<int, int>(px[R], py[R]));
          reverse(path.begin(), path.end());
          return path;
        }
        in_queue[a][b] = 1;
      }
    L++;
  }
  assert(false);
}
int bak[31][31];
bool check() {
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(m); ++j)
      if (a[i][j] != g[i][j]) return 0;
  return 1;
}
void restore() {
  ans.clear();
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(m); ++j) a[i][j] = bak[i][j];
}
bool gao() {
  if (n == 1 || m == 1) {
    for (int i = 0; i < int(n); ++i)
      for (int j = 0; j < int(m); ++j) bak[i][j] = a[i][j];
    int p;
    if (n == 1) {
      for (int i = 0; i < int(m); ++i)
        for (int j = 0; j < int(m); ++j) {
          restore();
          x = 0, y = i;
          do {
            mv(0, p);
            p += sgn(j - y);
          } while (y != p);
          if (check()) return 1;
        }
    } else if (m == 1) {
      for (int i = 0; i < int(n); ++i)
        for (int j = 0; j < int(n); ++j) {
          restore();
          x = i, y = 0;
          do {
            mv(p, 0);
            p += sgn(j - x);
          } while (x != p);
          if (check()) return 1;
        }
    }
    return 0;
  }
  for (int tt = n * m - 1; tt > 0; --tt) {
    int i = 0, j = 0;
    for (int I = 0; I < int(n); ++I)
      for (int J = 0; J < int(m); ++J)
        if (!vis[I][J] && max(I, J) >= max(i, j)) i = I, j = J;
    if (a[i][j] != g[i][j] || (x == i && y == j)) {
      int u, v;
      fi(g[i][j], u, v);
      vector<pair<int, int> > path = go(u, v, i, j);
      for (int z = 0; z < int(path.size()); ++z) {
        int uu = path[z].first, vv = path[z].second;
        vis[u][v] = 1;
        vector<pair<int, int> > path2 = go(x, y, uu, vv);
        for (int k = 0; k < int(path2.size()); ++k) {
          mv(path2[k].first, path2[k].second);
        }
        mv(u, v);
        vis[u][v] = 0;
        u = uu, v = vv;
      }
      vis[i][j] = 1;
    } else
      vis[i][j] = 1;
  }
  return 1;
}
void init() {
  x = y = 0;
  if (a[0][0] != g[0][0]) {
    for (int i = 0; i < int(n); ++i)
      for (int j = 0; j < int(m); ++j)
        if (a[i][j] == g[0][0]) {
          x = i, y = j;
          i = n, j = m;
        }
    mv(x, y);
    for (; x || y;) mv(x - sgn(x), y - sgn(y));
  } else
    mv(0, 0);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(m); ++j) scanf("%d", a[i] + j), cnt[a[i][j]]++;
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(m); ++j) scanf("%d", g[i] + j), cnt[g[i][j]]--;
  for (int i = 0; i < int(901); ++i)
    if (cnt[i] != 0) {
      puts("-1");
      return 0;
    }
  if (n > 1 && m > 1) init();
  if (gao()) {
    printf("%d\n", (int)ans.size() - 1);
    for (int i = 0; i < int(ans.size()); ++i)
      printf("%d %d\n", ans[i].first, ans[i].second);
    for (int i = 0; i < int(n); ++i)
      for (int j = 0; j < int(m); ++j) assert(a[i][j] == g[i][j]);
  } else
    puts("-1");
}
