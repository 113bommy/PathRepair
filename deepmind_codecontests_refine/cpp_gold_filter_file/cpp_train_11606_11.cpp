#include <bits/stdc++.h>
using namespace std;
int a[20][20];
int main() {
  int n;
  scanf("%d", &n);
  int i, j;
  for (i = 1; i <= n; i++) a[1][i] = 1;
  for (i = 1; i <= n; i++) a[i][1] = 1;
  int mx = 1;
  for (i = 2; i <= n; i++)
    for (j = 2; j <= n; j++) {
      a[i][j] = a[i - 1][j] + a[i][j - 1];
      mx = max(mx, a[i][j]);
    }
  printf("%d\n", mx);
  return 0;
}
