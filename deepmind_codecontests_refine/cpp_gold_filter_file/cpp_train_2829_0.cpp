#include <bits/stdc++.h>
using namespace std;
const int maxn = 51;
const int inf = 0x3f3f3f3f;
int dp[maxn][maxn][maxn][maxn];
char s[maxn][maxn];
int n;
int f[maxn][maxn][maxn][maxn];
int up[maxn][maxn][maxn][maxn];
int down[maxn][maxn][maxn][maxn];
int lef[maxn][maxn][maxn][maxn];
int rig[maxn][maxn][maxn][maxn];
int DP(int x1, int y1, int x2, int y2) {
  if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
  dp[x1][y1][x2][y2] = f[x1][y1][x2][y2];
  for (int i = x1; i < x2; i++)
    dp[x1][y1][x2][y2] =
        min(dp[x1][y1][x2][y2], DP(x1, y1, i, y2) + DP(i + 1, y1, x2, y2));
  for (int i = y1; i < y2; i++)
    dp[x1][y1][x2][y2] =
        min(dp[x1][y1][x2][y2], DP(x1, y1, x2, i) + DP(x1, i + 1, x2, y2));
  return dp[x1][y1][x2][y2];
}
void getmin(int& x, int y) {
  if (y < x) x = y;
}
void getmax(int& x, int y) {
  if (y > x) x = y;
}
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    memset(dp, -1, sizeof dp);
    memset(f, 0, sizeof f);
    memset(lef, 0x3f, sizeof lef);
    memset(rig, -1, sizeof rig);
    memset(up, 0x3f, sizeof up);
    memset(down, -1, sizeof down);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        for (int i2 = i; i2 < n; i2++) {
          for (int j2 = j; j2 < n; j2++) {
            if (s[i2][j2] == '#') {
              lef[i][j][i2][j2] = j2;
              rig[i][j][i2][j2] = j2;
              down[i][j][i2][j2] = i2;
              up[i][j][i2][j2] = i2;
            }
            if (j2 > j) {
              getmin(lef[i][j][i2][j2], lef[i][j][i2][j2 - 1]);
              getmax(rig[i][j][i2][j2], rig[i][j][i2][j2 - 1]);
            }
            if (i2 > i) {
              getmin(up[i][j][i2][j2], up[i][j][i2 - 1][j2]);
              getmax(down[i][j][i2][j2], down[i][j][i2 - 1][j2]);
            }
          }
        }
        for (int i2 = i + 1; i2 < n; i2++) {
          for (int j2 = j; j2 < n; j2++) {
            getmin(lef[i][j][i2][j2], lef[i][j][i2 - 1][j2]);
            getmax(rig[i][j][i2][j2], rig[i][j][i2 - 1][j2]);
          }
        }
        for (int j2 = j + 1; j2 < n; j2++) {
          for (int i2 = i; i2 < n; i2++) {
            getmin(up[i][j][i2][j2], up[i][j][i2][j2 - 1]);
            getmax(down[i][j][i2][j2], down[i][j][i2][j2 - 1]);
          }
        }
        for (int i2 = i; i2 < n; i2++) {
          for (int j2 = j; j2 < n; j2++) {
            if (lef[i][j][i2][j2] == inf)
              f[i][j][i2][j2] = 0;
            else {
              f[i][j][i2][j2] = max(down[i][j][i2][j2] - up[i][j][i2][j2],
                                    rig[i][j][i2][j2] - lef[i][j][i2][j2]) +
                                1;
            }
          }
        }
      }
    cout << DP(0, 0, n - 1, n - 1) << endl;
  }
  return 0;
}
