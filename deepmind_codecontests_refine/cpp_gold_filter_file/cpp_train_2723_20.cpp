#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
pair<int, int> v[55];
int dp[2][55][55][55], inv[3005], ans[2];
int liked, disliked;
int exp(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = ((long long)r * a) % MOD;
    b /= 2;
    a = ((long long)a * a) % MOD;
  }
  return r;
}
inline void add(int& a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
inline int mul(int a, int b) { return ((long long)a * b) % MOD; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &v[i].first);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i].second);
    liked += v[i].first * v[i].second;
    disliked += (!v[i].first) * v[i].second;
  }
  for (int i = 0; i <= 3000; i++) inv[i] = exp(i, MOD - 2);
  dp[1][1][0][0] = dp[0][1][0][0] = 1;
  for (int w = 1; w < 51; w++)
    for (int i = 0; i < m; i++)
      for (int j = 0; j <= i; j++) {
        int k = i - j;
        if (liked + j + disliked - k <= 0) continue;
        int aux = inv[liked + j + disliked - k];
        add(dp[1][w][i + 1][j + 1],
            mul(mul(dp[1][w][i][j], (liked + j - w)), aux));
        add(dp[1][w][i + 1][j], mul(mul(dp[1][w][i][j], (disliked - k)), aux));
        add(dp[1][w + 1][i + 1][j + 1], mul(mul(dp[1][w][i][j], w), aux));
      }
  for (int w = 1; w > 0; w--)
    for (int i = 0; i < m; i++)
      for (int j = 0; j <= i; j++) {
        int k = i - j;
        if (liked + j + disliked - k <= 0) continue;
        int aux = inv[liked + j + disliked - k];
        add(dp[0][w][i + 1][j],
            mul(mul(dp[0][w][i][j], (disliked - k - w)), aux));
        add(dp[0][w][i + 1][j + 1], mul(mul(dp[0][w][i][j], (liked + j)), aux));
        add(dp[0][w - 1][i + 1][j], mul(mul(dp[0][w][i][j], w), aux));
      }
  for (int i = 0; i <= 1; i++)
    for (int w = 0; w <= 51; w++)
      for (int j = 0; j <= m; j++) add(ans[i], mul(w, dp[i][w][m][j]));
  for (int cur = 0; cur < n; cur++)
    printf("%d\n", mul(ans[v[cur].first], v[cur].second));
  return 0;
}
