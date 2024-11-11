#include <bits/stdc++.h>
using namespace std;
int v[151][3], dp[153][53][53][53];
char s[155];
void addV(int &x, int y) {
  x = (x + y) % 51123987;
  return;
}
bool isOK(int x, int y) { return x - y <= 1 && y - x <= 1; }
int main() {
  int n = 0, m = 0, res = 0;
  scanf("%d%s", &n, s + 1);
  m = n / 3 + 2;
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j < 3; ++j) {
      v[i][j] = v[i + 1][j];
    }
    v[i][s[i] - 'a'] = i;
  }
  dp[1][0][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int p = 0; p <= m; ++p) {
        for (int q = 0; q <= m; ++q) {
          int tmp = dp[i][j][p][q];
          if (tmp) {
            if (j + p + q == n && isOK(j, p) && isOK(p, q) && isOK(j, q)) {
              addV(res, tmp);
            }
            addV(dp[v[i][0]][j + 1][p][q], tmp);
            addV(dp[v[i][1]][j][p + 1][q], tmp);
            addV(dp[v[i][2]][j][p][q + 1], tmp);
          }
        }
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
