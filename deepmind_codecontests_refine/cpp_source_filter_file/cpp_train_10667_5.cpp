#include <bits/stdc++.h>
using namespace std;
int a[310][310];
int b[310];
int main() {
  int flag, n, tmp, s;
  cin >> n;
  char ch;
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) {
    getchar();
    for (int j = 1; j <= n; j++) {
      ch = getchar();
      a[i][j] = ch - '0';
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (i != j && i != k && j != k) {
          a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
        }
  flag = 1;
  while (flag) {
    flag = 0;
    for (int i = 1; i < n; i++)
      for (int j = n; j >= i + 1; j--) {
        if (a[i][j] == 1 && b[i] >= b[j]) {
          tmp = b[j];
          b[j] = b[i];
          b[i] = tmp;
          flag = 1;
        }
      }
  }
  for (int i = 1; i <= n - 1; i++) printf("%d ", b[i]);
  printf("%d\n", b[n]);
  return 0;
}
