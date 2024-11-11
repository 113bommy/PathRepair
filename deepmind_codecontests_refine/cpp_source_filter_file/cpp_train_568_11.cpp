#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const double PI = acos(-1);
using namespace std;
const int MAX = 20;
long long dp[MAX + 1][1 << MAX];
char str[MAX][26];
int cost[MAX][MAX], who[MAX][26];
long long sum[MAX][26];
int n, m;
const long long oo = 1LL << 60;
int lookup[1 << 20];
long long solve() {
  for (int msk = 0; msk < (1 << n); msk++) dp[m][msk] = oo;
  dp[m][(1 << n) - 1] = 0L;
  for (int pos = m - 1; pos >= 0; pos--)
    for (int msk = (1 << n) - 1; msk >= 0; msk--) {
      dp[pos][msk] = dp[pos + 1][msk];
      long long ret = dp[pos][msk];
      for (int omsk = ((1 << n) - 1) ^ msk, cur; omsk;
           omsk ^= ((omsk) & (-(omsk)))) {
        cur = lookup[((msk) & (-(msk)))];
        ret = min(ret, dp[pos][msk | (1 << cur)] + cost[cur][pos]);
        int c = str[cur][pos] - 'a';
        ret =
            min(ret, dp[pos][msk | who[pos][c]] + sum[pos][c] - cost[cur][pos]);
      }
      dp[pos][msk] = ret;
    }
  return dp[0][0];
}
int main() {
  for (int i = 0; i < (MAX); i++) lookup[1 << i] = i;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < (n); i++) scanf("%s", str[i]);
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++) scanf("%d", &cost[i][j]);
  for (int pos = 0; pos < m; pos++)
    for (int i = 0; i < n; i++) {
      int c = str[i][pos] - (int)'a';
      sum[pos][c] += cost[i][pos];
      who[pos][c] |= 1 << i;
    }
  cout << solve() << endl;
  return 0;
}
