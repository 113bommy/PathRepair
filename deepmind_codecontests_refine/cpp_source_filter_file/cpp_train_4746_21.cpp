#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int INF = ((1 << 31) - 1);
const long long LLINF = (((1LL << 63) - 1LL));
const double eps = 1e-9;
const double PI = 3.14159265358979323846;
char buf[1 << 20 - 2];
int mod = 1e9 + 7;
int dp[300][300][2][2];
int n, m;
vector<vector<int> > plan;
int add(int x, int y) {
  int res = x + y;
  if (res >= mod) return res - mod;
  return res;
}
bool canVert(int x, int y) {
  static int special[10] = {0, 0, 1, 2, 1, 2, 0, 0, 1, 2};
  return special[x] != 1 && special[y] != 1;
}
bool canHor(int x, int y) {
  static int special[10] = {0, 0, 1, 2, 1, 2, 0, 0, 1, 2};
  return special[x] != 2 && special[y] != 2;
}
int solve(int x, int y, int is_double_move, int satisfied) {
  if (x == m - 1 && is_double_move) return 0;
  if (dp[x][y][is_double_move][satisfied] >= 0)
    return dp[x][y][is_double_move][satisfied];
  int& res = dp[x][y][is_double_move][satisfied];
  res = 0;
  if (y == n) {
    if (is_double_move && satisfied == 0) return res = 0;
    return res = add(solve(x + 1 + is_double_move, 0, 0, 0),
                     solve(x + 1 + is_double_move, 0, 1, 0));
  }
  if (x == m) {
    if (y != 0) return 0;
    if (is_double_move && satisfied == 0) return res = 0;
    return res = 1;
  }
  if (is_double_move) {
    if (canHor(plan[y][x], plan[y][x + 1]))
      res = add(res, solve(x, y + 1, is_double_move, 1));
    if (y + 1 < n && canVert(plan[y][x], plan[y + 1][x]) &&
        canVert(plan[y][x + 1], plan[y + 1][x + 1]))
      res = add(res, solve(x, y + 2, is_double_move, satisfied));
  } else {
    if (y + 1 < n && canVert(plan[y][x], plan[y + 1][x]))
      res = add(res, solve(x, y + 2, is_double_move, satisfied));
  }
  return res;
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  plan.assign(n, vector<int>(m, -1));
  for (int i = 0; i < n; ++i) {
    vector<string> line;
    for (int j = 0; j < 4; ++j) {
      scanf("%s", buf);
      if (j > 0) line.push_back(string(buf));
    }
    for (int j = 0; j < m; ++j) {
      string sum = line[0].substr(1 + j * 4, 3) + line[1].substr(1 + j * 4, 3) +
                   line[2].substr(1 + j * 4, 3);
      int num = count((sum).begin(), (sum).end(), 'O');
      if (num == 0)
        plan[i][j] = 0;
      else if (num == 1)
        plan[i][j] = 1;
      else if (num == 2) {
        if (sum[0] == 'O')
          plan[i][j] = 3;
        else
          plan[i][j] = 2;
      } else if (num == 3) {
        if (sum[0] == 'O')
          plan[i][j] = 5;
        else
          plan[i][j] = 4;
      } else if (num == 4) {
        plan[i][j] = 6;
      } else if (num == 5) {
        plan[i][j] = 7;
      } else if (num == 6) {
        if (sum[1] == 'O')
          plan[i][j] = 9;
        else
          plan[i][j] = 8;
      } else {
      }
    }
  }
  scanf("%s", buf);
  cout << add(solve(0, 0, 0, 0), solve(0, 0, 1, 0)) << "\n";
  return 0;
}
