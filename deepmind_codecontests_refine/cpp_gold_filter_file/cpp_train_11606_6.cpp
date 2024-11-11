#include <bits/stdc++.h>
using namespace std;
int a[20][20];
int main() {
  int n;
  scanf("%d", &n);
  int res = 1;
  for (int i = 1; i <= n; ++i) a[1][i] = 1, a[i][1] = 1;
  for (int i = 2; i <= n; ++i)
    for (int j = 2; j <= n; ++j)
      res = max(res, a[i][j] = a[i - 1][j] + a[i][j - 1]);
  printf("%d\n", res);
}
