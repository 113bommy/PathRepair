#include <bits/stdc++.h>
using namespace std;
const int DIM = 1e4 + 5;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
char arr[5][DIM], mat[5][DIM];
int dp[DIM][8];
void back2(int x, int msk, int p, int nmsk) {
  if (p == 4)
    dp[x][nmsk] = (dp[x][nmsk] + dp[x - 1][msk]) % MOD;
  else {
    if (((msk >> (p - 1)) & 1) == 1)
      back2(x, msk, p + 1, nmsk + (1 << (p - 1)) * (mat[p][x] == 'X'));
    if (p <= 2 && ((msk >> (p - 1)) & 1) == 1 && ((msk >> p) & 1) == 1 &&
        mat[p][x] == '.' && mat[p + 1][x] == '.')
      back2(x, msk, p + 2, nmsk + (1 << (p - 1)) + (1 << p));
    if (((msk >> (p - 1)) & 1) == 0 && mat[p][x] == '.')
      back2(x, msk, p + 1, nmsk + (1 << (p - 1)));
  }
  return;
}
int solve(int n) {
  memset(dp, 0, sizeof(dp));
  dp[0][7] = 1;
  for (int i = 1; i <= n; i++) {
    for (int msk = 0; msk <= 7; msk++) {
      if (dp[i - 1][msk] == 0) continue;
      back2(i, msk, 1, 0);
    }
  }
  return dp[n][7];
}
void back(int x, int y, int n, int p, int &ans) {
  int px = x + dx[p], py = y + dy[p];
  if (p == 4)
    ans = (ans - solve(n) + MOD) % MOD;
  else {
    if (px < 1 || px > 3 || py < 1 || py > n || mat[px][py] == 'X')
      back(x, y, n, p + 1, ans);
    for (int d = (p + 3) % 4, ok = 1; ok == 1 || d != (p + 3) % 4;
         d = (d + 2) % 4, ok = 0) {
      int vx = px + dx[d], vy = py + dy[d];
      char ch1 = mat[px][py], ch2 = mat[vx][vy];
      if (vx < 1 || vx > 3 || vy < 1 || vy > n || mat[vx][vy] == 'X') continue;
      mat[px][py] = mat[vx][vy] = 'X';
      back(x, y, n, p + 1, ans);
      mat[px][py] = ch1;
      mat[vx][vy] = ch2;
    }
  }
  return;
}
int main(void) {
  int n;
  cin >> n;
  int px = 0, py = 0;
  for (int i = 1; i <= 3; i++) {
    cin >> (arr[i] + 1);
    for (int j = 1; j <= n; j++) {
      mat[i][j] = arr[i][j];
      if (arr[i][j] == 'O') {
        px = i;
        py = j;
        mat[i][j] = 'X';
      }
    }
  }
  int ans = solve(n);
  back(px, py, n, 0, ans);
  cout << ans << endl;
  return 0;
}
