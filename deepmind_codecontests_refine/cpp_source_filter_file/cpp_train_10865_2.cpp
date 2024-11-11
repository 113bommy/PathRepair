#include <bits/stdc++.h>
using namespace std;
int n;
int a[4010], dp[4010][4010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    int p = 0;
    for (int j = 0; j < i; ++j) {
      dp[j][i] = dp[p][j] + 1;
      if (a[i] == a[j]) p = j;
      mx = max(mx, dp[i][j]);
    }
  }
  printf("%d\n", mx);
  return 0;
}
