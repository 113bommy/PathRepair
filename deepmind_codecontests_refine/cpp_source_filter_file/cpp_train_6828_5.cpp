#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int INF = -0x3f3f3f3f;
int a[MAXN];
int dp[MAXN][500];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= n + n; ++j) {
      if (i + a[i] + j > n)
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i + a[i] + j][j] + 1;
    }
  }
  int ans = 0;
  int m;
  scanf("%d", &m);
  int p, k;
  while (m--) {
    ans = 0;
    scanf("%d%d", &p, &k);
    if (k > 400) {
      while (p <= n) {
        p = p + a[p] + k;
        ans++;
      }
      printf("%d\n", ans);
    } else
      printf("%d\n", dp[p][k]);
  }
  return 0;
}
