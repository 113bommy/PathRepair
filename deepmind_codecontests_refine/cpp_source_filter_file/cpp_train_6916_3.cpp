#include <bits/stdc++.h>
int FASTBUFFER;
using namespace std;
int n, k, i, j, l, len, s, x, ans;
int mi[1000005];
int f[505][505];
int sumi(int a, int b);
int main() {
  mi[0] = 1;
  for (i = 1; i <= 1000000; i++) mi[i] = mi[i - 1] * 2 % 1000000007;
  scanf("%d %d", &n, &k);
  if (k == 0) {
    printf("1\n");
    return 0;
  }
  f[0][0] = 1;
  for (i = 1; i <= k; i++)
    for (j = 1; j <= n; j++) {
      f[i][j] = 0;
      for (l = 0; l < j; l++) {
        if (f[i - 1][l] == 0) continue;
        len = j - l;
        s = (n - j) * len + len;
        x = mi[s];
        x = mi[(n - j) * len];
        x %= 1000000007;
        while (x < 0) x += 1000000007;
        (f[i][j] += (long long)f[i - 1][l] * x % 1000000007) %= 1000000007;
      }
      if (i == k) (ans += f[i][j]) %= 1000000007;
    }
  printf("%d\n", ans);
  return 0;
}
int sumi(int a, int b) {
  int ret = 1, c = a;
  while (b) {
    if (b & 1) ret = (long long)ret * c % 1000000007;
    c = (long long)c * c % 1000000007;
    b >>= 1;
  }
  return ret;
}
