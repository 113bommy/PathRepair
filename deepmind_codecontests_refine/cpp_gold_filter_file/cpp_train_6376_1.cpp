#include <bits/stdc++.h>
using namespace std;
template <typename T>
int size(T& a) {
  return (int)a.size();
}
template <typename T>
T sqr(T a) {
  return a * a;
}
const int dx[4] = {+1, -1, 0, 0};
const int dy[4] = {0, 0, +1, -1};
const int MAXN = 1002;
int n, m;
char s[MAXN][MAXN];
bool u[MAXN][MAXN];
int c[MAXN][MAXN];
int g[MAXN][MAXN];
int Tm = 0;
int T = 0;
pair<int, int> q[MAXN * MAXN];
int sz;
bool okey;
bool good(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }
void dfs(int x, int y) {
  if (!good(x, y)) return;
  if (s[y][x] == '1') return;
  if (u[y][x]) return;
  u[y][x] = true;
  if (x == 0 || y == 0 || x == m - 1 || y == n - 1) okey = false;
  for (int dx = -1; dx <= 1; ++dx)
    for (int dy = -1; dy <= 1; ++dy)
      if (good(x + dx, y + dy) && s[y + dy][x + dx] == '1' &&
          c[y + dy][x + dx] != T) {
        q[sz++] = make_pair(x + dx, y + dy);
        c[y + dy][x + dx] = T;
      }
  dfs(x + 1, y);
  dfs(x - 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
  dfs(x + 1, y + 1);
  dfs(x + 1, y - 1);
  dfs(x - 1, y + 1);
  dfs(x - 1, y - 1);
}
int solve() {
  int cmp = 0;
  ++Tm;
  for (int i = (0); i < (sz); ++i) {
    int x = q[i].first;
    int y = q[i].second;
    if (g[y][x] == Tm) continue;
    ++cmp;
    g[y][x] = Tm;
    queue<pair<int, int> > qq;
    qq.push(make_pair(x, y));
    while (size(qq)) {
      pair<int, int> p = qq.front();
      qq.pop();
      bool fst = true;
      int cnt = 0;
      for (int u = (0); u < (4); ++u) {
        int nx = p.first + dx[u];
        int ny = p.second + dy[u];
        if (good(nx, ny) && c[ny][nx] == T) ++cnt;
        if (good(nx, ny) && c[ny][nx] == T && g[ny][nx] != Tm &&
            s[ny][nx] == '1') {
          if (fst) {
            g[ny][nx] = Tm;
            qq.push(make_pair(nx, ny));
          }
        }
      }
      if (cnt != 2) return 0;
    }
  }
  if (cmp == 1 && sz >= 5) return sz;
  return 0;
}
int main() {
  int ans = 0;
  scanf("%d%d\n", &n, &m);
  for (int i = (0); i < (n); ++i) gets(s[i]);
  memset((u), (false), sizeof(u));
  memset((c), (255), sizeof(c));
  memset((g), (255), sizeof(g));
  for (int i = (0); i < (n - 1); ++i)
    for (int j = (0); j < (m - 1); ++j)
      if (s[i][j] == '1' && s[i + 1][j] == '1' && s[i][j + 1] == '1' &&
          s[i + 1][j + 1] == '1')
        ans = max(ans, 4);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j)
      if (s[i][j] == '0' && !u[i][j]) {
        ++T;
        sz = 0;
        okey = true;
        dfs(j, i);
        if (!okey) continue;
        ans = max(ans, solve());
      }
  cout << ans;
}
