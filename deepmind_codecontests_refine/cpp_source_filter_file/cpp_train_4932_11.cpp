#include <bits/stdc++.h>
using namespace std;
double d[60][2510] = {0};
double fact[100];
int a[60], n, len;
void Init() {
  fact[0] = 1;
  for (int i = 1; i <= 50; i++) fact[i] = fact[i - 1] * i;
}
int main() {
  Init();
  scanf("%d", &n);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  if (sum < len) {
    printf("%d", n);
    return 0;
  }
  double ans = 0;
  scanf("%d", &len);
  if (sum < len) {
    printf("%d", n);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    memset(d, 0, sizeof(d));
    d[0][0] = 1;
    for (int j = 1; j <= n; j++)
      if (j != i) {
        for (int k = j; k >= 1; k--)
          for (int l = a[j]; l <= 2500; l++)
            if (d[k - 1][l - a[j]]) {
              d[k][l] += d[k - 1][l - a[j]];
            }
      }
    for (int j = len - a[i] + 1; j <= len; j++)
      for (int k = 1; k < n; k++)
        ans += k * d[k][j] * fact[k] * fact[n - 1 - k];
  }
  printf("%lf\n", ans / fact[n]);
  return 0;
}
