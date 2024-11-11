#include <bits/stdc++.h>
using namespace std;
char grid[30][30], par;
bool done, visit[30][30];
pair<int, int> po, test[4], a;
int c, n, m;
void dfs(int x, int y) {
  if (x > n || x < 1 || y > m || y < 1 || visit[x][y] || grid[x][y] != par)
    return;
  visit[x][y] = 1;
  c++;
  if (c >= 4) {
    test[0] = make_pair(x - 1, y);
    test[1] = make_pair(x + 1, y);
    test[2] = make_pair(x, y - 1);
    test[3] = make_pair(x, y + 1);
    for (int i = 0; i < 4; i++) {
      if (test[i] == po) {
        done = 1;
        return;
      }
    }
  }
  dfs(x - 1, y);
  dfs(x + 1, y);
  dfs(x, y - 1);
  dfs(x, y + 1);
  c = 0;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      par = grid[i][j];
      po = make_pair(i, j);
      dfs(i, j);
      if (done) {
        cout << "Yes";
        return 0;
      }
      memset(visit, 0, sizeof visit);
      c = 0;
    }
  }
  cout << "No";
  return 0;
}
