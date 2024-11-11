#include <bits/stdc++.h>
using namespace std;
long long a[(int)(1.1e3)][(int)(1.1e3)], pre[(int)(1.1e3)];
int main() {
  int n, m, k;
  for (int i = 1; i <= 1000; i++) a[i][1] = (1 + i) * i / 2;
  pre[0] = 0;
  for (int i = 2; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++)
      pre[j] = (pre[j - 1] + a[j][i - 1]) % (int)(1e9 + 7);
    for (int j = 1; j <= 1000; j++)
      a[j][i] = (a[j - 1][i] + pre[j]) % (int)(1e9 + 7);
  }
  scanf("%d%d%d", &n, &m, &k);
  if (n - 2 * k < 1 || m - 2 * k < 1)
    puts("0");
  else
    printf("%lld\n", a[n - 2 * k][k] * a[m - 2 * k][k] % (int)(1e9 + 7));
  return 0;
}
