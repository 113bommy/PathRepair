#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m;
int a[N];
int main() {
  scanf("%d%d", &n, &m);
  if (m == 0) {
    puts("0.00000000000");
    return 0;
  }
  int i;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  double Max = 0;
  for (i = 1; i <= m; i++) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &x);
    if (1.0 * (a[x] + a[y]) / c > Max) Max = 1.0 * (a[x] + a[y]) / c;
  }
  printf("%.6\n", Max);
  return 0;
}
