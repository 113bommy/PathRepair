#include <bits/stdc++.h>
using namespace std;
const int maxn = 1600 + 100;
int n, m;
int a[maxn][maxn];
bool isPainted(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m && a[x][y];
}
int isInside(int x, int y) {
  for (int dx = -3; dx <= 3; dx++)
    for (int dy = -3; dy <= 3; dy++)
      if (dx * dx + dy * dy != 18 && !isPainted(x + dx, y + dy)) return 0;
  return 1;
}
bool isRay(int x, int y) {
  if (a[x][y] != 1) return 0;
  for (int dx = -4; dx <= 4; dx++)
    for (int dy = -4; dy <= 4; dy++)
      if (isPainted(x + dx, y + dy) && a[x + dx][y + dy] == 2) return 0;
  return 1;
}
void dfsRay(int x, int y) {
  if (!isPainted(x, y)) return;
  if (a[x][y] != 8) return;
  a[x][y] = 0;
  for (int dx = -1; dx <= 1; dx++)
    for (int dy = -1; dy <= 1; dy++) dfsRay(x + dx, y + dy);
}
int dfs(int x, int y) {
  if (!isPainted(x, y)) return 0;
  int ret = 0;
  if (a[x][y] == 8) dfsRay(x, y), ret++;
  a[x][y] = 0;
  for (int dx = -1; dx <= 1; dx++)
    for (int dy = -1; dy <= 1; dy++) ret += dfs(x + dx, y + dy);
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0, _n = (int)(n); i < _n; i++)
    for (int j = 0, _n = (int)(m); j < _n; j++) cin >> a[i][j];
  for (int i = 0, _n = (int)(n); i < _n; i++)
    for (int j = 0, _n = (int)(m); j < _n; j++)
      if (a[i][j]) a[i][j] += isInside(i, j);
  for (int i = 0, _n = (int)(n); i < _n; i++)
    for (int j = 0, _n = (int)(m); j < _n; j++)
      if (isRay(i, j)) a[i][j] = 8;
  vector<int> ans;
  for (int i = 0, _n = (int)(n); i < _n; i++)
    for (int j = 0, _n = (int)(m); j < _n; j++)
      if (a[i][j] == 2) ans.push_back(dfs(i, j));
  sort((ans).begin(), (ans).end());
  cout << (int((ans).size())) << endl;
  for (int i = 0, _n = (int)((int((ans).size()))); i < _n; i++)
    cout << ans[i] << ' ';
  cout << endl;
  {
    int _;
    cin >> _;
    return 0;
  }
}
