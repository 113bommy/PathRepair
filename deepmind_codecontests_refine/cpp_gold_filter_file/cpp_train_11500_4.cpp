#include <bits/stdc++.h>
using namespace std;
bool flag;
long long ans[10][10], co[10][10][10], line[10];
void init() {
  for (int i = 1; i <= 8; i++) {
    cin >> co[i][1][0] >> co[i][2][0] >> co[i][3][0];
    co[i][1][1] = co[i][1][0];
    co[i][2][1] = co[i][3][0];
    co[i][3][1] = co[i][2][0];
    co[i][1][2] = co[i][2][0];
    co[i][2][2] = co[i][1][0];
    co[i][3][2] = co[i][3][0];
    co[i][1][3] = co[i][2][0];
    co[i][2][3] = co[i][3][0];
    co[i][3][3] = co[i][1][0];
    co[i][1][4] = co[i][3][0];
    co[i][2][4] = co[i][1][0];
    co[i][3][4] = co[i][2][0];
    co[i][1][5] = co[i][3][0];
    co[i][2][5] = co[i][2][0];
    co[i][3][5] = co[i][1][0];
  }
}
void dfs(int l) {
  if (l > 8) {
    for (int i = 2; i <= 8; i++) {
      line[i - 1] = 0;
      for (int j = 1; j <= 3; j++)
        line[i - 1] += (ans[i][j] - ans[1][j]) * (ans[i][j] - ans[1][j]);
    }
    sort(line + 1, line + 8);
    if (line[1] == line[3] && line[4] == line[6])
      if (line[4] == 2 * line[1] && line[7] == 3 * line[1]) flag = true;
    return;
  }
  for (int i = 0; i < 6; i++) {
    ans[l][1] = co[l][1][i];
    ans[l][2] = co[l][2][i];
    ans[l][3] = co[l][3][i];
    bool no_can = false;
    for (int j = l - 1; j >= 1; j--)
      if (ans[l][1] == ans[j][1] && ans[l][2] == ans[j][2] &&
          ans[l][3] == ans[j][3]) {
        no_can = true;
        break;
      }
    if (no_can) continue;
    dfs(l + 1);
    if (flag) return;
  }
}
void solve() {
  flag = false;
  dfs(1);
  if (flag) {
    cout << "YES" << endl;
    for (int i = 1; i <= 8; i++)
      cout << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << endl;
  } else
    cout << "NO" << endl;
}
int main() {
  init();
  solve();
}
