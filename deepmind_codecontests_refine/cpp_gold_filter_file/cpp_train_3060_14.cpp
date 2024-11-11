#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, L;
int a[2000010];
double an, x;
int main() {
  scanf("%d%d%d", &n, &L, &t);
  if (n == 1) printf("%.12lf\n", 0), exit(0);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), a[n + i] = a[i] + L;
  j = 1;
  t *= 2;
  x = t / L, t %= L;
  for (i = 1; i <= n; i++) {
    for (; j < n * 2 && a[j] - a[i] <= t; j++)
      ;
    an += j - i - 1;
  }
  printf("%.12lf\n", (an + x * n * (n - 1)) / 4);
  return 0;
}
