#include <bits/stdc++.h>
using namespace std;
vector<int> V[2];
int dp[2][7005], v[2][7005], n;
int Sech(int x, int y) {
  int i, t, sum, temp;
  if (dp[x][y] != 2) return dp[x][y];
  if (v[x][y]) return dp[x][y];
  sum = 0;
  v[x][y] = 1;
  for (i = 0; i < V[x].size(); i++) {
    t = (y + V[x][i]) % (n + 1);
    if (t == 0) {
      dp[x][y] = 1;
      return dp[x][y];
    }
  }
  for (i = 0; i < V[x].size(); i++) {
    t = (y + V[x][i]) % (n + 1);
    temp = Sech(x ^ 1, t);
    if (temp == -1) {
      dp[x][y] = 1;
      return dp[x][y];
    }
    if (temp == 1) sum += 1;
  }
  if (sum == V[x].size()) {
    dp[x][y] = -1;
    return dp[x][y];
  }
  return dp[x][y];
}
int main(void) {
  int i, m, x, j;
  for (i = 0; i <= 7000; i++) dp[0][i] = dp[1][i] = 2;
  scanf("%d%d", &n, &m);
  n -= 1;
  for (i = 1; i <= m; i++) {
    scanf("%d", &x);
    V[0].push_back(x);
  }
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d", &x);
    V[1].push_back(x);
  }
  for (j = 1; j <= 8; j++) {
    memset(v, 0, sizeof(v));
    for (i = 1; i <= n; i++) {
      Sech(0, i);
      Sech(1, i);
    }
  }
  for (i = 0; i <= 1; i++) {
    for (j = 1; j <= n; j++) {
      if (dp[i][j] == 1)
        printf("Win ");
      else if (dp[i][j] == -1)
        printf("Lose ");
      else
        printf("Loop ");
    }
    printf("\n");
  }
  return 0;
}
