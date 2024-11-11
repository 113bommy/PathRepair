#include <bits/stdc++.h>
using namespace std;
int n, k, f[200021][2], sum[200021], g[200021][2];
char s[200021];
int main() {
  scanf("%d%d%s", &n, &k, s + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i] - '0');
  f[0][0] = f[0][1] = 1;
  g[n + 1][0] = g[n + 1][1] = 1;
  for (int i = 1; i <= n; i++) {
    f[i][0] = f[i - 1][0] && s[i] == '0';
    f[i][0] |= i <= k ? 1 : sum[i - k] == 0;
    f[i][1] = f[i - 1][1] && s[i] == '1';
    f[i][1] |= i <= k ? 1 : sum[i - k] == i - k;
  }
  for (int i = n; i >= 1; i--) {
    g[i][0] = g[i + 1][0] && s[i] == '0';
    g[i][0] |= i > n - k ? 1 : sum[n] - sum[i + k - 1] == 0;
    g[i][1] = g[i + 1][1] && s[i] == '1';
    g[i][1] |= i > n - k ? 1 : sum[n] - sum[i + k - 1] == n - (i + k - 1);
  }
  if (f[n][0] || f[n][1]) {
    puts("tokitsukaze");
    return 0;
  }
  bool ok = true;
  for (int i = k; i <= n; i++) {
    for (int t = 0; t < 2; t++) {
      bool z = (f[i - k][t] && (sum[n] - sum[i] == (n - i) * t || n == i)) ||
               ((i == k || sum[i - k - 1] == (i - k - 1) * t) && g[i + 1][t]);
      if (!z) ok = false;
    }
  }
  if (ok)
    puts("quailty");
  else
    puts("once again");
  return 0;
}
