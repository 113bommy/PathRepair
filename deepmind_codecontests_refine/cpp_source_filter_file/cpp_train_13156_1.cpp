#include <bits/stdc++.h>
using namespace std;
int const N = 2 * 1e5 + 5;
int ans = 0;
int i, j, n, m, k, z, y, x, t, mi, ma;
long long a[N];
long long dp[N][2], d[N][2];
char st[N];
int poisk(int x, int t) {
  if (dp[x][t] != 0) return dp[x][t];
  long long y = x;
  d[x][t]++;
  if (d[x][t] > 1) {
    d[x][t] = -1;
    return d[x][t];
  }
  if (t == 0)
    y += a[x];
  else
    y -= a[x];
  if (y < 1 || y > n) {
    dp[x][t] = a[x];
    return dp[x][t];
  }
  long long z = poisk(y, 1 - t);
  if (z > 0)
    dp[x][t] = a[x] + z;
  else
    dp[x][t] = -1;
  return dp[x][t];
}
int main() {
  scanf("%d", &n);
  for (i = 2; i <= n; i++) scanf("%I64d", &a[i]);
  for (i = 1; i < n; i++) {
    a[1] = i;
    d[1][0] = 0;
    long long k = poisk(1 + i, 1);
    if (k > 0) k += i;
    printf("%I64d\n", k);
  }
}
