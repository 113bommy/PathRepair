#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, q, num[5], dp[N][2];
int ans;
bool ty[5][N];
char ch;
int main() {
  scanf("%d %d %d\n", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    ch = getchar();
    if (ch == 'B') ty[1][i] = 1, num[1]++;
  }
  getchar();
  for (int i = 1; i <= n; i++) {
    ch = getchar();
    if (ch == 'B') ty[2][i] = 1, num[2]++;
  }
  getchar();
  for (int i = 1; i <= m; i++) {
    ch = getchar();
    if (ch == 'B') ty[3][i] = 1, num[3]++;
  }
  getchar();
  for (int i = 1; i <= m; i++) {
    ch = getchar();
    if (ch == 'B') ty[4][i] = 1, num[4]++;
  }
  getchar();
  dp[0][0] = num[1];
  dp[0][1] = n - num[1];
  for (int i = 1; i <= m; i++) {
    dp[i][0] = min(dp[i - 1][0] + ty[3][i] + ty[4][i],
                   dp[i - 1][1] + n + 2 - ty[3][i] - ty[4][i]);
    dp[i][1] = min(dp[i - 1][0] + n + ty[3][i] + ty[4][i],
                   dp[i - 1][1] + 2 - ty[3][i] - ty[4][i]);
  }
  ans = min(dp[m][0] + num[2], dp[m][1] + n - num[2]);
  dp[0][0] = num[3];
  dp[0][1] = m - num[3];
  for (int i = 1; i <= n; i++) {
    dp[i][0] = min(dp[i - 1][0] + ty[1][i] + ty[2][i],
                   dp[i - 1][1] + m + 2 - ty[1][i] - ty[2][i]);
    dp[i][1] = min(dp[i - 1][0] + m + ty[1][i] + ty[2][i],
                   dp[i - 1][1] + 2 - ty[1][i] - ty[2][i]);
  }
  ans = min(ans, min(dp[n][0] + num[4], dp[n][1] + n - num[4]));
  cout << ans;
}
