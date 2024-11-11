#include <bits/stdc++.h>
using namespace std;
int n, m, h, x, z, s, i;
double comb(int n, int r) {
  int i;
  double s = 0;
  for (i = 1; i <= r; i++) s -= log(i);
  for (i = 1; i <= n - r; i++) s -= log(i);
  for (i = 1; i <= n; i++) s += log(i);
  return s;
}
int main() {
  scanf("%d%d%d", &n, &m, &h);
  for (i = 1; i <= m; i++) {
    scanf("%d", &x);
    s += x;
    if (i == h) z = x;
  }
  if (s - 1 < n - 1)
    printf("-1");
  else if (s - z < n - 1)
    printf("1");
  else
    printf("%.10lf", 1 - exp(comb(s - z, n - 1) - comb(s - 1, n - 1)));
  return 0;
}
