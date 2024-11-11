#include <bits/stdc++.h>
using namespace std;
int n, m;
int pre[1050];
int rec[1050][1050];
int tot;
int cnt[1050];
int upp[1050];
bool exs[1050];
int tag;
double c[1050][1050];
double dp[1050][1050];
int main() {
  scanf("%d%d", &n, &m);
  tot = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &cnt[i]);
    for (int j = 1; j <= cnt[i]; j++) {
      scanf("%d", &rec[i][j]);
      pre[++tot] = rec[i][j];
    }
  }
  sort(pre + 1, pre + 1 + tot);
  tag = pre[tot - n + 1];
  memset(exs, false, sizeof(exs));
  memset(upp, 0, sizeof(upp));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
      if (rec[i][j] == tag)
        exs[i] = true;
      else if (rec[i][j] > tag)
        upp[i]++;
    }
  }
  for (int i = 1; i <= 1005; i++)
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        c[i][j] = 1;
      else
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  int eql = 0;
  int supp = 0;
  for (int i = 1; i <= m; i++)
    if (exs[i]) eql++;
  for (int i = 1; i <= m; i++) supp += upp[i];
  for (int i = 0; i <= 1005; i++)
    for (int j = 0; j <= 1005; j++) dp[i][j] = 0;
  dp[0][0] = 1;
  for (int i = 1; i <= m; i++)
    for (int j = 0; j <= n - supp; j++) {
      if (exs[i] && j) {
        dp[i][j] = dp[i - 1][j] / c[cnt[i]][upp[i]] +
                   dp[i - 1][j - 1] / c[cnt[i]][upp[i] + 1];
      } else {
        dp[i][j] = dp[i - 1][j] / c[cnt[i]][upp[i]];
      }
    }
  printf("%.11f\n", dp[m][n - supp] / c[eql + supp][n]);
}
