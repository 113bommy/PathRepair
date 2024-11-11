#include <bits/stdc++.h>
using namespace std;
void Print() { cout << endl; }
template <typename T1, typename... T>
void Print(const T1 &t1, const T &...t) {
  cout << t1 << " ";
  Print(t...);
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
const int MaxN = 100100, MaxM = 20, MaxL = 400;
int L;
char cmap[255];
int dx[3] = {-1, 0, 0}, dy[3] = {0, -1, 1};
char table[MaxN][MaxM];
int vis[MaxN][MaxM];
int mark[MaxN][MaxM];
pair<int, int> to[MaxL][MaxL][MaxM];
int n, m, q;
bool in(int i, int j) { return 1 <= i && i <= n && 1 <= j && j <= m; }
pair<int, int> dfs(int x, int y, int m) {
  if (vis[x][y] > 0 && vis[x][y] < m)
    return vis[x][y] = m, to[x / L][x - x / L * L][y];
  vis[x][y] = m;
  int l = x / L;
  int nx = x + dx[cmap[table[x][y]]], ny = y + dy[cmap[table[x][y]]];
  if (in(nx, ny)) {
    auto res = (vis[nx][ny] != m) ? dfs(nx, ny, m) : make_pair(nx, ny);
    if (nx / L == x / L) {
      return to[l][x - L * l][y] = res;
    } else {
      return to[l][x - L * l][y] = make_pair(nx, ny);
    }
  } else {
    return to[l][x - L * l][y] = make_pair(nx, ny);
  }
}
pair<int, int> dfs2(int x, int y, int m) {
  if (vis[x][y] > 0 && vis[x][y] < m)
    return vis[x][y] = m, to[x / L][x - x / L * L][y];
  vis[x][y] = m;
  int l = x / L;
  int nx = x + dx[cmap[table[x][y]]], ny = y + dy[cmap[table[x][y]]];
  if (in(nx, ny)) {
    if (nx / L == x / L) {
      if (vis[nx][ny] < m)
        return to[l][x - L * l][y] = dfs2(nx, ny, m);
      else
        return to[l][x - L * l][y] = make_pair(nx, ny);
    } else {
      return to[l][x - L * l][y] = make_pair(nx, ny);
    }
  } else {
    return to[l][x - L * l][y] = make_pair(nx, ny);
  }
}
void build() {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!vis[i][j]) ++cnt, dfs(i, j, cnt);
    }
  }
}
pair<int, int> query_pos(int x, int y, int m) {
  auto p = make_pair(x, y);
  while (in(p.first, p.second) && mark[p.first][p.second] != m) {
    mark[p.first][p.second] = m;
    int l = p.first / L, lx = p.first - l * L;
    p = to[l][lx][p.second];
  }
  if (!in(p.first, p.second))
    return p;
  else
    return make_pair(-1, -1);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> (table[i] + 1);
  }
  L = (int)sqrt(n);
  cmap['^'] = 0, cmap['<'] = 1, cmap['>'] = 2;
  build();
  memset(vis, 0, sizeof(vis));
  int query_pos_cnt = 0;
  for (int i = 0; i < q; ++i) {
    char op, c;
    int x, y;
    cin >> op >> x >> y;
    if (op == 'A') {
      auto ans = query_pos(x, y, ++query_pos_cnt);
      Print(ans.first, ans.second);
    } else {
      cin >> c;
      table[x][y] = c;
      int l = x / L * L, r = min((x / L + 1) * L, n + 1);
      for (int j = max(l, 1); j < r; ++j) {
        memset(vis[j], 0, sizeof(vis[j]));
      }
      int cnt = 0;
      for (int j = max(l, 1); j < r; ++j) {
        for (int k = 1; k <= m; ++k)
          if (!vis[j][k]) ++cnt, dfs2(j, k, cnt);
      }
    }
  }
  return 0;
}
