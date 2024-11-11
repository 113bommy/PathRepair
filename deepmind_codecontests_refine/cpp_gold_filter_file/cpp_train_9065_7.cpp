#include <bits/stdc++.h>
using namespace std;
int dcmp(long double n, long double y) {
  return fabs(n - y) <= 1e-9 ? 0 : n < y ? -1 : 1;
}
const int MAX = 2e3;
char grid[MAX][MAX], ans[MAX][MAX];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool ok(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '*';
}
int get_max(int x, int y) {
  for (int i = 0; i < (int)(4); ++i) {
    int nx, ny;
    nx = x + dx[i];
    ny = y + dy[i];
    if (!ok(nx, ny)) return 0;
  }
  int ret = 1e9;
  int t, d, l, r;
  t = d = l = r = 0;
  for (int i = x - 1; i >= 0; i--) {
    if (ok(i, y))
      t++;
    else
      break;
  }
  for (int i = x + 1; i < n; i++) {
    if (ok(i, y))
      d++;
    else
      break;
  }
  for (int i = y - 1; i >= 0; i--) {
    if (ok(x, i))
      l++;
    else
      break;
  }
  for (int i = y + 1; i < m; i++) {
    if (ok(x, i))
      r++;
    else
      break;
  }
  return min({t, l, d, r});
}
void fill(int x, int y, int mm) {
  int tmp = mm;
  for (int i = x - 1; i >= 0 && tmp; i--) {
    ans[i][y] = '*';
    tmp--;
  }
  tmp = mm;
  for (int i = x + 1; i < n && tmp; i++) {
    ans[i][y] = '*';
    tmp--;
  }
  tmp = mm;
  for (int i = y - 1; i >= 0 && tmp; i--) {
    ans[x][i] = '*';
    tmp--;
  }
  tmp = mm;
  for (int i = y + 1; i < m && tmp; i++) {
    ans[x][i] = '*';
    tmp--;
  }
}
struct out {
  int x, y, s;
  out() { x = y = s = 0; }
  out(int u, int z, int f) {
    x = u;
    y = z;
    s = f;
  }
};
vector<out> anss;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n >> m;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> grid[i];
  }
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(m); ++j) ans[i][j] = '.';
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(m); ++j) {
      if (grid[i][j] == '*') {
        int mm = get_max(i, j);
        if (mm > 0) {
          ans[i][j] = '*';
          anss.push_back(out(i + 1, j + 1, mm));
          fill(i, j, mm);
        }
      }
    }
  }
  int ok = 1;
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(m); ++j) {
      ok &= (ans[i][j] == grid[i][j]);
    }
  }
  if (ok) {
    cout << anss.size() << '\n';
    for (int i = 0; i < ((int)((anss).size())); ++i) {
      cout << anss[i].x << ' ' << anss[i].y << ' ' << anss[i].s << '\n';
    }
  } else {
    cout << -1 << '\n';
  }
}
