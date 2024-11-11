#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int inf = 0x3f3f3f3f;
int n, m;
int l[102], r[102];
int dp[102][MAXN];
int q[MAXN], head, tail;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &l[i], &r[i]);
  for (int j = 0; j <= n; j++) dp[0][j] = inf;
  dp[0][0] = 0;
  for (int i = 1; i <= m; i++) {
    head = 1, tail = 0;
    for (int j = 0; j <= n; j++) dp[i][j] = dp[i - 1][j];
    for (int j = 0; j <= r[i]; j++) {
      while (head <= tail && q[head] < j - (r[i] - l[i])) head++;
      if (j <= n) {
        while (head <= tail && dp[i - 1][j] <= dp[i - 1][q[tail]]) tail--;
        q[++tail] = j;
      }
      if (head <= tail) dp[i][j] = min(dp[i][j], dp[i - 1][q[head]] + 2);
    }
    head = 1, tail = 0;
    for (int j = r[i]; j >= 0; j--) {
      while (head <= tail && q[head] < l[i] - j) head++;
      if (r[i] - j <= n) {
        while (head <= tail && dp[i - 1][r[i] - j] <= dp[i - 1][q[tail]])
          tail--;
        q[++tail] = r[i] - j;
      }
      if (head <= tail) dp[i][j] = min(dp[i][j], dp[i - 1][q[head]] + 1);
    }
  }
  if (dp[m][n] == inf)
    printf("Hungry");
  else
    printf("Full\n%d\n", dp[m][n]);
  return 0;
}
