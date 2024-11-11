#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int main() {
  long long n, i, j, m, ans, t = 0;
  ans = 0;
  scanf("%lld", &n);
  m = int(sqrt(n));
  for (i = 1; i <= m; i++) {
    ans = ans - n / i * 2;
  }
  ans = ans + m * m;
  for (i = 1; i <= n % 9; i++) a[i]++;
  for (i = 0; i <= 8; i++) a[i] = a[i] + n / 9;
  for (i = 0; i <= 8; i++)
    for (j = 0; j <= 8; j++) ans = ans + a[i] * a[j] * a[i * j % 9];
  printf("%lld\n", ans);
  return 0;
}
