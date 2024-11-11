#include <bits/stdc++.h>
using namespace std;
int a[4010];
int dp[4010][4010];
vector<int> e[200010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    e[a[i]].push_back(i);
    dp[0][i] = 1;
  }
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      int t = a[i];
      int left = 0, right = e[t].size() - 1, mid, p = -1;
      while (left <= right) {
        mid = (left + right) >> 1;
        if (e[t][mid] < j) {
          left = mid + 1;
          p = mid;
        } else
          right = mid - 1;
      }
      if (p != -1) {
        dp[i][j] = dp[j][p] + 1;
      } else
        dp[i][j] = 2;
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
}
