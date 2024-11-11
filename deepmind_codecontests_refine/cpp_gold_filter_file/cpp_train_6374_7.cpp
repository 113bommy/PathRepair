#include <bits/stdc++.h>
using namespace std;
pair<int, int> vec[1005][1005];
int vis[1005][1005], pai[1005][1005], n;
char res[1005][1005];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }
int getrev(int i) {
  if (i == 0) return 1;
  if (i == 1) return 0;
  if (i == 2) return 3;
  if (i == 3) return 2;
  return -1;
}
void solve(int xs, int ys, int flag) {
  queue<pair<int, int> > q;
  q.push({xs, ys});
  vis[xs][ys] = 1;
  if (flag == 0)
    pai[xs][ys] = -1;
  else
    pai[xs][ys] = -2;
  while (!q.empty()) {
    pair<int, int> t = q.front();
    q.pop();
    int x = t.first, y = t.second;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (valid(xx, yy) && !vis[xx][yy] && vec[x][y] == vec[xx][yy]) {
        if (flag == 1 && x == xs && y == ys) pai[xs][ys] = getrev(i);
        vis[xx][yy] = 1;
        pai[xx][yy] = i;
        q.push({xx, yy});
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d %d", &vec[i][j].first, &vec[i][j].second);
      if (vec[i][j] != pair<int, int>(-1, -1)) {
        vec[i][j].first--;
        vec[i][j].second--;
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) pai[i][j] = -2;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (vec[i][j] != pair<int, int>(-1, -1) &&
          !vis[vec[i][j].first][vec[i][j].second]) {
        solve(vec[i][j].first, vec[i][j].second, 0);
        if ((vec[i][j].first != i || vec[i][j].second != j) && pai[i][j] < 0) {
          cout << "INVALID" << endl;
          return 0;
        }
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (vec[i][j] == pair<int, int>(-1, -1) && !vis[i][j]) {
        solve(i, j, 1);
        if (pai[i][j] < 0) {
          cout << "INVALID" << endl;
          return 0;
        }
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (pai[i][j] == 0)
        res[i][j] = 'U';
      else if (pai[i][j] == 1)
        res[i][j] = 'D';
      else if (pai[i][j] == 2)
        res[i][j] = 'L';
      else if (pai[i][j] == 3)
        res[i][j] = 'R';
      else if (pai[i][j] == -1)
        res[i][j] = 'X';
      else {
        cout << "INVALID" << endl;
        return 0;
      }
    }
  cout << "VALID" << endl;
  for (int i = 0; i < n; i++) printf("%s\n", res[i]);
  return 0;
}
