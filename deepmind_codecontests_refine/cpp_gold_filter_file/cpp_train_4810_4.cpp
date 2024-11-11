#include <bits/stdc++.h>
using namespace std;
int n, m;
long long int k;
int pri;
pair<int, int> p[198];
bool brac[198], check[198];
long long int dp[100][100];
void init() {
  scanf("%d %d %lld", &n, &m, &k);
  for (int i = 0; i <= n + m - 2; i++) p[i] = {1 << 30, i};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &pri);
      p[i + j].first = min(p[i + j].first, pri);
    }
  }
  sort(p, p + m + n - 1);
  for (int i = 0; i < n + m - 1; i++) check[i] = false;
}
long long int call(int x, int y) {
  if (y < 0 || x < 0 || x < y || x > (n + m - 1) / 2 || y > (n + m - 1) / 2)
    return 0;
  return dp[x][y];
}
void solve(int pos) {
  brac[p[pos].second] = false;
  check[p[pos].second] = true;
  dp[0][0] = 1;
  if (k == 1) dp[0][0] = -1;
  for (int i = 1; i <= (n + m - 1) / 2; i++) {
    for (int j = 0; j <= i; j++) {
      if (!check[i + j - 1]) {
        if (call(i - 1, j) < 0 || call(i, j - 1) < 0)
          dp[i][j] = -1;
        else {
          dp[i][j] = call(i - 1, j) + call(i, j - 1);
          if (dp[i][j] >= k) dp[i][j] = -1;
        }
      } else if (!brac[i + j - 1]) {
        dp[i][j] = call(i - 1, j);
      } else {
        dp[i][j] = call(i, j - 1);
      }
    }
  }
  if (dp[(n + m - 1) / 2][(n + m - 1) / 2] >= 0) {
    brac[p[pos].second] = true;
    k -= dp[(n + m - 1) / 2][(n + m - 1) / 2];
  }
}
int main() {
  init();
  for (int i = 0; i < n + m - 1; i++) {
    solve(i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", (brac[i + j] ? ')' : '('));
    }
    printf("\n");
  }
}
