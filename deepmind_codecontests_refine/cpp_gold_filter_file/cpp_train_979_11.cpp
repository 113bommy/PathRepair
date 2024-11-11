#include <bits/stdc++.h>
using namespace std;
int sum[110], a, ans[110];
bool cmp(int a, int b) { return a > b; }
int main() {
  int i, j, n, m;
  scanf("%d", &n);
  int r = 0;
  int C = 0, J = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &m);
    scanf("%d", &a);
    sum[0] = a;
    for (j = 1; j < m; j++) {
      scanf("%d", &a);
      sum[j] = sum[j - 1] + a;
    }
    if (m & 1) {
      ans[r++] = sum[m / 2] - sum[m / 2 - 1];
      J += sum[m - 1] - sum[m / 2];
    } else
      J += sum[m - 1] - sum[m / 2 - 1];
    C += sum[m / 2 - 1];
  }
  sort(ans, ans + r, cmp);
  for (i = 0; i < r; i++)
    if ((i & 1) == 0)
      C += ans[i];
    else
      J += ans[i];
  printf("%d %d\n", C, J);
  return 0;
}
