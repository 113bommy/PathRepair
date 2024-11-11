#include <bits/stdc++.h>
using namespace std;
int n, now;
long long pnt[5005], son[5005];
long long up[2][10005], down[5005][5005], cnt[5005];
long long inv = 1, p = 1000000007 - 2, x = 2;
int main() {
  while (p > 0) {
    if ((p & 1) == 1) {
      inv *= x;
      inv %= 1000000007;
    }
    p >>= 1;
    x *= x;
    x %= 1000000007;
  }
  scanf("%d", &n);
  pnt[1] = 1;
  up[0][0] = 1;
  for (register int i = 1; i < n; i++) {
    scanf("%lld", &son[i]);
    pnt[i + 1] = pnt[i] * son[i];
    pnt[i + 1] %= 1000000007;
  }
  for (register int i = 1; i <= n; i++) {
    down[i][0] = 1;
    for (register int j = 1; j + i <= n; j++) {
      down[i][j] += down[i][j - 1] * son[i + j - 1] % 1000000007;
      down[i][j] %= 1000000007;
    }
  }
  for (register int i = 2; i <= n; i++) {
    now = (i & 1) ^ 1;
    up[now][0] = 1;
    for (register int j = 1; j <= ((n - 1) << 1); j++) {
      up[now][j] = 0;
    }
    for (register int j = 1; j <= ((n - 1) << 1); j++) {
      up[now][j] += up[now ^ 1][j - 1];
      up[now][j] %= 1000000007;
      if (j > 1 && j <= n + 1) {
        up[now][j] += down[i - 1][j - 1] - down[i][j - 2];
        up[now][j] += 1000000007;
        up[now][j] %= 1000000007;
      }
    }
    for (register int j = 1; j <= ((n - 1) << 1); j++) {
      cnt[j] += (up[now][j] + (j < i)) % 1000000007 * pnt[i] % 1000000007;
      cnt[j] %= 1000000007;
    }
  }
  for (register int i = 1; i < ((n - 1) << 1); i++) {
    printf("%lld ", cnt[i] * inv % 1000000007);
  }
  printf("%lld\n", cnt[(n - 1) << 1] * inv % 1000000007);
  return 0;
}
