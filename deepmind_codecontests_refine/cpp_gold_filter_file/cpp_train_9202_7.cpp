#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = acos(-1);
template <class T>
void add(T &a, T b) {
  a += b;
  if (a >= mod) a -= mod;
}
int n, tx, ty;
int dp[N][1 << 3][2];
int state[N];
char Map[3][N];
bool can(int x, int y, int op) {
  if (op == 0)
    return Map[x][y] == '.' && Map[x][y + 1] == '.';
  else
    return Map[x][y] == '.' && Map[x + 1][y] == '.';
}
bool ok(int x, int y, int op) {
  if (op == 0) {
    if (x != tx) return false;
    return y + 2 == ty || y - 1 == ty;
  } else {
    if (y != ty) return false;
    return x + 2 == tx || x - 1 == tx;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; i++) scanf("%s", Map[i] + 1);
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= n; j++) {
      if (Map[i][j] == 'O') {
        tx = i;
        ty = j;
        i = 3;
        break;
      }
    }
  }
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i < 3; i++)
      if (Map[i][j] != '.') state[j] |= 1 << i;
  }
  dp[1][state[1]][0] = 1;
  for (int j = 0; j <= n; j++) {
    for (int mask = 0; mask < (1 << 3); mask++) {
      for (int k = 0; k < 2; k++) {
        if (mask == 0) {
          if (can(0, j, 0) && can(1, j, 0) && can(2, j, 0))
            add(dp[j + 1][7 | state[j + 1]]
                  [k || ok(0, j, 0) || ok(1, j, 0) || ok(2, j, 0)],
                dp[j][mask][k]);
          if (can(0, j, 0) && can(1, j, 1))
            add(dp[j + 1][1 | state[j + 1]][k || ok(0, j, 0) || ok(1, j, 1)],
                dp[j][mask][k]);
          if (can(0, j, 1) && can(2, j, 0))
            add(dp[j + 1][4 | state[j + 1]][k || ok(0, j, 1) || ok(2, j, 0)],
                dp[j][mask][k]);
        } else if (mask == 1) {
          if (can(1, j, 0) && can(2, j, 0))
            add(dp[j + 1][6 | state[j + 1]][k || ok(1, j, 0) || ok(2, j, 0)],
                dp[j][mask][k]);
          if (can(1, j, 1))
            add(dp[j + 1][0 | state[j + 1]][k || ok(1, j, 1)], dp[j][mask][k]);
        } else if (mask == 2) {
          if (can(0, j, 0) && can(2, j, 0))
            add(dp[j + 1][5 | state[j + 1]][k || ok(0, j, 0) || ok(2, j, 0)],
                dp[j][mask][k]);
        } else if (mask == 3) {
          if (can(2, j, 0))
            add(dp[j + 1][4 | state[j + 1]][k || ok(2, j, 0)], dp[j][mask][k]);
        } else if (mask == 4) {
          if (can(0, j, 0) && can(1, j, 0))
            add(dp[j + 1][3 | state[j + 1]][k || ok(0, j, 0) || ok(1, j, 0)],
                dp[j][mask][k]);
          if (can(0, j, 1))
            add(dp[j + 1][0 | state[j + 1]][k || ok(0, j, 1)], dp[j][mask][k]);
        } else if (mask == 5) {
          if (can(1, j, 0))
            add(dp[j + 1][2 | state[j + 1]][k || ok(1, j, 0)], dp[j][mask][k]);
        } else if (mask == 6) {
          if (can(0, j, 0))
            add(dp[j + 1][1 | state[j + 1]][k || ok(0, j, 0)], dp[j][mask][k]);
        } else if (mask == 7) {
          add(dp[j + 1][0 | state[j + 1]][k], dp[j][mask][k]);
        }
      }
    }
  }
  printf("%d\n", dp[n + 1][0][1]);
  return 0;
}
