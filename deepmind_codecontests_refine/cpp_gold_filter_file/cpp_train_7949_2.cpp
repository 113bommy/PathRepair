#include <bits/stdc++.h>
using namespace std;
const int N = 13, mod = 1e9 + 7, M = 510;
const double PI = 3.1415926535;
long long res[40], p[40], ei[40], sum[N], n;
double pre[N];
long long dp[N][N][N][N];
char str[N];
int path[100];
void dfs(int u, int s, long long va) {
  if (u == -1) {
    sum[s] = ((long long)sum[s] + va) % mod;
    return;
  }
  for (int i = 0; i <= n; i++) {
    path[i]++;
    if (res[i] - path[i] + 1)
      dfs(u - 1, s + i, (long long)va * (res[i] - path[i] + 1) % mod);
    path[i]--;
  }
}
int main() {
  scanf("%s", str + 1);
  dp[0][0][0][0] = 1;
  n = strlen(str + 1);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 10; j++)
      for (int k = 0; k <= 10; k++)
        for (int r = 0; r < 10; r++)
          for (int z = 0; z < 2; z++) {
            int f = j, s = k, st = z;
            if (r == 4) f++;
            if (r == 7) s++;
            if (z == 0 && r > str[i + 1] - '0') continue;
            if (z == 0 && r < str[i + 1] - '0') st = 1;
            dp[i + 1][f][s][st] += dp[i][j][k][z];
          }
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      for (int k = 0; k < 2; k++)
        if (i + j <= n) res[i + j] += dp[n][i][j][k];
    }
  }
  res[0]--;
  dfs(5, 0, 1);
  long long ans = 0, pre = 0;
  for (int i = 1; i <= n; i++) {
    pre = pre + sum[i - 1];
    ans = (ans + pre * res[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
