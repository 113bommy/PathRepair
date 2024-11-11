#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 15;
const int mod = 1e9 + 7;
unordered_map<int, int> ff;
int n, dp[2][maxn], cur, C[maxn][maxn], fac[maxn], inv[maxn];
int power(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1LL * ret * x % mod;
    y >>= 1;
    x = 1LL * x * x % mod;
  }
  return ret;
}
inline void Update(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main(int argc, char* argv[]) {
  C[0][0] = fac[0] = inv[0] = 1;
  for (int i = 1; i <= 300; ++i) {
    C[i][0] = 1;
    fac[i] = 1LL * fac[i - 1] * i % mod;
    inv[i] = power(fac[i], mod - 2);
    for (int j = 1; j <= i; ++j) Update(C[i][j], C[i - 1][j - 1] + C[i - 1][j]);
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x, z = 1;
    scanf("%d", &x);
    for (int j = 2; j * j <= x; ++j)
      if (x % j == 0) {
        int cnt = 0;
        while (x % j == 0) x /= j, ++cnt;
        if (cnt & 1) z *= j;
      }
    z *= x;
    ++ff[z];
  }
  dp[cur][0] = 1;
  int sum = 0;
  for (auto&& it : ff) {
    int x = it.second;
    int pre = cur;
    cur ^= 1;
    memset(dp[cur], 0, sizeof(dp[cur]));
    for (int i = 0; i <= sum; ++i)
      for (int j = 1; j <= x; ++j)
        if (dp[pre][i]) {
          int y = 1LL * dp[pre][i] * C[x - 1][j - 1] % mod;
          y = 1LL * y * inv[j] % mod;
          if ((x - j) & 1) y = mod - y;
          Update(dp[cur][i + j], y);
        }
    sum += x;
  }
  int ans = 0;
  for (int i = 0; i <= sum; ++i) Update(ans, 1LL * dp[cur][i] * fac[i] % mod);
  for (auto&& it : ff) ans = 1LL * ans * fac[it.second];
  printf("%d\n", ans);
  return 0;
}
