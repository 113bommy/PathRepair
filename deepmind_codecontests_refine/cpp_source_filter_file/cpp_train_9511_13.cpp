#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1005], app;
double dp[1005][1005], C[1005][1005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int x;
      scanf("%d", &x);
      arr[i].push_back(x);
      app.push_back(x);
    }
  }
  for (int i = 0; i < 1004; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  sort(app.begin(), app.end(), greater<int>());
  int cnt = 0, tot = 0;
  while (app[cnt] != app[n - 1]) cnt++;
  tot = cnt;
  while (app[tot] == app[n - 1]) tot++;
  dp[0][0] = 1;
  for (int i = 0; i < m; i++) {
    int k = arr[i].size(), x = 0, y = 0;
    for (int j = 0; j < k; j++) {
      x += arr[i][j] > app[n - 1];
      y += arr[i][j] == app[n - 1];
    }
    for (int j = 0; j <= n - cnt; j++) {
      if (j <= n - cnt) dp[i + 1][j] += dp[i][j] / C[k][x];
      if (j < n - cnt && y) dp[i + 1][j + 1] += dp[i][j] / C[k][x + 1];
    }
  }
  printf("%.12lf\n", dp[m][n - cnt] / C[tot][n - cnt]);
  return 0;
}
