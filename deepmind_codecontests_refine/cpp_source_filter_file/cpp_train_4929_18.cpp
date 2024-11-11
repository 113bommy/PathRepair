#include <bits/stdc++.h>
using namespace std;
long long graph[60][60][60];
int n, m, r;
long long dp[60][60][60];
long long getAns(int cur, int tar, int left) {
  if (left > 59) return getAns(cur, tar, 59);
  long long &ret = dp[cur][tar][left];
  if (ret != -1) return ret;
  ret = 99999999;
  if (left == 1)
    for (int i = 0; i < m; i++) ret = min(ret, graph[i][cur][tar]);
  else if (left > 1)
    for (int i = 0; i < n; i++)
      ret = min(ret, getAns(cur, i, 1) + getAns(i, tar, left - 1));
  return ret;
}
int main(void) {
  scanf("%d %d %d", &n, &m, &r);
  for (int q = 0; q < m; q++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) scanf("%I64d", graph[q][i] + j);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          if (graph[q][i][k] + graph[q][k][j] < graph[q][i][j])
            graph[q][i][j] = graph[q][i][k] + graph[q][k][j];
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < r; i++) {
    int s, t, K;
    scanf("%d %d %d", &s, &t, &K);
    printf("%I64d\n", getAns(s - 1, t - 1, K + 1));
  }
  return 0;
}
