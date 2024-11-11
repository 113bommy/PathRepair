#include <bits/stdc++.h>
using namespace std;
int sorta[5011], dp[5011];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    double x;
    scanf("%d%lf", &sorta[i], &x);
  }
  for (int i = 1; i <= n; i++) {
    int j = sorta[i];
    for (int k = j; k >= 1; k--) {
      dp[j] = max(dp[k] + 1, dp[j]);
    }
  }
  int longest = 0;
  for (int i = 1; i <= n; i++) longest = max(longest, dp[i]);
  printf("%d", n - longest);
  return 0;
}
