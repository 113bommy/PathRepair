#include <bits/stdc++.h>
using namespace std;
int n, f[1000 + 5][1000 + 5];
int main() {
  scanf("%d", &n);
  if (n == 4) {
    puts("-1");
    return 0;
  }
  bool flag;
  if (n & 1)
    flag = 0;
  else
    flag = 1;
  n--;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++)
      if (j - i & 1)
        f[j][i] = 1;
      else
        f[i][j] = 1;
  if (flag) {
    n++;
    f[1][n] = f[2][n] = 1;
    for (int i = 3; i < n; i++) f[n][i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d ", f[i][j]);
    puts("");
  }
  return 0;
}
