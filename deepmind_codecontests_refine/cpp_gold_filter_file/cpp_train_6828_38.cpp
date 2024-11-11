#include <bits/stdc++.h>
using namespace std;
int n, a[100000 + 7], q, p, k, dp[500][100001];
int main() {
  cin >> n;
  for (int i = (0); i < (n); i++) scanf("%d", a + i);
  for (int i = (1); i < (500); i++) {
    for (int j = n - 1; j >= 0; j--) {
      dp[i][j] = 1;
      if (j + a[j] + i < n) dp[i][j] += dp[i][j + a[j] + i];
    }
  }
  cin >> q;
  for (int i = (0); i < (q); i++) {
    scanf("%d%d", &p, &k);
    p--;
    if (k < 500)
      printf("%d\n", dp[k][p]);
    else {
      int res = 0;
      while (p < n) {
        p = p + a[p] + k;
        res++;
      }
      printf("%d\n", res);
    }
  }
  return 0;
}
