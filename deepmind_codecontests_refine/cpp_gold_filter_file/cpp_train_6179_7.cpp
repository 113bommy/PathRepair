#include <bits/stdc++.h>
using namespace std;
const int maxN = 1010;
bool grid[maxN][maxN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  for (int t = 1; t <= T; ++t) {
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> idx;
    for (int i = 1; i <= m; ++i) {
      int x, y;
      cin >> x >> y;
      idx[make_pair(x, y)] = i;
      grid[x][y] = true;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= 1000; ++i) {
      for (int j = 1; j <= 1000; ++j) {
        if (grid[i][j] and grid[i][j + 1] and grid[i][j + 2] and
            grid[i + 1][j] and grid[i + 1][j + 1] and grid[i + 1][j + 2] and
            grid[i + 2][j] and grid[i + 2][j + 1] and grid[i + 2][j + 2]) {
          int min_res = max(
              idx[make_pair(i, j)],
              max(idx[make_pair(i, j + 1)],
                  max(idx[make_pair(i, j + 2)],
                      max(idx[make_pair(i + 1, j)],
                          max(idx[make_pair(i + 1, j + 1)],
                              max(idx[make_pair(i + 1, j + 2)],
                                  max(idx[make_pair(i + 2, j)],
                                      max(idx[make_pair(i + 2, j + 1)],
                                          idx[make_pair(i + 2, j + 2)]))))))));
          ans = min(ans, min_res);
        }
      }
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
  }
}
