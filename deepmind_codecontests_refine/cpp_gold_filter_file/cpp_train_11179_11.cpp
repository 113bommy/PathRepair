#include <bits/stdc++.h>
using namespace std;
int n, k, a[22][10005], b[22][10005];
long long tmp;
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    int i, j;
    for (i = 0; i < n; i++) a[0][i] = 1;
    a[0][n] = 0;
    for (i = 1; i <= k; i++) {
      for (j = 1; j <= n; j++) {
        tmp = 1;
        tmp = tmp << i;
        if (n - j >= tmp) {
          a[i][j] = tmp;
          b[i][j] = n - (a[i][j] - a[i - 1][j]);
        } else {
          a[i][j] = n - j;
          b[i][j] = n - (a[i][j] - a[i - 1][j]);
        }
      }
    }
    for (i = 1; i <= k; i++)
      for (j = 1; j <= n; j++) {
        if (j != n)
          cout << b[i][j] << " ";
        else
          cout << b[i][j] << endl;
      }
  }
  return 0;
}
