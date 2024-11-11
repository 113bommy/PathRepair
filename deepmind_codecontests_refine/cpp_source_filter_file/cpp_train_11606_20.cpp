#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int n;
int main() {
  for (int i = 1; i <= 10; i++) a[i][1] = a[1][i] = 1;
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++) a[i][j] = a[i - 1][j] + a[i][j - 1];
  scanf("%d", &n);
  printf("%d\n", a[n][n]);
  return 0;
}
