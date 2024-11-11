#include <bits/stdc++.h>
using namespace std;
const int MAXV = 1110;
int n, m, a[MAXV][MAXV], dp1[MAXV][MAXV], dp2[MAXV][MAXV], dp3[MAXV][MAXV],
    dp4[MAXV][MAXV];
void solve1() {
  memset(dp1, 0, sizeof(dp1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + a[i][j];
    }
}
void solve2() {
  memset(dp2, 0, sizeof(dp2));
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++) {
      dp2[i][j] = max(dp2[i + 1][j], dp2[i][j - 1]) + a[i][j];
    }
}
void solve3() {
  memset(dp3, 0, sizeof(dp3));
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--) {
      dp3[i][j] = max(dp3[i + 1][j], dp3[i][j + 1]) + a[i][j];
    }
}
void solve4() {
  memset(dp4, 0, sizeof(dp4));
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--) {
      dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + a[i][j];
    }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  solve1();
  solve2();
  solve3();
  solve4();
  int res = 0;
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++) {
      int t1 = dp1[i][j - 1] + dp3[i][j + 1] + dp2[i + 1][j] + dp4[i - 1][j];
      int t2 = dp1[i - 1][j] + dp3[i + 1][j] + dp2[i][j - 1] + dp4[i][j + 1];
      int tres = max(t1, t2);
      res = max(res, tres);
    }
  printf("%d\n", res);
  return 0;
}
