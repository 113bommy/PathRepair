#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int ALPHA = 26;
const int inf = maxn * maxn;
struct item {
  int val, row, col;
  item() {}
  item(int v, int r, int c) {
    val = v;
    row = r;
    col = c;
  }
  inline item operator*(item& o) { return val < o.val ? *this : o; }
};
item UL[ALPHA][ALPHA];
item UR[ALPHA][ALPHA];
item DL[ALPHA][ALPHA];
item DR[ALPHA][ALPHA];
item best[ALPHA][ALPHA];
string s[maxn];
int Cnt[maxn][2][ALPHA];
item dp[maxn][ALPHA][ALPHA];
pair<int, int> opt[maxn][ALPHA][ALPHA];
void build(int idx) {
  for (int r = 0; r < ALPHA; r++) {
    for (int c = 0; c < ALPHA; c++) {
      UL[r][c] = dp[idx][r][c];
      if (r > 0) UL[r][c] = UL[r][c] * UL[r - 1][c];
      if (c > 0) UL[r][c] = UL[r][c] * UL[r][c - 1];
    }
  }
  for (int r = ALPHA - 1; r >= 0; r--) {
    for (int c = 0; c < ALPHA; c++) {
      DL[r][c] = dp[idx][r][c];
      if (r < ALPHA - 1) DL[r][c] = DL[r][c] * DL[r + 1][c];
      if (c > 0) DL[r][c] = DL[r][c] * DL[r][c - 1];
    }
  }
  for (int r = 0; r < ALPHA; r++) {
    for (int c = ALPHA - 1; c >= 0; c--) {
      UR[r][c] = dp[idx][r][c];
      if (r > 0) UR[r][c] = UR[r][c] * UR[r - 1][c];
      if (c < ALPHA - 1) UR[r][c] = UR[r][c] * UR[r][c + 1];
    }
  }
  for (int r = ALPHA - 1; r >= 0; r--) {
    for (int c = ALPHA - 1; c >= 0; c--) {
      DR[r][c] = dp[idx][r][c];
      if (r < ALPHA - 1) DR[r][c] = DR[r][c] * DR[r + 1][c];
      if (c < ALPHA - 1) DR[r][c] = DR[r][c] * DR[r][c + 1];
    }
  }
  for (int r = 0; r < ALPHA; r++) {
    for (int c = 0; c < ALPHA; c++) {
      best[r][c] = item(inf, r, c);
      if (r > 0 && c > 0) best[r][c] = best[r][c] * UL[r - 1][c - 1];
      if (r > 0 && c < ALPHA - 1) best[r][c] = best[r][c] * UR[r - 1][c + 1];
      if (r < ALPHA - 1 && c > 0) best[r][c] = best[r][c] * DL[r + 1][c - 1];
      if (r < ALPHA - 1 && c < ALPHA - 1)
        best[r][c] = best[r][c] * DR[r + 1][c + 1];
    }
  }
}
int main() {
  int n, m;
  scanf("%d %d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) Cnt[i][j][s[i][j] - 'a']++;
  }
  for (int i = 0; i < ALPHA; i++) {
    for (int j = 0; j < ALPHA; j++) {
      dp[0][i][j] = item((i == j) ? inf : 0, i, j);
    }
  }
  build(0);
  for (int i = 1; i <= n; i++) {
    for (int a = 0; a < ALPHA; a++) {
      for (int b = 0; b < ALPHA; b++) {
        if (a == b)
          dp[i][a][b] = item(inf, a, b);
        else {
          int D = m - Cnt[i][0][a] + Cnt[i][1][b];
          opt[i][a][b] = {best[a][b].row, best[a][b].col};
          dp[i][a][b] = item(best[a][b].val + D, a, b);
        }
      }
    }
    build(i);
  }
  auto Ans = dp[n][0][0];
  for (int a = 0; a < ALPHA; a++)
    for (int b = 0; b < ALPHA; b++) Ans = Ans * dp[n][a][b];
  printf("%d\n", Ans.val);
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < m; j++) {
      if (j & 1)
        s[i][j] = Ans.col + 'a';
      else
        s[i][j] = Ans.row + 'a';
    }
    auto nxt = opt[i][Ans.row][Ans.col];
    Ans = dp[i - 1][nxt.first][nxt.second];
  }
  for (int i = 1; i <= n; i++) printf("%s\n", s[i].c_str());
}
