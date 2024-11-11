#include <bits/stdc++.h>
using namespace std;
typedef const int &ci;
const int N = 1003;
const int K = 102;
int n, k, m;
int rt[N], pw[N];
int dp[N][K][2];
inline void Add(int &x, ci y) {
  x += y;
  if (x >= m) x -= m;
}
inline int Dfs(ci p, ci r, const bool &t) {
  if (~dp[p][r][t]) return dp[p][r][t];
  if (!r && !t) return dp[p][r][t] = rt[n - p + 1];
  if (p > n) return dp[p][r][t] = 0;
  int ret = 0;
  for (int i = 0; i <= 9; i++)
    Add(ret, Dfs(p + 1, (r + 1ll * pw[p] * i) % k, t & (i == 0)));
  return dp[p][r][t] = ret;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d %d %d", &n, &k, &m);
  rt[0] = pw[1] = 1, rt[1] = 9;
  for (int i = 2; i <= n; i++) {
    rt[i] = 10ll * rt[i - 1] % m;
    pw[i] = 10ll * pw[i - 1] % k;
  }
  printf("%d\n", Dfs(1, 0, 1));
  return 0;
}
