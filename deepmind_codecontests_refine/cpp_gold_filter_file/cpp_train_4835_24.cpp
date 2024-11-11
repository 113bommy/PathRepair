#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  int ans = n * m + 5;
  if (n > k) {
    for (int i = 0; i < n; i++) {
      int ret = 0;
      for (int j = 0; j < n; j++)
        if (i != j) {
          int t1 = 0, t2 = 0;
          for (int k = 0; k < m; k++)
            if (a[i][k] != a[j][k])
              t1++;
            else
              t2++;
          ret += m - max(t1, t2);
        }
      ans = min(ans, ret);
    }
  } else {
    for (int id = 0; id <= (1 << n) - 1; id++) {
      int ret = 0;
      for (int j = 0; j < m; j++) {
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++) {
          if ((id & (1 << i)) == (a[i][j] << i))
            t1++;
          else
            t2++;
        }
        ret += n - max(t1, t2);
      }
      ans = min(ans, ret);
    }
  }
  if (ans <= k)
    printf("%d", ans);
  else
    printf("-1");
}
