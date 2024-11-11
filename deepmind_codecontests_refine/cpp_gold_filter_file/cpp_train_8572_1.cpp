#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int main() {
  scanf("%d%d%d", &n, &m, &s);
  if ((s & 1) == 0) {
    printf("0\n");
    return 0;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i += 2) {
    for (int j = 1; j <= m; j += 2) {
      int ss = s - i * j;
      if (ss < 0)
        break;
      else if (ss == 0) {
        ans += (i + 1) / 2 * ((j + 1) / 2) * (n - i + 1) * (m - j + 1);
        break;
      }
      for (int k = j + 2; k <= m; k += 2) {
        int kk = k - j;
        if (kk * i >= ss) {
          if (ss % kk == 0 && ss / kk % 2 == 1)
            ans += (n - i + 1) * (m - k + 1);
        } else {
          int sss = ss - kk * i;
          if (k * (n - i) >= sss && sss % k == 0 && sss / k % 2 == 0) {
            ans += (n - sss / k - i + 1) * (m - k + 1);
          }
        }
      }
      for (int k = i + 2; k <= n; k += 2) {
        int kk = k - i;
        if (kk * j >= ss && ss % kk == 0 && ss / kk % 2 == 1) {
          ans += (n - k + 1) * (m - j + 1);
        }
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
