#include <bits/stdc++.h>
using namespace std;
long long m, k;
long long f[100][100][2];
long long calc(long long o) {
  memset(f, 0, sizeof(f));
  f[63][0][1] = 1;
  for (int i = 62; i >= 0; i--)
    for (int j = 0; j <= 63; j++) {
      if (f[i + 1][j][0]) {
        f[i][j][0] += f[i + 1][j][0];
        f[i][j + 1][0] += f[i + 1][j][0];
      }
      if (f[i + 1][j][1]) {
        if (o & (1LL << i))
          f[i][j][0] += f[i + 1][j][1], f[i][j + 1][1] = 1;
        else
          f[i][j][1] = 1;
      }
    }
  return f[0][k][0];
}
int main() {
  scanf("%I64d%I64d", &m, &k);
  long long L = 1, R = (long long)1e18, mid, ans, sum;
  while (L <= R) {
    mid = (L + R) >> 1;
    sum = calc(mid * 2 + 1) - calc(mid + 1);
    if (sum == m) {
      ans = mid;
      break;
    }
    if (sum > m)
      R = mid - 1;
    else
      L = mid + 1;
  }
  printf("%I64d", ans);
  return 0;
}
