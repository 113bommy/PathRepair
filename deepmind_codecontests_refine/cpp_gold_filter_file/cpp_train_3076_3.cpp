#include <bits/stdc++.h>
using namespace std;
int N, k;
int A[600];
bitset<505> dp[600];
int main() {
  while (~scanf("%d%d", &N, &k)) {
    for (int i = 0; i < N; i++) {
      scanf("%d", &A[i]);
    }
    for (int i = 0; i <= k; i++) {
      dp[i].reset();
    }
    dp[0].set(0);
    for (int i = 0; i < N; i++) {
      for (int j = k; j >= A[i]; j--) {
        dp[j] |= dp[j - A[i]] | (dp[j - A[i]] << A[i]);
      }
    }
    cout << dp[k].count() << endl;
    for (int i = 0; i <= k; i++) {
      if (dp[k][i]) {
        printf("%d\n", i);
      }
    }
  }
  return 0;
}
