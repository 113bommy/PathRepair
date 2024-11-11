#include <bits/stdc++.h>
using namespace std;
int n, m, a[51][51], min1;
int main() {
  min1 = 4;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] && i == 1 || a[i][j] && j == 1 || a[i][j] && i == n ||
          a[i][j] && j == m)
        min1 = 2;
    }
  printf("%d\n", min1);
}
