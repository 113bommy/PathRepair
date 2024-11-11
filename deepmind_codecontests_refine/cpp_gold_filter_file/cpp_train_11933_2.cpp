#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000005;
int A;
int dp[MAXN];
int main() {
  scanf("%d", &A);
  dp[0] = 1;
  for (int k = (1); k < (3); k++)
    for (int i = (0); i < (MAXN - k); i++) {
      dp[i + k] += dp[i];
    }
  int ans;
  for (int i = (1); i < (MAXN); i++) {
    if (dp[i] == A) {
      ans = i;
      break;
    }
  }
  printf("%d %d\n", ans, 2);
  printf("%d %d\n", 1, 2);
  return 0;
}
