#include <bits/stdc++.h>
long long k, a, b, l, r, ansa, ansb, A[5][5], B[5][5], vis[5][5], s[29][2];
long long xxx(long long x, long long y) {
  return (x == 3 && y == 2) || (x == 2 && y == 1) || (x == 3 && y == 1);
}
void dfs(long long x, long long y, long long d) {
  vis[x][y] = d;
  s[d][0] = xxx(x, y);
  s[d][1] = xxx(y, x);
  long long xx = A[x][y], yy = B[x][y];
  if (vis[xx][yy]) {
    l = vis[xx][yy];
    r = d;
    return;
  }
  dfs(xx, yy, d + 1);
}
int main() {
  scanf("%lld%lld%lld", &k, &a, &b);
  for (long long i = 1; i < 4; i++)
    for (long long j = 1; j < 4; j++) scanf("%lld", &A[i][j]);
  for (long long i = 1; i < 4; i++)
    for (long long j = 1; j < 4; j++) scanf("%lld", &B[i][j]);
  dfs(a, b, 1);
  for (long long i = 1; i <= std::min(k, r); i++)
    ansa += s[i][0], ansb += s[i][1];
  if (k <= r) {
    printf("%lld %lld", ansa, ansb);
    return 0;
  }
  k -= r;
  long long t = r - l + 1;
  for (long long i = l; i <= r; i++)
    ansa += k / t * s[i][0], ansb += k / t * s[i][1];
  for (long long i = l; i <= l + k % t - 1; i++)
    ansa += s[i][0], ansb += s[i][1];
  printf("%lld %lld", ansa, ansb);
  return 0;
}
