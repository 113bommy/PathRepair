#include <bits/stdc++.h>
using namespace std;
const int NMAX = 507;
int n, k, c[NMAX], dp[2][NMAX][NMAX];
vector<int> res;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int now = i % 2;
    int last = 1 - now;
    for (int j = 0; j <= k; j++) {
      for (int t = 0; t <= j; t++) {
        dp[now][j][t] |= dp[last][j][t];
        if (j >= c[i]) {
          dp[now][j][t] |= dp[last][j - c[i]][t];
          if (t >= c[i]) dp[now][j][t] |= dp[last][j - c[i]][t - c[i]];
        }
      }
    }
  }
  for (int i = 0; i <= 25000; i++)
    if (dp[n % 2][k][i]) res.push_back(i);
  printf("%d\n", res.size());
  for (auto it : res) printf("%d ", it);
  return 0;
}
