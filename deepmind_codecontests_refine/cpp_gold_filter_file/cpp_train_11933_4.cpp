#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6, INF = 1e9;
int dp[maxn], p[20];
int main() {
  int a;
  scanf("%d", &a);
  p[1] = 1;
  p[2] = 2;
  dp[0] = 1;
  for (int i = 1; i <= 2; i++) {
    for (int j = 0; j < maxn - 5; j++) {
      if (dp[j] > INF) dp[j] = INF;
      if (dp[j]) dp[j + p[i]] = dp[j] + 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < maxn; i++) {
    if (dp[i] == a + 1) {
      ans = i;
      break;
    }
  }
  printf("%d 2\n", ans);
  for (int i = 1; i <= 2; i++) {
    printf("%d ", p[i]);
  }
}
