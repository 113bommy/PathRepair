#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 10;
long long f[20][70][maxn], l, r, g[20][70][maxn], sum[20][70][maxn];
int q, k, tot, d[100], tmp[100];
void dp(int x) {
  f[x][0][0] = 1;
  for (int i = 0; i < 60; i++) {
    for (int j = 0; j < (1 << x); j++)
      if (f[x][i][j])
        for (int k = 0; k < x; k++) {
          int nj = j ^ (1 << k);
          f[x][i + 1][nj] += f[x][i][j];
        }
  }
  for (int i = 0; i <= 60; i++)
    for (int j = 0; j < (1 << x); j++)
      for (int k = 1; k < x; k++) g[x][i + 1][j ^ (1 << k)] += f[x][i][j];
  for (int j = 0; j < (1 << x); j++) {
    sum[x][0][j] = g[x][0][j];
    for (int i = 1; i <= 60; i++) sum[x][i][j] = sum[x][i - 1][j] + g[x][i][j];
  }
}
void split(long long x) {
  tot = 0;
  while (x) {
    tmp[++tot] = x % k;
    x /= k;
  }
  for (int i = 1; i <= tot; i++) d[i] = tmp[tot + 1 - i];
}
long long dfs(int be, int s, int p, int sta) {
  if (s == 1) {
    if (be)
      return f[k][tot - p + 1][sta];
    else
      return sum[k][tot - p + 1][sta];
  }
  if (p == tot + 1) return sta == 0;
  long long res = 0;
  for (int i = 0; i < d[p]; i++)
    if (be || i)
      res += dfs(1, 1, p + 1, sta ^ (1 << i));
    else
      res += dfs(0, 1, p + 1, 0);
  res += dfs(1, 0, p + 1, sta ^ (1 << d[p]));
  return res;
}
long long calc(long long x) {
  if (!x) return 0;
  split(x);
  return dfs(0, 0, 1, 0);
}
int main() {
  for (int i = 2; i <= 10; i++) dp(i);
  scanf("%d", &q);
  while (q--) {
    scanf("%d%lld%lld", &k, &l, &r);
    printf("%lld\n", calc(r) - calc(l - 1));
  }
}
