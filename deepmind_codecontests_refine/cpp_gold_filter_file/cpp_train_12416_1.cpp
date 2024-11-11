#include <bits/stdc++.h>
using namespace std;
const int nn = 1100000;
const int inff = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos(-1.0);
const long long mod = (479 << 21) + 1;
bitset<200010> b, c;
int a[nn];
int dp[nn];
int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= n; i++) {
    scanf("%d", &a[i]);
    b[a[i]] = 1;
  }
  for (int i = 0; i < n; i++) c |= (b >> a[i]);
  for (int i = 1; i <= x; i++) {
    if (c[i] > 0) {
      dp[i + y] = i + y;
      for (int j = 2 * (i + y); j <= (1 << 19); j += (i + y)) {
        dp[j] = i + y;
      }
    }
  }
  int q;
  scanf("%d", &q);
  int l;
  while (q--) {
    scanf("%d", &l);
    if (dp[l / 2] == -1) {
      printf("-1 ");
    } else {
      printf("%d ", 2 * dp[l / 2]);
    }
  }
  printf("\n");
  return 0;
}
