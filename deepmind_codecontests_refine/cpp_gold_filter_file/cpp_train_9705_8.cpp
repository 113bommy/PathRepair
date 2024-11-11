#include <bits/stdc++.h>
using namespace std;
int n, m, q;
char grid[505][505];
int record[505][505][10][10];
int dp[4][505][505];
int Log[505];
int ST[505][505][10][10];
inline bool judge(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void pre() {
  Log[1] = 0, Log[2] = 1;
  for (int i = 3; i < 505; i++) Log[i] = Log[i / 2] + 1;
  char color[4] = {'R', 'G', 'B', 'Y'};
  int d[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
  int init[4][2] = {{0, 0}, {0, m - 1}, {n - 1, m - 1}, {n - 1, 0}};
  for (int c = 0; c < 4; c++) {
    int x = init[c][0], y = init[c][1];
    int delt_x = d[c][0], delt_y = d[c][1];
    for (int i = 0; i < n; i++) {
      y = init[c][1];
      for (int j = 0; j < m; j++) {
        int res;
        if ((!judge(x - delt_x, y - delt_y)) || (!judge(x - delt_x, y)) ||
            (!judge(x, y - delt_y)))
          res = 0;
        else
          res = min(dp[c][x - delt_x][y - delt_y],
                    min(dp[c][x - delt_x][y], dp[c][x][y - delt_y]));
        if (grid[x][y] != color[c])
          dp[c][x][y] = 0;
        else
          dp[c][x][y] = res + 1;
        y += delt_y;
      }
      x += delt_x;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      ST[i][j][0][0] =
          min(dp[0][i][j],
              min(dp[1][i][j + 1], min(dp[2][i + 1][j + 1], dp[3][i + 1][j])));
    }
  }
  int logn = Log[n], logm = Log[m];
  for (int leny = 1; leny <= logm; leny++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j + (1 << leny) - 1 < m; j++)
        ST[i][j][0][leny] = max(ST[i][j][0][leny - 1],
                                ST[i][j + (1 << (leny - 1))][0][leny - 1]);
  for (int lenx = 1; lenx <= logn; lenx++)
    for (int i = 0; i + (1 << lenx) - 1 < n; i++)
      for (int j = 0; j < m; j++)
        ST[i][j][lenx][0] = max(ST[i][j][lenx - 1][0],
                                ST[i + (1 << (lenx - 1))][j][lenx - 1][0]);
  for (int lenx = 1; lenx <= logn; lenx++) {
    for (int leny = 1; leny <= logm; leny++) {
      for (int i = 0; i + (1 << lenx) - 1 < n; i++) {
        for (int j = 0; j + (1 << leny) - 1 < m; j++) {
          ST[i][j][lenx][leny] =
              max(ST[i][j + (1 << (leny - 1))][lenx][leny - 1],
                  ST[i][j][lenx][leny - 1]);
        }
      }
    }
  }
}
int query(int x1, int y1, int x2, int y2) {
  int x_len = Log[x2 - x1 + 1], y_len = Log[y2 - y1 + 1];
  int a = max(ST[x1][y1][x_len][y_len],
              ST[x1][y2 - (1 << y_len) + 1][x_len][y_len]);
  int b = max(ST[x2 - (1 << x_len) + 1][y1][x_len][y_len],
              ST[x2 - (1 << x_len) + 1][y2 - (1 << y_len) + 1][x_len][y_len]);
  return max(a, b);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) scanf("%s", grid[i]);
  pre();
  for (int i = 0; i < q; i++) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--, y1--, x2--, y2--;
    int l = 1, r = min((x2 - x1 + 1) / 2, (y2 - y1 + 1) / 2) + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (query(x1 + mid - 1, y1 + mid - 1, x2 - mid, y2 - mid) >= mid)
        l = mid;
      else
        r = mid;
    }
    if (l < r && query(x1 + l - 1, y1 + l - 1, x2 - l, y2 - l) >= l)
      printf("%d\n", l * l * 4);
    else
      printf("0\n");
  }
}
