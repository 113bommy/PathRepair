#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MOD = 1000000007;
const double PI = acos(-1.0);
const int MAXN = 40;
const int SIZE = 16;
int ipt[110];
int dp[110][1 << SIZE];
int p[110][1 << SIZE];
int x[110][1 << SIZE];
int to[MAXN + 1];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
map<int, int> mp;
void init() {
  for (int i = 0; i < (SIZE); ++i) mp[prime[i]] = 1 << i;
  for (int ii = (0); ii <= (MAXN); ++ii) {
    int n = ii, ret = 0, i;
    for (i = 0; i < SIZE && prime[i] * prime[i] <= n; i++)
      if (n % prime[i] == 0) {
        while (n % prime[i] == 0) n /= prime[i];
        ret += 1 << i;
      }
    if (n > 1) ret += mp[n];
    to[ii] = ret;
  }
}
int n;
void dfs(int idx, int id) {
  if (idx >= 2) dfs(idx - 1, p[idx][id]);
  printf("%d%c", x[idx][id], idx == n ? '\n' : ' ');
}
int main() {
  int all = 1 << SIZE;
  init();
  while (~scanf("%d", &n)) {
    for (int i = (1); i <= (n); ++i) scanf("%d", &ipt[i]);
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for (int i = (0); i <= (n - 1); ++i) {
      for (int j = (0); j < (all); ++j) {
        for (int jj = (0); jj <= (MAXN); ++jj) {
          int v = to[jj];
          if (j & v) continue;
          int val = dp[i][j] + abs(jj - ipt[i + 1]);
          int& nxt = dp[i + 1][j | v];
          if (val < nxt) {
            nxt = val;
            p[i + 1][j | v] = j;
            x[i + 1][j | v] = jj;
          }
        }
      }
    }
    int ans = INF, id = 0;
    for (int j = 0; j < (all); ++j) {
      if (dp[n][j] < ans) {
        ans = dp[n][j];
        id = j;
      }
    }
    dfs(n, id);
  }
  return 0;
}
