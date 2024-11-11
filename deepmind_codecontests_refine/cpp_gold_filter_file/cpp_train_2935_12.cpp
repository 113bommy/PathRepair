#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const double eps = (double)1e-9;
const double pi = acos(-1.0);
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
const int N = 500;
int n, col[N][N];
vector<pair<int, int> > g[N][N];
void dfs(int x, int y) {
  for (auto to : g[x][y]) {
    if (!col[to.first][to.second]) {
      col[to.first][to.second] = 3 - col[x][y];
      dfs(to.first, to.second);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int xa = -2; xa <= 2; ++xa)
        for (int ya = -2; ya <= 2; ++ya) {
          if (abs(xa * ya) != 2) continue;
          int xb = xa + i, yb = ya + j;
          if (xb >= 1 && xb <= n && yb >= 1 && yb <= n)
            g[xb][yb].push_back(make_pair(i, j));
        }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      if (!col[i][j]) {
        col[i][j] = 1;
        dfs(i, j);
      }
      if (col[i][j] == 1)
        cout << "W";
      else
        cout << "B";
      if (j == n) cout << endl;
    }
  return 0;
}
