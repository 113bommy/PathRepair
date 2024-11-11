#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[2010];
long long f[2010][2010], g[2010][2010], ans;
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  f[0][0] = 1;
  g[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      f[i][j] += 1LL * g[i - 1][j] * (s[i] - 'a');
      f[i][j] %= 1000000007;
      for (int pre = 1; pre <= i; pre++) {
        if (j < pre * (n - i + 1)) break;
        f[i][j] += 1LL * f[i - pre][j - pre * (n - i + 1)] * ('z' - s[i]);
        f[i][j] %= 1000000007;
      }
      g[i][j] = g[i - 1][j] + f[i][j];
      g[i][j] %= 1000000007;
    }
  }
  printf("%I64d", g[n][k]);
}
