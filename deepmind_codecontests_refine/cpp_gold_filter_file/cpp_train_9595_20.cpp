#include <bits/stdc++.h>
using namespace std;
int a[1010], f[1010][1010], n, k, pre[1010][1010];
int solve(int x) {
  f[0][0] = 1;
  pre[0][0] = 1;
  int tl = 0;
  for (int i = 1; i <= n; i++) {
    while (a[i] - a[tl + 1] >= x) tl++;
    for (int j = 1; j <= k; j++) {
      f[i][j] = 0;
      f[i][j] = f[i][j] + pre[tl][j - 1];
      if (f[i][j] >= 998244353) f[i][j] = f[i][j] - 998244353;
      pre[i][j] = pre[i - 1][j] + f[i][j];
      if (pre[i][j] >= 998244353) pre[i][j] = pre[i][j] - 998244353;
    }
    pre[i][0] = 1;
  }
  return pre[n][k];
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int res = 0;
  for (int i = 1; i <= (a[n] - a[1]) / (k - 1); i++)
    res = (res + solve(i)) % 998244353;
  printf("%d\n", res);
  return 0;
}
