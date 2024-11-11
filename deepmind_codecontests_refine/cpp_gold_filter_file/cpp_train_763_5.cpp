#include <bits/stdc++.h>
long long f[1000001];
int main() {
  long long sum = 0, two = 2, three = 3, one = 1;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    f[x - 1]++;
    f[y - 1]++;
  }
  long long uu = 0;
  for (int i = 0; i < n; i++) {
    long long tmp = 0, nn = n - 1;
    if (f[i] > 1) tmp += (f[i] - one) * f[i] / two;
    if (nn - f[i] > 1) tmp += (nn - f[i] - one) * (nn - f[i]) / two;
    uu += f[i] * (nn - f[i]);
    sum += tmp;
  }
  uu /= two;
  sum -= uu;
  sum /= three;
  printf("%I64d\n", sum);
  return 0;
}
