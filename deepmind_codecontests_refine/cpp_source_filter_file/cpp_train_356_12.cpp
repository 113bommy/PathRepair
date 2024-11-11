#include <bits/stdc++.h>
using namespace std;
int n, k;
double f[2][600];
int main() {
  scanf("%d%d", &n, &k);
  int t = min(n, 500);
  int now = 1;
  for (int i = 1; i <= n; i++, now ^= 1)
    for (int j = t; j; j--)
      f[now][j] = ((f[now ^ 1][j + 1] + j) / (j + 1.0) +
                   j * (f[now ^ 1][j] + (j + 1.0) / 2.0) / (j + 1.0)) /
                      (k * 1.0) +
                  (k - 1) * f[now ^ 1][j] / (k * 1.0);
  printf("%.10lf", k * f[now ^ 1][1]);
}
