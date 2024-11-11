#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int i, j, k, m, n, l;
int a[N + 10][3], b[N + 10][3];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 0; j < 3; j++) scanf("%d", &a[i][j]);
  scanf("%d", &m);
  for (i = 1; i <= m; i++)
    for (j = 0; j < 3; j++) scanf("%d", &b[i][j]);
  int ans = 0;
  for (i = 1; i <= n; i++) {
    int tmp = INT_MAX;
    for (j = 1; j <= m; j++) {
      if (b[j][0] < a[i][2])
        k = INT_MAX;
      else {
        l = b[j][1] * b[j][0] / a[i][2];
        k = ((a[i][0] + a[i][1]) * 2 + l - 1) / l * b[j][2];
      }
      tmp = min(tmp, k);
    }
    ans += tmp;
  }
  printf("%d\n", ans);
  return 0;
}
