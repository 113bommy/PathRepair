#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int n;
pair<int, int> INF = make_pair((int)1e9, 100);
pair<int, int> dp[10][10][101][3];
int val[10][10];
inline void init() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k <= 100; k++) {
        for (int l = 0; l < 3; l++) {
          dp[i][j][k][l] = INF;
        }
      }
    }
  }
}
bool check(int x, int y) { return x >= 0 && y >= 0 && x < n && y < n; }
pair<int, int> knight[] = {{1, 2},  {2, 1},  {-1, 2},  {2, -1},
                           {1, -2}, {-2, 1}, {-2, -1}, {-1, -2}};
bool ok;
void relax(int i, int j, int k, int l, int _i, int _j, int _k, int _l, int d1,
           int d2) {
  if (dp[i][j][k][l] > make_pair(dp[_i][_j][_k][_l].first + d1,
                                 dp[_i][_j][_k][_l].second + d2)) {
    dp[i][j][k][l] = make_pair(dp[_i][_j][_k][_l].first + d1,
                               dp[_i][_j][_k][_l].second + d2);
    ok = 1;
  }
}
inline void solve() {
  init();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> val[i][j];
      dp[i][j][0][0] = dp[i][j][0][1] = dp[i][j][0][2] = make_pair(0, 0);
    }
  }
  for (int k = 0; k <= n * n; k++) {
    ok = 1;
    int cnt = 0;
    while (ok) {
      cnt++;
      if (cnt == 40) {
        break;
      }
      ok = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          for (int l = 0; l < 3; l++) {
            if (val[i][j] == k + 1) {
              relax(i, j, k + 1, l, i, j, k, l, 0, 0);
            }
            for (int to = 0; to < 3; to++) {
              relax(i, j, k, to, i, j, k, l, 1, 1);
            }
            if (l == 0) {
              for (int dx = -10; dx <= 10; dx++) {
                if (check(i + dx, j)) {
                  relax(i + dx, j, k, l, i, j, k, l, 1, 0);
                }
              }
              for (int dy = -10; dy <= 10; dy++) {
                if (check(i, j + dy)) {
                  relax(i, j + dy, k, l, i, j, k, l, 1, 0);
                }
              }
            }
            if (l == 1) {
              for (int d = 0; d < 8; d++) {
                int x = i + knight[d].first;
                int y = j + knight[d].second;
                if (check(x, y)) {
                  relax(x, y, k, l, i, j, k, l, 1, 0);
                }
              }
            }
            if (l == 2) {
              for (int d = 0; d <= 11; d++) {
                int x = i + d;
                int y = j - d;
                if (check(x, y)) {
                  relax(x, y, k, l, i, j, k, l, 1, 0);
                }
              }
              for (int d = 0; d <= 11; d++) {
                int x = i - d;
                int y = j + d;
                if (check(x, y)) {
                  relax(x, y, k, l, i, j, k, l, 1, 0);
                }
              }
              for (int d = 0; d <= 11; d++) {
                int x = i - d;
                int y = j - d;
                if (check(x, y)) {
                  relax(x, y, k, l, i, j, k, l, 1, 0);
                }
              }
              for (int d = 0; d <= 11; d++) {
                int x = i + d;
                int y = j + d;
                if (check(x, y)) {
                  relax(x, y, k, l, i, j, k, l, 1, 0);
                }
              }
            }
          }
        }
      }
    }
  }
  int x = -1;
  int y = -1;
  int f = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < 3; l++) {
        if (INF > dp[i][j][n * n][l]) {
          x = i;
          y = j;
          f = l;
          INF = dp[i][j][n * n][l];
        }
      }
    }
  }
  cout << dp[x][y][n * n][f].first << ' ' << dp[x][y][n * n][f].second << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n) solve();
  return 0;
}
