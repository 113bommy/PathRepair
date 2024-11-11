#include <bits/stdc++.h>
using namespace std;
long long dp[12][120][(1 << 11)][2];
int a[120];
int b;
long long dfs(int pos, int sta, bool g, bool limit) {
  if (pos == 0) {
    return (!sta) && g;
  }
  if (!limit && dp[b][pos][sta][g] != -1) return dp[b][pos][sta][g];
  int up = limit ? a[pos] : b - 1;
  long long tmp = 0;
  for (int i = 0; i <= up; i++) {
    bool nexg = ((g | i) > 0);
    long long nexs = sta;
    if (nexg) nexs ^= (1 << i);
    tmp += dfs(pos - 1, nexs, nexg, limit && i == a[pos]);
  }
  if (!limit) dp[b][pos][sta][g] = tmp;
  return tmp;
}
long long solve(long long k) {
  int pos = 0;
  while (k > 0) {
    a[++pos] = k % b;
    k /= b;
  }
  return dfs(pos, 0, 0, true);
}
int main(void) {
  long long le, ri;
  memset(dp, -1, sizeof dp);
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%d%I64d%I64d", &b, &le, &ri);
    printf("%I64d\n", solve(ri) - solve(le - 1));
  }
  return 0;
}
