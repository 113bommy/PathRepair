#include <bits/stdc++.h>
using namespace std;
const int maxN = 505;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const char dir[4] = {'R', 'L', 'D', 'U'};
const char rdir[4] = {'L', 'R', 'U', 'D'};
int n, x, y;
int a[maxN][maxN];
string res;
bool mark[maxN][maxN];
int first, last, qx[maxN * maxN], qy[maxN * maxN];
int len[maxN][maxN];
bool Check(int x, int y) { return (x >= 1 && x <= n && y >= 1 && y <= n); }
void DFS(int u, int v) {
  mark[u][v] = true;
  if (a[u][v] == 0) res.push_back('1');
  int cnt[] = {0, 0, 0, 0};
  for (int i = 0; i < 4; ++i)
    for (int j = 1; j <= n; ++j) {
      int x = u + j * dx[i];
      int y = v + j * dy[i];
      if (!Check(x, y)) break;
      if (a[x][y] == 1) ++cnt[i];
    }
  a[u][v] = 1;
  for (int i = 0; i < 4; ++i) {
    int x = u + dx[i];
    int y = v + dy[i];
    if (Check(x, y) && !mark[x][y] && cnt[i] > 0) {
      res.push_back(dir[i]);
      DFS(x, y);
      res.push_back(rdir[i]);
    }
  }
}
bool Check_Graph() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (a[i][j] == 1 && !mark[i][j]) return false;
  return true;
}
void BFS(int s, int t) {
  first = last = 1;
  qx[1] = s;
  qy[1] = t;
  len[s][t] = 1;
  mark[s][t] = true;
  while (first <= last) {
    int x = qx[first], y = qy[first];
    ++first;
    for (int i = 0; i < 4; ++i) {
      int u = x + dx[i];
      int v = y + dy[i];
      if (Check(u, v) && a[u][v] == 1 && !mark[u][v]) {
        mark[u][v] = true;
        len[u][v] = len[x][y] + 1;
        ++last;
        qx[last] = u;
        qy[last] = v;
      }
    }
  }
}
void Re_DFS(int u, int v) {
  mark[u][v] = true;
  for (int i = 0; i < 4; ++i) {
    int x = u + dx[i];
    int y = v + dy[i];
    if (Check(x, y) && !mark[x][y] && a[x][y] == 1 && len[x][y] > len[u][v]) {
      res.push_back(dir[i]);
      Re_DFS(x, y);
      res.push_back(rdir[i]);
    }
  }
  res.push_back('2');
}
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
  memset(mark, false, sizeof mark);
  DFS(x, y);
  if (!Check_Graph()) {
    printf("NO\n");
    return 0;
  }
  memset(mark, false, sizeof mark);
  BFS(x, y);
  memset(mark, false, sizeof mark);
  Re_DFS(x, y);
  cout << "YES\n";
  cout << res;
  return 0;
}
