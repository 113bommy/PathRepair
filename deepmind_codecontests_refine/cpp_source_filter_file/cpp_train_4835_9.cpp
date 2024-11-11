#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, k;
int a[N][N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  int ans = INT_MAX;
  if (m <= k) {
    for (int i = 0; i < (1 << m); i++) {
      int sum = 0;
      for (int j = 0; j < n; j++) {
        int x = 0;
        for (int k = 0; k < m; k++) {
          if (a[j][k] != (i & (1 << k))) x++;
        }
        sum += min(x, m - x);
      }
      ans = min(ans, sum);
    }
  } else {
    for (int i = 0; i < m; i++) {
      int sum = 0;
      for (int j = 0; j < m; j++) {
        int x = 0;
        for (int k = 0; k < n; k++)
          if (a[k][i] != a[k][j]) x++;
        sum += min(x, n - x);
      }
      ans = min(ans, sum);
    }
  }
  if (ans > k) ans = -1;
  printf("%d\n", ans);
  return 0;
}
