#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int n, k;
char grid[maxn][maxn];
int cc[maxn][maxn];
int cc_size[maxn * maxn];
int when_added[maxn * maxn];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool inside(int x, int y) {
  if (x < 0 || x >= n) return false;
  if (y < 0 || y >= n) return false;
  return true;
}
void dfs(int x, int y, int num) {
  cc[x][y] = num;
  ++cc_size[num];
  for (int i = 0; i < 4; i++) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if (inside(x2, y2) && grid[x2][y2] == '.' && cc[x2][y2] == 0)
      dfs(x2, y2, num);
  }
}
void add(int x, int y, int& ans, int num) {
  if (inside(x, y) && grid[x][y] == '.') {
    int id = cc[x][y];
    if (when_added[id] != num) {
      when_added[id] = num;
      ans += cc_size[id];
    }
  }
}
void QAQ() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%s", grid[i]);
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j] == '.' && cc[i][j] == 0) dfs(i, j, ++cnt);
  int cur_time = 1;
  int Ans = 0;
  for (int y_low = 0; y_low + k <= n; y_low++) {
    for (int x = 0; x < k; x++)
      for (int y = y_low; y < y_low + k; y++) --cc_size[cc[x][y]];
    for (int x_low = 0; x_low + k <= n; x_low++) {
      int ans = k * k;
      for (int x = x_low; x < x_low + k; x++) {
        add(x, y_low - 1, ans, cur_time);
        add(x, y_low + k, ans, cur_time);
      }
      for (int y = y_low; y < y_low + k; y++) {
        add(x_low - 1, y, ans, cur_time);
        add(x_low + k, y, ans, cur_time);
      }
      ++cur_time;
      Ans = max(Ans, ans);
      if (x_low + k != n) {
        for (int y = y_low; y < y_low + k; y++) {
          ++cc_size[cc[x_low][y]];
          --cc_size[cc[x_low + k][y]];
        }
      }
    }
    for (int x = n - k; x < n; x++)
      for (int y = y_low; y < y_low + k; y++) ++cc_size[cc[x][y]];
  }
  cout << Ans << endl;
}
int main() { QAQ(); }
