#include <bits/stdc++.h>
using namespace std;
const int N = 1100000;
const int INF = 1000000005;
int n, m;
char c[22][22];
int a[22][22], sm[22][22], Tm[22][22], mn[22];
int dp[N], mp[N];
int main() {
  for (int i = 1; i < N; i++) dp[i] = INF;
  scanf("%d%d", &n, &m);
  int tmp = 1;
  while (mp[tmp] < 20) {
    mp[tmp * 2] = mp[tmp] + 1;
    tmp *= 2;
  }
  for (int i = 0; i < n; i++) scanf("%s", c + i);
  for (int i = 0; i < n; i++) {
    mn[i] = INF;
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      mn[i] = min(mn[i], a[i][j]);
    }
  }
  for (int i = 0; i < n; i++)
    for (int k = 0; k < m; k++) {
      int mx = 0;
      for (int j = 0; j < n; j++)
        if (c[i][k] == c[j][k]) {
          sm[i][k] |= 1 << j;
          mx = max(mx, a[j][k]);
          Tm[i][k] += a[j][k];
        }
      Tm[i][k] -= mx;
    }
  for (int i = 1; i < (1 << n); i++) {
    int lb = i & (i - 1) ^ i;
    int mmp = mp[lb];
    if (dp[i ^ lb] != INF) dp[i] = min(dp[i], dp[i ^ lb] + mn[mmp]);
    for (int j = 0; j < m; j++)
      dp[i] = min(dp[i], dp[i ^ sm[mmp][j]] + Tm[mmp][j]);
  }
  printf("%d\n", dp[(1 << n) - 1]);
  return 0;
}
