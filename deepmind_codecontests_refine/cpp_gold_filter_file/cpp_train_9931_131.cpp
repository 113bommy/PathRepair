#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[1700][1700];
int sum[1700][1700];
int mark[1700][1700];
bool v[1700][1700];
bool v2[1700][1700];
vector<int> thisX, thisY;
int fixX(int x) {
  if (x <= 0) return 1;
  if (x > n) return n;
  return x;
}
int fixY(int y) {
  if (y <= 0) return 1;
  if (y > m) return m;
  return y;
}
int around(int x, int y, int d) {
  int xL = fixX(x - d);
  int xR = fixX(x + d);
  int yL = fixY(y - d);
  int yR = fixY(y + d);
  return sum[xR][yR] - sum[xR][yL - 1] - sum[xL - 1][yR] + sum[xL - 1][yL - 1];
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int x, int y, int id) {
  if (x <= 0 || x > n || y <= 0 || y > m) return;
  if (board[x][y] == false) return;
  if (v[x][y]) return;
  thisX.push_back(x);
  thisY.push_back(y);
  v[x][y] = true;
  mark[x][y] = id;
  for (int d = 0; d < 4; d++) dfs(x + dx[d], y + dy[d], id);
}
bool check(int x, int y) { return around(x, y, 3) <= 15; }
void dfs2(int x, int y) {
  if (x <= 0 || x > n || y <= 0 || y > m) return;
  if (board[x][y] == false) return;
  if (v2[x][y]) return;
  v2[x][y] = true;
  if (check(x, y) == false) return;
  for (int d = 0; d < 4; d++) dfs2(x + dx[d], y + dy[d]);
}
int calc(int x, int y, int id) { return 1; }
int MAIN() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> board[i][j];
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      sum[i][j] =
          board[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  memset(v, 0, sizeof(v));
  memset(v2, 0, sizeof(v2));
  memset(mark, 0, sizeof(mark));
  vector<int> ans;
  int id = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!v[i][j] && board[i][j]) {
        id++;
        thisX.clear(), thisY.clear();
        dfs(i, j, id);
        int cnt = 0;
        for (int u = 0; u < thisX.size(); u++) {
          int x = thisX[u];
          int y = thisY[u];
          if (!v2[x][y] && check(x, y)) {
            dfs2(x, y);
            cnt++;
          }
        }
        ans.push_back(cnt);
      }
  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
  return 0;
}
int main() {
  ios ::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  return MAIN();
}
