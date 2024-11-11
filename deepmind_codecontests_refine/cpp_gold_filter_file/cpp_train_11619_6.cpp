#include <bits/stdc++.h>
using namespace std;
int a[10005], b[10005];
int main() {
  int n, m, i, j, mark, x, y, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= m; i++) {
    int h = 0;
    scanf("%d%d%d", &x, &y, &k);
    if (k < x || k > y) {
      printf("Yes\n");
      continue;
    }
    mark = a[k];
    for (j = x; j <= y; j++)
      if (a[j] <= mark) h++;
    if (h + x - 1 == k)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
