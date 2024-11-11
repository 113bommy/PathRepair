#include <bits/stdc++.h>
using namespace std;
static int dp[2000][300];
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  vector<pair<int, int> > v;
  if (n < 2 * k + 1) {
    printf("-1\n");
    return 0;
  } else {
    printf("%lld\n", n * k);
    for (int i = 1; i <= n; i++) {
      int j = i + 1;
      for (int c = 0; c < k; c++) {
        if (j > n) {
          j %= n;
        }
        printf("%d %d\n", i, j);
        j += 1;
      }
    }
  }
}
