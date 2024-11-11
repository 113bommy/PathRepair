#include <bits/stdc++.h>
using namespace std;
const int maxN = 2000 + 10;
int n, m;
int a[maxN][maxN];
int f[maxN][maxN];
int adj[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int> > p;
void dfs(int i, int j) {
  f[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int x = i + adj[k][0];
    int y = j + adj[k][1];
    if (a[x][y] && !f[x][y]) dfs(x, y);
  }
  p.push_back(pair<int, int>(i, j));
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  int sq = 0, ci = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] && !f[i][j]) {
        p.clear();
        dfs(i, j);
        int maxh = -1, minh = n + 1, minw = n + 1, maxw = -1;
        for (int k = 0; k < p.size(); k++)
          maxh = max(maxh, p[k].second), minh = min(minh, p[k].second),
          maxw = max(maxw, p[k].first), minw = min(minw, p[k].first);
        bool square = 0;
        for (int dx = -1; dx <= 1; dx++)
          for (int dy = -1; dy <= 1; dy++)
            if (a[maxw + dx][maxh + dy]) square = 1;
        sq += square;
        ci += !square;
      }
  cout << ci << ' ' << sq << endl;
  return 0;
}
