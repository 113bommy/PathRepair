#include <bits/stdc++.h>
using namespace std;
const int MAX = 1600 + 5;
const int dr[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dc[] = {1, -1, 0, 0, 1, 1, -1, -1};
int n, m, nr, nc, cnt, ct;
bool grid[MAX][MAX], x[MAX][MAX], y[MAX][MAX], z[MAX][MAX], val;
vector<int> ans;
pair<int, int> cur;
bool inside(int r, int c) {
  if (r > 0 && r <= n && c > 0 && c <= m) return 1;
  return 0;
}
void dfs(int r, int c) {
  grid[r][c] = 0;
  x[r][c] = 1;
  for (int i = 0; i <= 3; i++) {
    nr = r + dr[i], nc = c + dc[i];
    if (!grid[nr][nc]) continue;
    dfs(nr, nc);
  }
}
void cs() {
  for (int r = 1; r <= n; r++)
    for (int c = 1; c <= m; c++) {
      if (!x[r][c]) continue;
      if (!inside(r - 1, c - 1)) continue;
      if (!inside(r + 1, c + 1)) continue;
      val = 1;
      for (int k = 0; k <= 7; k++)
        if (!x[r + dr[k]][c + dc[k]]) {
          val = 0;
          break;
        }
      if (val) {
        y[r][c] = 1;
        for (int k = 0; k <= 7; k++) y[r + dr[k]][c + dc[k]] = 1;
      }
    }
}
void cas() {
  for (int r = 1; r <= n; r++)
    for (int c = 1; c <= m; c++) {
      if (!x[r][c]) continue;
      if (!inside(r - 2, c - 2)) continue;
      if (!inside(r + 2, c + 2)) continue;
      val = 1;
      for (int i = r - 2; i <= r + 2; i++)
        for (int j = c - 2; j <= c + 2; j++)
          if (!x[i][j]) {
            val = 0;
            break;
          }
      if (val)
        for (int i = r - 2; i <= r + 2; i++)
          for (int j = c - 2; j <= c + 2; j++) z[i][j] = 1;
    }
  for (int r = 1; r <= n; r++)
    for (int c = 1; c <= n; c++) z[r][c] ^= y[r][c];
}
void cast() {
  for (int r = 1; r <= n; r++)
    for (int c = 1; c <= m; c++) {
      if (!z[r][c]) continue;
      if (!inside(r - 1, c - 1)) continue;
      if (!inside(r + 1, c + 1)) continue;
      val = 1;
      for (int k = 0; k <= 7; k++)
        if (!z[r + dr[k]][c + dc[k]]) {
          val = 0;
          break;
        }
      y[r][c] = val;
    }
}
void df(int r, int c) {
  ct++;
  y[r][c] = 0;
  for (int i = 0; i <= 7; i++) {
    nr = r + dr[i], nc = c + dc[i];
    if (!y[nr][nc]) continue;
    df(nr, nc);
  }
}
void hit() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (!y[i][j]) continue;
      ct = 0;
      df(i, j);
      if (ct > 3) cnt++;
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> grid[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (!grid[i][j]) continue;
      memset(x, 0, sizeof x);
      memset(y, 0, sizeof y);
      memset(z, 0, sizeof z);
      dfs(i, j);
      cs();
      cas();
      memset(y, 0, sizeof y);
      cast();
      cnt = 0;
      hit();
      ans.push_back(cnt);
    }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto i : ans) cout << i << " ";
  return 0;
}
