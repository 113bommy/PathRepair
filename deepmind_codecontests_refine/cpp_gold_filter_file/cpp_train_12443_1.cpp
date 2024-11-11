#include <bits/stdc++.h>
using namespace std;
long long s, x, dp[105][105][2][2];
int ls, lx, sum[105], _xor[105];
void conv(long long v, int &l, int *a) {
  if (v == 0) {
    a[++l] = 0;
    return;
  }
  for (; v > 0; v /= 2) a[++l] = v % 2;
}
long long F(int i, int c, int z1, int z2) {
  if (i > max(lx, ls)) {
    return c == 0 && z1 == 0 && z2 == 0;
  }
  if (dp[i][c][z1][z2] != -1) return dp[i][c][z1][z2];
  long long ans = 0;
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      int q = a ^ b;
      if (q != _xor[i]) continue;
      int v = (a + b + c) % 2;
      int nc = (a + b + c) / 2;
      if (v == sum[i]) ans += F(i + 1, nc, z1 && a == 0, z2 && b == 0);
    }
  }
  return dp[i][c][z1][z2] = ans;
}
int main() {
  scanf("%I64d%I64d", &s, &x);
  conv(s, ls, sum);
  conv(x, lx, _xor);
  memset(dp, -1, sizeof(dp));
  printf("%I64d\n", F(1, 0, 1, 1));
  return 0;
}
