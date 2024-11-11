#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[400005], b[400005];
int h[21];
long long dp[2100000];
long long f[21][21];
int num[21];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (!h[a[i]]) h[a[i]] = ++m;
    b[i] = h[a[i]];
  }
  for (int i = n; i >= 1; i--) {
    num[b[i]]++;
    for (int j = 1; j <= m; j++)
      if (j != b[i]) f[b[i]][j] += num[j];
  }
  memset(dp, 0x3f3f3f3f, sizeof dp);
  for (int i = 1; i <= m; i++) dp[1 << (i - 1)] = 0;
  for (int s = 1; s < (1 << m); s++) {
    for (int i = 1; i <= m; i++) {
      if (!(s & (1 << (i - 1)))) {
        int ns = s | (1 << (i - 1));
        long long tmp = 0;
        for (int j = 1; j <= m; j++) {
          if (s & (1 << (j - 1))) tmp += f[i][j];
        }
        dp[ns] = min(dp[ns], dp[s] + tmp);
      }
    }
  }
  printf("%lld", dp[(1 << m) - 1]);
  return 0;
}
