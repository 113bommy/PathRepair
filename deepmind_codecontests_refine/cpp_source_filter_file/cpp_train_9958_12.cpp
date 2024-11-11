#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int x[100010], y[10010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &y[i]);
  }
  int sum1 = 0, sum2 = 0;
  for (int r1 = 0, r2 = 0; r1 <= n, r2 <= m;) {
    while (sum1 < sum2 || r1 == 0) {
      r1++;
      sum1 += x[r1];
    }
    while (sum1 > sum2 || r2 == 0) {
      r2++;
      sum2 += y[r2];
    }
    if (sum1 == sum2) {
      ans++;
      r1++;
      r2++;
      sum1 = x[r1];
      sum2 = y[r2];
    }
  }
  printf("%d", ans);
  return 0;
}
