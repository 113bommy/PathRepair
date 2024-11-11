#include <bits/stdc++.h>
using namespace std;
int a[2005], nr[2][4005], dp[2][2005][2][4005], sum[2][2005], sq[4005], u;
vector<pair<int, int>> g[2005];
bitset<4005> num;
void dfs(int nod) {
  int i, sz = g[nod].size(), x, y;
  for (i = 0; i < sz; i++) {
    x = g[nod][i].first;
    y = g[nod][i].second;
    if (num[y] == 0) {
      num[y] = 1;
      if (x != 1)
        dfs(x);
      else
        u++;
      a[u]++;
    }
  }
}
int main() {
  int n, m, x, y, i, i1, j1, aux, j, k, u1, ans = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++)
    scanf("%d%d", &x, &y), g[x].push_back({y, i}), g[y].push_back({x, i});
  dfs(1);
  for (i1 = 0; i1 <= 1; i1++) {
    aux = !i1 * 2 - 1;
    for (j1 = 0; j1 <= 1; j1++) dp[i1][(u + 1) * i1][j1][0] = 1;
    for (i = 1 + (u - 1) * i1; i && i <= u; i = i + aux) {
      sum[i1][i] = sum[i1][i - aux] + a[i];
      for (j1 = 0; j1 <= 1; j1++)
        for (j = 0; j <= sum[i1][i]; j++) {
          dp[i1][i][j1][j] = dp[i1][i - aux][j1][j] * j1;
          for (u1 = -1; u1 <= 1; u1 += 2)
            if (j + a[i] * u1 >= -sum[i1][i - aux] &&
                j + a[i] * u1 <= sum[i1][i - aux])
              dp[i1][i][j1][j] =
                  (dp[i1][i][j1][j] + dp[i1][i - aux][j1][abs(j + a[i] * u1)]) %
                  1000000007;
        }
    }
  }
  ans = dp[0][u][0][0];
  for (i = 1; i <= u; i++)
    for (j1 = 0; j1 <= 1; j1++) {
      for (j = 0; j <= m; j++) sq[j] = 0;
      for (j = -sum[0][i - 1]; j <= sum[0][i - 1]; j++)
        for (k = max(-sum[1][i + 1], -j); k <= min(sum[1][i + 1], a[i] - j);
             k++)
          sq[j + k] =
              (1LL * dp[0][i - 1][j1][abs(j)] * dp[1][i + 1][j1][abs(k)] +
               sq[j + k]) %
              1000000007;
      if (j1 == 0)
        ans = (1LL * sq[a[i] - 1] * 4 + ans) % 1000000007;
      else
        for (j = 1; j < a[i]; j++)
          ans = ((1LL * sq[abs(j - (a[i] - j))] +
                  sq[abs(j - (a[i] - j - 1))] * (j < a[i] - 1)) *
                     2 +
                 ans) %
                1000000007;
    }
  printf("%d\n", ans);
  return 0;
}
