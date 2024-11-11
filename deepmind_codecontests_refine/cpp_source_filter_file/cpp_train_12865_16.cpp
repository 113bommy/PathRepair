#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  int mat[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &mat[i][j]);
    }
  }
  vector<int> dp(n + 1, 0);
  for (int j = 1; j <= m; j++) {
    vector<int> dp2(n + 1, 0);
    for (int k = n - 1; k >= 1; k--) {
      if (mat[k][j] <= mat[k + 1][j]) dp2[k] = 1 + dp2[k + 1];
    }
    for (int i = 1; i <= n; i++) dp[i] = max(dp[i], dp2[i]);
  }
  int k, l, r;
  scanf("%d", &k);
  while (k--) {
    scanf("%d", &l);
    scanf("%d", &r);
    if (l + dp[l] >= r)
      printf("YES");
    else
      printf("NO");
    printf("\n");
  }
}
