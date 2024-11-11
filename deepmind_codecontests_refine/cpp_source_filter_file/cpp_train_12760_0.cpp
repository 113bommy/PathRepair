#include <bits/stdc++.h>
using namespace std;
const int MAXN = 320;
int dir[8][2] = {{-1, 0}, {-1, +1}, {0, +1}, {+1, +1},
                 {+1, 0}, {+1, -1}, {0, -1}, {-1, -1}};
bool dp[MAXN][MAXN][8][8];
int n, t[32];
bool spot[MAXN][MAXN];
void Rec(int l, int x, int y, int d) {
  if (l > n) return;
  if (dp[x][y][d][t[l]])
    return;
  else
    dp[x][y][d][t[l]] = true;
  for (int i = 1; i <= t[l]; ++i) {
    spot[x + i * dir[d][0]][y + i * dir[d][1]] = true;
  }
  int le = (d != 0) ? d - 1 : 7;
  int ri = (d != 7) ? d + 1 : 0;
  Rec(l + 1, x + dir[d][0] * t[l], y + dir[d][1] * t[l], le);
  Rec(l + 1, x + dir[d][0] * t[l], y + dir[d][1] * t[l], ri);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }
  Rec(1, 160, 160, 0);
  int cnt = 0;
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      if (spot[i][j]) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
