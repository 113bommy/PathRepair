#include <bits/stdc++.h>
using namespace std;
int S = (1 << 22) - 1;
int dp[(1 << 22) + 10];
int n, m, a[100005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    dp[a[i] ^ S] = a[i];
  }
  for (int i = S; i >= 0; i--) {
    if (!dp[i]) {
      for (int j = 0; j <= 21; j++) {
        if (dp[i | (1 << j)]) dp[i] = dp[i | (1 << j)];
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (dp[a[i]])
      printf("%d ", dp[a[i]]);
    else
      printf("-1 ");
}
