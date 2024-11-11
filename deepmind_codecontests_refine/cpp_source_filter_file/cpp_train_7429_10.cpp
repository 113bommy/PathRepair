#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
const int MAXN2 = 1e2 + 1;
int a[MAXN];
long double ans;
int sz[MAXN];
long double dp[MAXN][MAXN2];
long double dp2[MAXN2];
int sz2[MAXN];
long double c(int a, int b) {
  long double ans = 1.;
  for (int i = 0; i < b; i++) {
    ans *= (1. * a - i) / (b - i);
  }
  return ans;
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sz[i] = a[i];
    dp[i][a[i]] = 1;
    sz2[i] = a[i];
    if (!sz[i]) ans++;
  }
  int q;
  scanf("%d", &q);
  int from, to, k;
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d", &from, &to, &k);
    from--;
    to--;
    for (int j = 0; j <= sz[from]; j++) {
      dp2[j] = 0;
    }
    for (int j = 0; j <= sz[from] && j <= sz2[from]; j++) {
      for (int h = 0; h <= j && h <= k; h++) {
        if (j < h || k < h) continue;
        long double cur =
            dp[from][j] * c(j, h) / c(sz[from], k) * c(sz[from] - j, k - h);
        dp2[j - h] += cur;
      }
    }
    ans += dp2[0] - dp[from][0];
    for (int j = 0; j <= sz[from]; j++) {
      dp[from][j] = dp2[j];
    }
    sz[from] -= k;
    sz[to] += k;
    printf("%.15lf\n", (double)ans);
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
